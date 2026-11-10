;
;PROGRAM: Blink User LED
;

include '..\..\rx.inc'
include '..\..\srecord.inc'
include '..\..\include\rx72n.inc'


ExtBase    = 0FFFF_FF80h       ;Exception Vector Table Base
IntBase    = ExtBase - (256*4) ;Interrupt Vector Table Base

RAM_START        = 0h
RAM_END          = 0007_FFFFh
EX_RAM_START     = 0080_0000h
EX_RAM_END       = 0087_FFFFh
ROM_START        = 0FFC0_0000h
ROM_END          = 0FFFF_FFFFh
DATA_FLASH_START = 0010_0000h
DATA_FLASH_END   = 0010_8000h

INT_STACK_BOTTOM  = RAM_START
INT_STACK_TOP     = RAM_START + 2*2048 ;4kb of interrupt stack
USER_STACK_BOTTOM = INT_STACK_TOP
USER_STACK_TOP    = RAM_END - 2  ;(aligned)

;
;POWER RESET
;

org ROM_START

powerON_reset:
setup_clock:
        mov     R1, SYSTEM.PRCR
        mov     word [R1], 0A503h  ;enable clock register writes

        mov     R2, SYSTEM.MOFCR
        mov     byte [R2], 20h     ;set main clock drive ability

;       mov     R1, SYSTEM.MOSCWTCR       ;oscillator wait counter
;       mov     byte [R1], 09h

        mov     R2, SYSTEM.MOSCCR
        mov     byte [R2], 0       ;start main oscillator
        cmp     R2, ubyte [R2]     ;read-back barrier

        mov     R1, SYSTEM.OSCOVFSR

main_oscillator_stable:
        mov     R2, byte [R1]
        btst    R2, 0
        bz      main_oscillator_stable

;       mov     R1, PLLCR
;       mov     word [R1], 1D00h   ;Set Frequency multiplication factor

        mov     R2, SYSTEM.PLLCR2
        mov     byte [R2], 0       ;Start PLL
        cmp     R2, ubyte [R2]

PLL_stable:
        mov     R2, byte [R1]
        btst    R2, 2
        bz      PLL_stable

        mov     R1, SYSTEM.SCKCR
        mov     [R1], 33C3_3333h   ;f/8, bclk/sdclk disabled

        mov     R2, SYSTEM.SCKCR3
        mov     word [R2], 0400h   ;clk src select PLL

        mov     R4, 30h

delay_3u:
        sub     R4, 1
        bnz     delay_3u

        mov     [R1], 21C2_1222h   ;120 MHz iclk
        cmp     R1, [R1]

        mov     R2, SYSTEM.PRCR
        mov     word [R2], 0A500h

init_stack:
        mvtc    ISP, INT_STACK_TOP
        mvtc    USP, USER_STACK_TOP


enRun_CMT0:
        mov     R1, SYSTEM.PRCR
        mov     word [R1], 0A502h

        mov     R2, SYSTEM.MSTPCRA
        mov     R3, [R2]
        bclr    R3, 15
        mov     [R2], R3
        mov     word [R1], 0A500h

enInterrupt_CMT0:
        mov     R1, ICU.IPR004
        mov     byte [R1], 3
        mov     R1, ICU.IER03
        bset    [R1], 4


conf_CMT0:
        mov     R1, CMT0.CMCR
        mov     word [R1], 0043h ;en interrupt, PCLKB/512 = 60MHz/512 = 8.53us
        mov     R1, CMT0.CMCOR
        mov     word [R1], 58617 ;0.5s/8.53us (roughly)


        mov     R1, CMT.CMSTR0
        mov     word [R1], 1 ;start counter

init_led:
        mov     R1, PORT4.PDR
        bset    [R1], 0

en_interrupt:
        mvtc    INTB, IntBase
        mvfc    R2, PSW
        mov     R1, main
        or      R2, 00110000h
        pushm   R1, R2

fin_setup:
        rte

;
;Program Start
;
main:
        nop
        bra main


;
;Interrupt Service Routines
;

CMT0_isr:
        push    R2
        mov     R2, PORT4.PODR
        bnot    byte [R2], 0

        mov     R1, ICU.IR028
        mov     byte [R1], 0
        cmp     R1, ubyte [R1]

        pop     R2

dummy_isr:
        rte

;
;Vector Tables
;
org IntBase
    repeat 28
       dd   dummy_isr
    end repeat

    dd   CMT0_isr

    repeat (255-29)
       dd dummy_isr
    end repeat

org ExtBase + 50h
    dd   dummy_isr;Privileged instruction exception
    dd   dummy_isr;Access exception

org ExtBase + 5Ch
    dd   dummy_isr;Undefined instruction exception
    dd   dummy_isr;Address exception
    dd   dummy_isr;Single-precision floating-point exception

org ExtBase + 78h
    dd   dummy_isr;Non-maskable interrupt

org 0xFFFFFFFC
    dd   powerON_reset ;reset vector