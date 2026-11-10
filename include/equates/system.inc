SYSTEM:

.MDMONR   = 0008_0000h ;Mode Monitor Register
.SYSCR0   = 0008_0006h ;System Control Register 0
.SYSCR1   = 0008_0008h ;System Control Register 1
.SBYCR    = 0008_000Ch ;Standby Control Register
.MSTPCRA  = 0008_0010h ;Module Stop Control Register A
.MSTPCRB  = 0008_0014h ;Module Stop Control Register B
.MSTPCRC  = 0008_0018h ;Module Stop Control Register C
.MSTPCRD  = 0008_001Ch ;Module Stop Control Register D
.SCKCR    = 0008_0020h ;System Clock Control Register
.SCKCR2   = 0008_0024h ;System Clock Control Register 2
.SCKCR3   = 0008_0026h ;System Clock Control Register 3
.PLLCR    = 0008_0028h ;PLL Control Register
.PLLCR2   = 0008_002Ah ;PLL Control Register 2
.BCKCR    = 0008_0030h ;External Bus Clock Control Register
.MOSCCR   = 0008_0032h ;Main Clock Oscillator Control Register
.SOSCCR   = 0008_0033h ;Sub-Clock Oscillator Control Register
.LOCOCR   = 0008_0034h ;Low-Speed On-Chip Oscillator Control Register
.ILOCOCR  = 0008_0035h ;IWDT-Dedicated On-Chip Oscillator Control Register
.HOCOCR   = 0008_0036h ;High-Speed On-Chip Oscillator Control Register
.HOCOCR2  = 0008_0037h ;High-Speed On-Chip Oscillator Control Register 2
.OSCOVFSR = 0008_003Ch ;Oscillation Stabilization Flag Register
.CKOCR    = 0008_003Eh ;CLKOUT Output Control Register
.OSTDCR   = 0008_0040h ;Oscillation Stop Detection Control Register
.OSTDSR   = 0008_0041h ;Oscillation Stop Detection Status Register
.PACKCR   = 0008_0044h ;Specific-Use Clock Control Register
.PPLLCR   = 0008_0048h ;PPLL Control Register
.PPLLCR2  = 0008_004Ah ;PPLL Control Register 2
.PPLLCR3  = 0008_004Bh ;PPLL Control Register 3
.OPCCR    = 0008_00A0h ;Operating Power Control Register
.RSTCKCR  = 0008_00A1h ;Sleep Mode Return Clock Source Switching Register
.MOSCWTCR = 0008_00A2h ;Main Clock Oscillator Wait Control Register
.SOSCWTCR = 0008_00A3h ;Sub-Clock Oscillator Wait Control Register
.RSTSR2   = 0008_00C0h ;Reset Status Register 2
.SWRR     = 0008_00C2h ;Software Reset Register
.LVD1CR1  = 0008_00E0h ; Voltage Monitoring 1 Circuit Control Register 1
.LVD1SR   = 0008_00E1h ; Voltage Monitoring 1 Circuit Status Register
.LVD2CR1  = 0008_00E2h ; Voltage Monitoring 2 Circuit Control Register 1
.LVD2SR   = 0008_00E3h ; Voltage Monitoring 2 Circuit Status Register
.PRCR     = 0008_03FEh ; Protect Register
.MEMWAIT  = 0008_101Ch ; Memory Wait Cycle Setting Register
.DPSBYCR  = 0008_C280h ; Deep Standby Control Register
.DPSIER0  = 0008_C282h ; Deep Standby Interrupt Enable Register 0
.DPSIER1  = 0008_C283h ; Deep Standby Interrupt Enable Register 1
.DPSIER2  = 0008_C284h ; Deep Standby Interrupt Enable Register 2
.DPSIER3  = 0008_C285h ; Deep Standby Interrupt Enable Register 3
.DPSIFR0  = 0008_C286h ; Deep Standby Interrupt Flag Register 0
.DPSIFR1  = 0008_C287h ; Deep Standby Interrupt Flag Register 1
.DPSIFR2  = 0008_C288h ; Deep Standby Interrupt Flag Register 2
.DPSIFR3  = 0008_C289h ; Deep Standby Interrupt Flag Register 3
.DPSIEGR0 = 0008_C28Ah ; Deep Standby Interrupt Edge Register 0
.DPSIEGR1 = 0008_C28Bh ; Deep Standby Interrupt Edge Register 1
.DPSIEGR2 = 0008_C28Ch ; Deep Standby Interrupt Edge Register 2
.DPSIEGR3 = 0008_C28Dh ; Deep Standby Interrupt Edge Register 3
.RSTSR0   = 0008_C290h ; Reset Status Register 0
.RSTSR1   = 0008_C291h ; Reset Status Register 1
.MOFCR    = 0008_C293h ; Main Clock Oscillator Forced Oscillation Control Register
.HOCOPCR  = 0008_C294h ; High-Speed On-Chip Oscillator Power Supply Control Register
.LVCMPCR  = 0008_C297h ; Voltage Monitoring Circuit Control Register
.LVDLVLR  = 0008_C298h ; Voltage Detection Level Select Register
.LVD1CR0  = 0008_C29Ah ; Voltage Monitoring 1 Circuit Control Register 0
.LVD2CR0  = 0008_C29Bh ; Voltage Monitoring 2 Circuit Control Register 0

;0008_C2A0h to 0008_C2BFh
;DPSBKR0 to DPSBKR31
;Deep Standby Backup Register 0 to 31
repeat 32, i:0
   .DPSBKR#i = 0008_C2A0h + i
end repeat