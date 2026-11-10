;
;I/O DEFINES FOR RX72N PROCESSOR
;

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

;0008 C2A0h to 0008 C2BFh
;DPSBKR0 to DPSBKR31
;Deep Standby Backup Register 0 to 31
repeat 32, i:0
   .DPSBKR#i = 0008_C2A0h + i
end repeat

FLASH:

.ROMCE    = 0008_1000h ; ROM Cache Enable Register
.ROMCIV   = 0008_1004h ; ROM Cache Invalidate Register
.NCRG0    = 0008_1040h ; Non-Cacheable Area 0 Address Register
.NCRC0    = 0008_1044h ; Non-Cacheable Area 0 Setting Register
.NCRG1    = 0008_1048h ; Non-Cacheable Area 1 Address Register
.NCRC1    = 0008_104Ch ; Non-Cacheable Area 1 Setting Register
.FWEPROR  = 0008 C296h ; Flash P/E Protect Register
.EEPFCLK  = 007F_C040h ; Data Flash Memory Access Frequency Setting Register
.FASTAT   = 007F_E010h ; Flash Access Status Register
.FAEINT   = 007F_E014h ; Flash Access Error Interrupt Enable Register
.FRDYIE   = 007F_E018h ; Flash Ready Interrupt Enable Register
.FSADDR   = 007F_E030h ; FACI Command Start Address Register
.FEADDR   = 007F_E034h ; FACI Command End Address Register
.FSTATR   = 007F_E080h ; Flash Status Register
.FENTRYR  = 007F_E084h ; Flash P/E Mode Entry Register
.FSUINITR = 007F_E08Ch ; Flash Sequencer Set-Up Initialization Register
.FCMDR    = 007F_E0A0h ; FACI Command Register
.FBCCNT   = 007F_E0D0h ; Data Flash Blank Check Control Register
.FBCSTAT  = 007F_E0D4h ; Data Flash Blank Check Status Register
.FPSADDR  = 007F_E0D8h ; Data Flash Programming Start Address Register
.FAWMON   = 007F_E0DCh ; Flash Access Window Monitor Register
.FCPSR    = 007F_E0E0h ; Flash Sequencer Processing Switching Register
.FPCKAR   = 007F_E0E4h ; Flash Sequencer Processing Clock Frequency Notification Register
.FSUACR   = 007F_E0E8h ; Start-Up Area Control Register

;FLASHCONST
.UIDR0 = FE7F_7D90h ; Unique ID Register 0
.UIDR1 = FE7F_7D94h ; Unique ID Register 1
.UIDR2 = FE7F_7D98h ; Unique ID Register 2
.UIDR3 = FE7F_7D9Ch ; Unique ID Register 3

RAM:

.RAMMODE   = 0008_1200h ; RAM Operating Mode Control Register
.RAMSTS    = 0008_1201h ; RAM Error Status Register
.RAMPRCR   = 0008_1204h ; RAM Protection Register
.RAMECAD   = 0008_1208h ; RAM Error Address Capture Register
.EXRAMMODE = 0008_1240h ; Expansion RAM Operating Mode Control Register
.EXRAMSTS  = 0008_1241h ; Expansion RAM Error Status Register
.EXRAMPRCR = 0008_1244h ; Expansion RAM Protection Register
.EXRAMECAD = 0008_1248h ; Expansion RAM Error Address Capture Register


ECCRAM:

.ECCRAMMODE   = 0008_12C0h ; ECCRAM Operating Mode Control Register
.ECCRAM2STS   = 0008_12C1h ; ECCRAM 2-Bit Error Status Register
.ECCRAM1STSEN = 0008_12C2h ; ECCRAM 1-Bit Error Information Update Enable Register
.ECCRAM1STS   = 0008_12C3h ; ECCRAM 1-Bit Error Status Register
.ECCRAMPRCR   = 0008_12C4h ; ECCRAM Protection Register
.ECCRAM2ECAD  = 0008_12C8h ; ECCRAM 2-Bit Error Address Capture Register
.ECCRAM1ECAD  = 0008_12CCh ; ECCRAM 1-Bit Error Address Capture Register
.ECCRAMPRCR2  = 0008_12D0h ; ECCRAM Protection Register 2
.ECCRAMETST   = 0008_12D4h ; ECCRAM Test Control Register

BSC:

.BERCLR  = 0008_1300h; Bus Error Status Clear Register
.BEREN   = 0008_1304h; Bus Error Monitoring Enable Register
.BERSR1  = 0008_1308h; Bus Error Status Register 1
.BERSR2  = 0008_130Ah; Bus Error Status Register 2
.BUSPRI  = 0008_1310h; Bus Priority Control Register
.CS0MOD  = 0008_3002h ; CS0 Mode Register
.CS0WCR1 = 0008_3004h ; CS0 Wait Control Register 1
.CS0WCR2 = 0008_3008h ; CS0 Wait Control Register 2
.CS1MOD  = 0008_3012h ; CS1 Mode Register
.CS1WCR1 = 0008_3014h ; CS1 Wait Control Register 1
.CS1WCR2 = 0008_3018h ; CS1 Wait Control Register 2
.CS2MOD  = 0008_3022h ; CS2 Mode Register
.CS2WCR1 = 0008_3024h ; CS2 Wait Control Register 1
.CS2WCR2 = 0008_3028h ; CS2 Wait Control Register 2
.CS3MOD  = 0008_3032h ; CS3 Mode Register
.CS3WCR1 = 0008_3034h ; CS3 Wait Control Register 1
.CS3WCR2 = 0008_3038h ; CS3 Wait Control Register 2
.CS4MOD  = 0008_3042h ; CS4 Mode Register
.CS4WCR1 = 0008_3044h ; CS4 Wait Control Register 1
.CS4WCR2 = 0008_3048h ; CS4 Wait Control Register 2
.CS5MOD  = 0008_3052h ; CS5 Mode Register
.CS5WCR1 = 0008_3054h ; CS5 Wait Control Register 1
.CS5WCR2 = 0008_3058h ; CS5 Wait Control Register 2
.CS6MOD  = 0008_3062h ; CS6 Mode Register
.CS6WCR1 = 0008_3064h ; CS6 Wait Control Register 1
.CS6WCR2 = 0008_3068h ; CS6 Wait Control Register 2
.CS7MOD  = 0008_3072h ; CS7 Mode Register
.CS7WCR1 = 0008_3074h ; CS7 Wait Control Register 1
.CS7WCR2 = 0008_3078h ; CS7 Wait Control Register 2
.CS0CR   = 0008_3802h ; CS0 Control Register
.CS0REC  = 0008_380Ah ; CS0 Recovery Cycle Register
.CS1CR   = 0008_3812h ; CS1 Control Register
.CS1REC  = 0008_381Ah ; CS1 Recovery Cycle Register
.CS2CR   = 0008_3822h ; CS2 Control Register
.CS2REC  = 0008_382Ah ; CS2 Recovery Cycle Register
.CS3CR   = 0008_3832h ; CS3 Control Register
.CS3REC  = 0008_383Ah ; CS3 Recovery Cycle Register
.CS4CR   = 0008_3842h ; CS4 Control Register
.CS4REC  = 0008_384Ah ; CS4 Recovery Cycle Register
.CS5CR   = 0008_3852h ; CS5 Control Register
.CS5REC  = 0008_385Ah ; CS5 Recovery Cycle Register
.CS6CR   = 0008_3862h ; CS6 Control Register
.CS6REC  = 0008_386Ah ; CS6 Recovery Cycle Register
.CS7CR   = 0008_3872h ; CS7 Control Register
.CS7REC  = 0008_387Ah ; CS7 Recovery Cycle Register
.CSRECEN = 0008_3880h ; CS Recovery Cycle Insertion Enable Register
.SDCCR   = 0008_3C00h ; SDC Control Register
.SDCMOD  = 0008_3C01h ; SDC Mode Register
.SDAMOD  = 0008_3C02h ; SDRAM Access Mode Register
.SDSELF  = 0008_3C10h ; SDRAM Self-Refresh Control Register
.SDRFCR  = 0008_3C14h ; SDRAM Refresh Control Register
.SDRFEN  = 0008_3C16h ; SDRAM Auto-Refresh Control Register
.SDICR   = 0008_3C20h ; SDRAM Initialization Sequence Control Register
.SDIR    = 0008_3C24h ; SDRAM Initialization Register
.SDADR   = 0008_3C40h ; SDRAM Address Register
.SDTR    = 0008_3C44h ; SDRAM Timing Register
.SDMOD   = 0008_3C48h ; SDRAM Mode Register
.SDSR    = 0008_3C50h ; SDRAM Status Register
.EBMAPCR = 000C_5800h ; Extended Bus Master Priority Control Register

DMAC0:

.DMSAR = 0008_2000h ; DMA Source Address Register
.DMDAR = 0008_2004h ; DMA Destination Address Register
.DMCRA = 0008_2008h ; DMA Transfer Count Register
.DMCRB = 0008_200Ch ; DMA Block Transfer Count Register
.DMTMD = 0008_2010h ; DMA Transfer Mode Register
.DMINT = 0008_2013h ; DMA Interrupt Setting Register
.DMAMD = 0008_2014h ; DMA Address Mode Register
.DMOFR = 0008_2018h ; DMA Offset Register
.DMCNT = 0008_201Ch ; DMA Transfer Enable Register
.DMREQ = 0008_201Dh ; DMA Software Start Register
.DMSTS = 0008_201Eh ; DMA Status Register
.DMCSL = 0008_201Fh ; DMA Request Source Flag Control Register

DMAC1:

.DMSAR = 0008_2040h ; DMA Source Address Register
.DMDAR = 0008_2044h ; DMA Destination Address Register
.DMCRA = 0008_2048h ; DMA Transfer Count Register
.DMCRB = 0008_204Ch ; DMA Block Transfer Count Register
.DMTMD = 0008_2050h ; DMA Transfer Mode Register
.DMINT = 0008_2053h ; DMA Interrupt Setting Register
.DMAMD = 0008_2054h ; DMA Address Mode Register
.DMCNT = 0008_205Ch ; DMA Transfer Enable Register
.DMREQ = 0008_205Dh ; DMA Software Start Register
.DMSTS = 0008_205Eh ; DMA Status Register
.DMCSL = 0008_205Fh ; DMA Request Source Flag Control Register


DMAC2:

.DMSAR = 0008_2080h ; DMA Source Address Register
.DMDAR = 0008_2084h ; DMA Destination Address Register
.DMCRA = 0008_2088h ; DMA Transfer Count Register
.DMCRB = 0008_208Ch ; DMA Block Transfer Count Register
.DMTMD = 0008_2090h ; DMA Transfer Mode Register
.DMINT = 0008_2093h ; DMA Interrupt Setting Register
.DMAMD = 0008_2094h ; DMA Address Mode Register
.DMCNT = 0008_209Ch ; DMA Transfer Enable Register
.DMREQ = 0008_209Dh ; DMA Software Start Register
.DMSTS = 0008_209Eh ; DMA Status Register
.DMCSL = 0008_209Fh ; DMA Request Source Flag Control Register


DMAC3:

.DMSAR = 0008_20C0h ; DMA Source Address Register
.DMDAR = 0008_20C4h ; DMA Destination Address Register
.DMCRA = 0008_20C8h ; DMA Transfer Count Register
.DMCRB = 0008_20CCh ; DMA Block Transfer Count Register
.DMTMD = 0008_20D0h ; DMA Transfer Mode Register
.DMINT = 0008_20D3h ; DMA Interrupt Setting Register
.DMAMD = 0008_20D4h ; DMA Address Mode Register
.DMCNT = 0008_20DCh ; DMA Transfer Enable Register
.DMREQ = 0008_20DDh ; DMA Software Start Register
.DMSTS = 0008_20DEh ; DMA Status Register
.DMCSL = 0008_20DFh ; DMA Request Source Flag Control Register


DMAC4:

.DMSAR = 008_2100h ; DMA Source Address Register
.DMDAR = 0008_2104h ; DMA Destination Address Register
.DMCRA = 0008_2108h ; DMA Transfer Count Register
.DMCRB = 0008_210Ch ; DMA Block Transfer Count Register
.DMTMD = 0008_2110h ; DMA Transfer Mode Register
.DMINT = 0008_2113h ; DMA Interrupt Setting Register
.DMAMD = 0008_2114h ; DMA Address Mode Register
.DMCNT = 0008_211Ch ; DMA Transfer Enable Register
.DMREQ = 0008_211Dh ; DMA Software Start Register
.DMSTS = 0008_211Eh ; DMA Status Register
.DMCSL = 0008_211Fh ; DMA Request Source Flag Control Register

DMAC5:

.DMSAR = 0008_2140h ; DMA Source Address Register
.DMDAR = 0008_2144h ; DMA Destination Address Register
.DMCRA = 0008_2148h ; DMA Transfer Count Register
.DMCRB = 0008_214Ch ; DMA Block Transfer Count Register
.DMTMD = 0008_2150h ; DMA Transfer Mode Register
.DMINT = 0008_2153h ; DMA Interrupt Setting Register
.DMAMD = 0008_2154h ; DMA Address Mode Register
.DMCNT = 0008_215Ch ; DMA Transfer Enable Register
.DMREQ = 0008_215Dh ; DMA Software Start Register
.DMSTS = 0008_215Eh ; DMA Status Register
.DMCSL = 0008_215Fh ; DMA Request Source Flag Control Register

DMAC6:
.DMSAR = 0008_2180h ; DMA Source Address Register
.DMDAR = 0008_2184h ; DMA Destination Address Register
.DMCRA = 0008_2188h ; DMA Transfer Count Register
.DMCRB = 0008_218Ch ; DMA Block Transfer Count Register
.DMTMD = 0008_2190h ; DMA Transfer Mode Register
.DMINT = 0008_2193h ; DMA Interrupt Setting Register
.DMAMD = 0008_2194h ; DMA Address Mode Register
.DMCNT = 0008_219Ch ; DMA Transfer Enable Register
.DMREQ = 0008_219Dh ; DMA Software Start Register
.DMSTS = 0008_219Eh ; DMA Status Register
.DMCSL = 0008_219Fh ; DMA Request Source Flag Control Register

DMAC7:

.DMSAR = 0008_21C0h ; DMA Source Address Register
.DMDAR = 0008_21C4h ; DMA Destination Address Register
.DMCRA = 0008_21C8h ; DMA Transfer Count Register
.DMCRB = 0008_21CCh ; DMA Block Transfer Count Register
.DMTMD = 0008_21D0h ; DMA Transfer Mode Register
.DMINT = 0008_21D3h ; DMA Interrupt Setting Register
.DMAMD = 0008_21D4h ; DMA Address Mode Register
.DMCNT = 0008_21DCh ; DMA Transfer Enable Register
.DMREQ = 0008_21DDh ; DMA Software Start Register
.DMSTS = 0008_21DEh ; DMA Status Register
.DMCSL = 0008_21DFh ; DMA Request Source Flag Control Register


DMAC:

.DMAST = 0008_2200h ; DMAC Module Start Register
.DMIST = 0008_2204h ; DMAC74 Interrupt Status Monitor Register

DTC:

.DTCCR    = 0008_2400h ; DTC Control Register
.DTCVBR   = 0008_2404h ; DTC Vector Base Register
.DTCADMOD = 0008_2408h ; DTC Address Mode Register
.DTCST    = 0008_240Ch ; DTC Module Start Register
.DTCSTS   = 0008_240Eh ; DTC Status Register
.DTCIBR   = 0008_2410h ; DTC Index Table Base Register
.DTCOR    = 0008_2414h ; DTC Operation Register
.DTCSQE   = 0008_2416h ; DTC Sequence Transfer Enable Register
.DTCDISP  = 0008_2418h ; DTC Address Displacement Register

EXDMAC0:

.EDMSAR = 0008_2800h ; EXDMA Source Address Register
.EDMDAR = 0008_2804h ; EXDMA Destination Address Register
.EDMCRA = 0008_2808h ; EXDMA Transfer Count Register
.EDMCRB = 0008_280Ch ; EXDMA Block Transfer Count Register
.EDMTMD = 0008_2810h ; EXDMA Transfer Mode Register
.EDMOMD = 0008_2812h ; EXDMA Output Setting Register
.EDMINT = 0008_2813h ; EXDMA Interrupt Setting Register
.EDMAMD = 0008_2814h ; EXDMA Address Mode Register
.EDMOFR = 0008_2818h ; EXDMA Offset Register
.EDMCNT = 0008_281Ch ; EXDMA Transfer Enable Register
.EDMREQ = 0008_281Dh ; EXDMA Software Start Register
.EDMSTS = 0008_281Eh ; EXDMA Status Register
.EDMRMD = 0008_2820h ; EXDMA External Request Sense Mode Register
.EDMERF = 0008_2821h ; EXDMA External Request Flag Register
.EDMPRF = 0008_2822h ; EXDMA Peripheral Request Flag Register

EXDMAC1:

.EDMSAR = 0008_2840h ; EXDMA Source Address Register
.EDMDAR = 0008_2844h ; EXDMA Destination Address Register
.EDMCRA = 0008_2848h ; EXDMA Transfer Count Register
.EDMCRB = 0008_284Ch ; EXDMA Block Transfer Count Register
.EDMTMD = 0008_2850h ; EXDMA Transfer Mode Register
.EDMOMD = 0008_2852h ; EXDMA Output Setting Register
.EDMINT = 0008_2853h ; EXDMA Interrupt Setting Register
.EDMAMD = 0008_2854h ; EXDMA Address Mode Register
.EDMCNT = 0008_285Ch ; EXDMA Transfer Enable Register
.EDMREQ = 0008_285Dh ; EXDMA Software Start Register
.EDMSTS = 0008_285Eh ; EXDMA Status Register
.EDMRMD = 0008_2860h ; EXDMA External Request Sense Mode Register
.EDMERF = 0008_2861h ; EXDMA External Request Flag Register
.EDMPRF = 0008_2862h ; EXDMA Peripheral Request Flag Register

EXDMAC:

.EDMAST = 0008_2A00h ; EXDMAC Module Start Register
.CLSBR0 = 0008_2BE0h ; Cluster Buffer Register 0
.CLSBR1 = 0008_2BE4h ; Cluster Buffer Register 1
.CLSBR2 = 0008_2BE8h ; Cluster Buffer Register 2
.CLSBR3 = 0008_2BECh ; Cluster Buffer Register 3
.CLSBR4 = 0008_2BF0h ; Cluster Buffer Register 4
.CLSBR5 = 0008_2BF4h ; Cluster Buffer Register 5
.CLSBR6 = 0008_2BF8h ; Cluster Buffer Register 6
.CLSBR7 = 0008_2BFCh ; Cluster Buffer Register 7

MPU:

.RSPAGE0 = 0008_6400h ; Region-0 Start Page Number Register
.REPAGE0 = 0008_6404h ; Region-0 End Page Number Register
.RSPAGE1 = 0008_6408h ; Region-1 Start Page Number Register
.REPAGE1 = 0008_640Ch ; Region-1 End Page Number Register
.RSPAGE2 = 0008_6410h ; Region-2 Start Page Number Register
.REPAGE2 = 0008_6414h ; Region-2 End Page Number Register
.RSPAGE3 = 0008_6418h ; Region-3 Start Page Number Register
.REPAGE3 = 0008_641Ch ; Region-3 End Page Number Register
.RSPAGE4 = 0008_6420h ; Region-4 Start Page Number Register
.REPAGE4 = 0008_6424h ; Region-4 End Page Number Register
.RSPAGE5 = 0008_6428h ; Region-5 Start Page Number Register
.REPAGE5 = 0008_642Ch ; Region-5 End Page Number Register
.RSPAGE6 = 0008_6430h ; Region-6 Start Page Number Register
.REPAGE6 = 0008_6434h ; Region-6 End Page Number Register
.RSPAGE7 = 0008_6438h ; Region-7 Start Page Number Register
.REPAGE7 = 0008_643Ch ; Region-7 End Page Number Register
.MPEN    = 0008_6500h ; Memory-Protection Enable Register
.MPBAC   = 0008_6504h ; Background Access Control Register
.MPECLR  = 0008_6508h ; Memory-Protection Error Status-Clearing Register
.MPESTS  = 0008_650Ch ; Memory-Protection Error Status Register
.MPDEA   = 0008_6514h ; Data Memory-Protection Error Address Register
.MPSA    = 0008_6520h ; Region Search Address Register
.MPOPS   = 0008_6524h ; Region Search Operation Register
.MPOPI   = 0008_6526h ; Region Invalidation Operation Register
.MHITI   = 0008_6528h ; Instruction-Hit Region Register
.MHITD   = 0008_652Ch ; Data-Hit Region Register

ICU:

;0008_7010h to 0008_70FFh
;IR016 to IR255
;Interrupt Request Register 016 to 255

repeat 240, i:16
   if i < 100
      .IR0#i = 0008_7000h + i
   else
      .IR#i  = 0008_7000h + i
   end if
end repeat


;0008_711Ah to 0008_71FFh
;DTC Transfer Request Enable Register 026 to 255
;DTCER026 to DTCER255

repeat 230, i:26
   if i < 100
      .DTCER0#i = 0008_7100h + i
   else
      .DTCER#i  = 0008_7100h + i
   end if
end repeat

;Names in hex. unsure how with repeat

.IER02 = 0008_7202h ; Interrupt Request Enable Register 02
.IER03 = 0008_7203h ; Interrupt Request Enable Register 03
.IER04 = 0008_7204h ; Interrupt Request Enable Register 04
.IER05 = 0008_7205h ; Interrupt Request Enable Register 05
.IER06 = 0008_7206h ; Interrupt Request Enable Register 06
.IER07 = 0008_7207h ; Interrupt Request Enable Register 07
.IER08 = 0008_7208h ; Interrupt Request Enable Register 08
.IER09 = 0008_7209h ; Interrupt Request Enable Register 09
.IER0A = 0008_720Ah ; Interrupt Request Enable Register 0A
.IER0B = 0008_720Bh ; Interrupt Request Enable Register 0B
.IER0C = 0008_720Ch ; Interrupt Request Enable Register 0C
.IER0D = 0008_720Dh ; Interrupt Request Enable Register 0D
.IER0E = 0008_720Eh ; Interrupt Request Enable Register 0E
.IER0F = 0008_720Fh ; Interrupt Request Enable Register 0F
.IER10 = 0008_7210h ; Interrupt Request Enable Register 10
.IER11 = 0008_7211h ; Interrupt Request Enable Register 11
.IER12 = 0008_7212h ; Interrupt Request Enable Register 12
.IER13 = 0008_7213h ; Interrupt Request Enable Register 13
.IER14 = 0008_7214h ; Interrupt Request Enable Register 14
.IER15 = 0008_7215h ; Interrupt Request Enable Register 15
.IER16 = 0008_7216h ; Interrupt Request Enable Register 16
.IER17 = 0008_7217h ; Interrupt Request Enable Register 17
.IER18 = 0008_7218h ; Interrupt Request Enable Register 18
.IER19 = 0008_7219h ; Interrupt Request Enable Register 19
.IER1A = 0008_721Ah ; Interrupt Request Enable Register 1A
.IER1B = 0008_721Bh ; Interrupt Request Enable Register 1B
.IER1C = 0008_721Ch ; Interrupt Request Enable Register 1C
.IER1D = 0008_721Dh ; Interrupt Request Enable Register 1D
.IER1E = 0008_721Eh ; Interrupt Request Enable Register 1E
.IER1F = 0008_721Fh ; Interrupt Request Enable Register 1F

.SWINTR  = 0008_72E0h ; Software Interrupt Generation Register
.SWINT2R = 0008_72E1h ; Software Interrupt 2 Generation Register
.FIR     = 0008_72F0h ; Fast Interrupt Set Register

;0008_7300h tp 8000_73FFh
;Interrupt Source Priority Register 000 to 255
;IPR000 to IPR255

repeat 256, i:0
   if i < 10
      .IPR00#i = 0008_7300h + i
   else if i < 100
      .IPR0#i  = 0008_7300h + i
   else
      .IPR#i   = 0008_7300h + i
   end if
end repeat


.DMRSR0 = 0008_7400h ; DMAC Trigger Select Register 0
.DMRSR1 = 0008_7404h ; DMAC Trigger Select Register 1
.DMRSR2 = 0008_7408h ; DMAC Trigger Select Register 2
.DMRSR3 = 0008_740Ch ; DMAC Trigger Select Register 3
.DMRSR4 = 0008_7410h ; DMAC Trigger Select Register 4
.DMRSR5 = 0008_7414h ; DMAC Trigger Select Register 5
.DMRSR6 = 0008_7418h ; DMAC Trigger Select Register 6
.DMRSR7 = 0008_741Ch ; DMAC Trigger Select Register 7

;0008_7500h to 0008_750Fh
;IRQ Control Register 0 to 16
;IRQCR0 to IRWCR16
repeat 16, i:0
   .IRQCR#i = 0008_7500h + i
end repeat

.IRQFLTE0  = 0008_7520h ; IRQ Pin Digital Filter Enable Register 0
.IRQFLTE1  = 0008_7521h ; IRQ Pin Digital Filter Enable Register 1
.IRQFLTC0  = 0008_7528h ; IRQ Pin Digital Filter Setting Register 0
.IRQFLTC1  = 0008_752Ah ; IRQ Pin Digital Filter Setting Register 1
.NMISR     = 0008_7580h ; Non-Maskable Interrupt Status Register
.NMIER     = 0008_7581h ; Non-Maskable Interrupt Enable Register
.NMICLR    = 0008_7582h ; Non-Maskable Interrupt Status Clear Register
.NMICR     = 0008_7583h ; NMI Pin Interrupt Control Register
.EXNMISR   = 0008_7584h ; Expanded Non-Maskable Interrupt Status Register
.EXNMIER   = 0008_7585h ; Expanded Non-Maskable Interrupt Enable Register
.EXNMICLR  = 0008 7586h ; Expanded Non-Maskable Interrupt Status Clear Register
.NMIFLTE   = 0008_7590h ; NMI Pin Digital Filter Enable Register
.NMIFLTC   = 0008_7594h ; NMI Pin Digital Filter Setting Register
.GRPIE0    = 0008_75B0h ; Group IE0 Interrupt Request Register
.GENIE0    = 0008_75B4h ; Group IE0 Interrupt Request Enable Register
.GCRIE0    = 0008_75B8h ; Group IE0 Interrupt Clear Register
.GRPBE0    = 0008_7600h ; Group BE0 Interrupt Request Register
.GRPBL0    = 0008 7630h ; Group BL0 Interrupt Request Register
.GRPBL1    = 0008 7634h ; Group BL1 Interrupt Request Register
.GRPBL2    = 0008 7638h ; Group BL2 Interrupt Request Register
.GENBE0    = 0008 7640h ; Group BE0 Interrupt Request Enable Register
.GENBL0    = 0008 7670h ; Group BL0 Interrupt Request Enable Register
.GENBL1    = 0008 7674h ; Group BL1 Interrupt Request Enable Register
.GENBL2    = 0008 7678h ; Group BL2 Interrupt Request Enable Register
.GCRBE0    = 0008 7680h ; Group BE0 Interrupt Clear Register
.PIBR0     = 0008 7700h ; Software Configurable Interrupt B Request Register 0
.PIBR1     = 0008 7701h ; Software Configurable Interrupt B Request Register 1
.PIBR2     = 0008 7702h ; Software Configurable Interrupt B Request Register 2
.PIBR3     = 0008 7703h ; Software Configurable Interrupt B Request Register 3
.PIBR4     = 0008 7704h ; Software Configurable Interrupt B Request Register 4
.PIBR5     = 0008 7705h ; Software Configurable Interrupt B Request Register 5
.PIBR6     = 0008 7706h ; Software Configurable Interrupt B Request Register 6
.PIBR7     = 0008 7707h ; Software Configurable Interrupt B Request Register 7
.PIBR8     = 0008 7708h ; Software Configurable Interrupt B Request Register 8
.PIBR9     = 0008 7709h ; Software Configurable Interrupt B Request Register 9
.PIBRA     = 0008_770Ah ; Software Configurable Interrupt B Request Register A
.PIBRB     = 0008 770Bh ; Software Configurable Interrupt B Request Register B
.SLIBXR128 = 0008_7780h ; Software Configurable Interrupt B Source Select Register X128
.SLIBXR129 = 0008_7781h ; Software Configurable Interrupt B Source Select Register X129
.SLIBXR130 = 0008_7782h ; Software Configurable Interrupt B Source Select Register X130
.SLIBXR131 = 0008_7783h ; Software Configurable Interrupt B Source Select Register X131
.SLIBXR132 = 0008_7784h ; Software Configurable Interrupt B Source Select Register X132
.SLIBXR133 = 0008_7785h ; Software Configurable Interrupt B Source Select Register X133
.SLIBXR134 = 0008_7786h ; Software Configurable Interrupt B Source Select Register X134
.SLIBXR135 = 0008_7787h ; Software Configurable Interrupt B Source Select Register X135
.SLIBXR136 = 0008_7788h ; Software Configurable Interrupt B Source Select Register X136
.SLIBXR137 = 0008_7789h ; Software Configurable Interrupt B Source Select Register X137
.SLIBXR138 = 0008_778Ah ; Software Configurable Interrupt B Source Select Register X138
.SLIBXR139 = 0008_778Bh ; Software Configurable Interrupt B Source Select Register X139
.SLIBXR140 = 0008_778Ch ; Software Configurable Interrupt B Source Select Register X140
.SLIBXR141 = 0008_778Dh ; Software Configurable Interrupt B Source Select Register X141
.SLIBXR142 = 0008_778Eh ; Software Configurable Interrupt B Source Select Register X142
.SLIBXR143 = 0008_778Fh ; Software Configurable Interrupt B Source Select Register X143
.SLIBR144  = 0008_7790h ; Software Configurable Interrupt B Source Select Register 144
.SLIBR145  = 0008_7791h ; Software Configurable Interrupt B Source Select Register 145
.SLIBR146  = 0008_7792h ; Software Configurable Interrupt B Source Select Register 146
.SLIBR147  = 0008_7793h ; Software Configurable Interrupt B Source Select Register 147
.SLIBR148  = 0008_7794h ; Software Configurable Interrupt B Source Select Register 148
.SLIBR149  = 0008_7795h ; Software Configurable Interrupt B Source Select Register 149
.SLIBR150  = 0008_7796h ; Software Configurable Interrupt B Source Select Register 150
.SLIBR151  = 0008_7797h ; Software Configurable Interrupt B Source Select Register 151
.SLIBR152  = 0008_7798h ; Software Configurable Interrupt B Source Select Register 152
.SLIBR153  = 0008_7799h ; Software Configurable Interrupt B Source Select Register 153
.SLIBR154  = 0008_779Ah ; Software Configurable Interrupt B Source Select Register 154
.SLIBR155  = 0008_779Bh ; Software Configurable Interrupt B Source Select Register 155
.SLIBR156  = 0008_779Ch ; Software Configurable Interrupt B Source Select Register 156
.SLIBR157  = 0008_779Dh ; Software Configurable Interrupt B Source Select Register 157
.SLIBR158  = 0008_779Eh ; Software Configurable Interrupt B Source Select Register 158
.SLIBR159  = 0008_779Fh ; Software Configurable Interrupt B Source Select Register 159
.SLIBR160  = 0008_77A0h ; Software Configurable Interrupt B Source Select Register 160
.SLIBR161  = 0008_77A1h ; Software Configurable Interrupt B Source Select Register 161
.SLIBR162  = 0008_77A2h ; Software Configurable Interrupt B Source Select Register 162
.SLIBR163  = 0008_77A3h ; Software Configurable Interrupt B Source Select Register 163
.SLIBR164  = 0008_77A4h ; Software Configurable Interrupt B Source Select Register 164
.SLIBR165  = 0008_77A5h ; Software Configurable Interrupt B Source Select Register 165
.SLIBR166  = 0008_77A6h ; Software Configurable Interrupt B Source Select Register 166
.SLIBR167  = 0008_77A7h ; Software Configurable Interrupt B Source Select Register 167
.SLIBR168  = 0008_77A8h ; Software Configurable Interrupt B Source Select Register 168
.SLIBR169  = 0008_77A9h ; Software Configurable Interrupt B Source Select Register 169
.SLIBR170  = 0008_77AAh ; Software Configurable Interrupt B Source Select Register 170
.SLIBR171  = 0008_77ABh ; Software Configurable Interrupt B Source Select Register 171
.SLIBR172  = 0008_77ACh ; Software Configurable Interrupt B Source Select Register 172
.SLIBR173  = 0008_77ADh ; Software Configurable Interrupt B Source Select Register 173
.SLIBR174  = 0008_77AEh ; Software Configurable Interrupt B Source Select Register 174
.SLIBR175  = 0008_77AFh ; Software Configurable Interrupt B Source Select Register 175
.SLIBR176  = 0008_77B0h ; Software Configurable Interrupt B Source Select Register 176
.SLIBR177  = 0008_77B1h ; Software Configurable Interrupt B Source Select Register 177
.SLIBR178  = 0008_77B2h ; Software Configurable Interrupt B Source Select Register 178
.SLIBR179  = 0008_77B3h ; Software Configurable Interrupt B Source Select Register 179
.SLIBR180  = 0008_77B4h ; Software Configurable Interrupt B Source Select Register 180
.SLIBR181  = 0008_77B5h ; Software Configurable Interrupt B Source Select Register 181
.SLIBR182  = 0008_77B6h ; Software Configurable Interrupt B Source Select Register 182
.SLIBR183  = 0008_77B7h ; Software Configurable Interrupt B Source Select Register 183
.SLIBR184  = 0008_77B8h ; Software Configurable Interrupt B Source Select Register 184
.SLIBR185  = 0008_77B9h ; Software Configurable Interrupt B Source Select Register 185
.SLIBR186  = 0008_77BAh ; Software Configurable Interrupt B Source Select Register 186
.SLIBR187  = 0008_77BBh ; Software Configurable Interrupt B Source Select Register 187
.SLIBR188  = 0008_77BCh ; Software Configurable Interrupt B Source Select Register 188
.SLIBR189  = 0008_77BDh ; Software Configurable Interrupt B Source Select Register 189
.SLIBR190  = 0008_77BEh ; Software Configurable Interrupt B Source Select Register 190
.SLIBR191  = 0008_77BFh ; Software Configurable Interrupt B Source Select Register 191
.SLIBR192  = 0008_77C0h ; Software Configurable Interrupt B Source Select Register 192
.SLIBR193  = 0008_77C1h ; Software Configurable Interrupt B Source Select Register 193
.SLIBR194  = 0008_77C2h ; Software Configurable Interrupt B Source Select Register 194
.SLIBR195  = 0008_77C3h ; Software Configurable Interrupt B Source Select Register 195
.SLIBR196  = 0008_77C4h ; Software Configurable Interrupt B Source Select Register 196
.SLIBR197  = 0008_77C5h ; Software Configurable Interrupt B Source Select Register 197
.SLIBR198  = 0008_77C6h ; Software Configurable Interrupt B Source Select Register 198
.SLIBR199  = 0008_77C7h ; Software Configurable Interrupt B Source Select Register 199
.SLIBR200  = 0008_77C8h ; Software Configurable Interrupt B Source Select Register 200
.SLIBR201  = 0008_77C9h ; Software Configurable Interrupt B Source Select Register 201
.SLIBR202  = 0008_77CAh ; Software Configurable Interrupt B Source Select Register 202
.SLIBR203  = 0008_77CBh ; Software Configurable Interrupt B Source Select Register 203
.SLIBR204  = 0008_77CCh ; Software Configurable Interrupt B Source Select Register 204
.SLIBR205  = 0008_77CDh ; Software Configurable Interrupt B Source Select Register 205
.SLIBR206  = 0008_77CEh ; Software Configurable Interrupt B Source Select Register 206
.SLIBR207  = 0008_77CFh ; Software Configurable Interrupt B Source Select Register 207
.GRPAL0    = 00087830h ; Group AL0 Interrupt Request Register
.GRPAL1    = 00087834h ; Group AL1 Interrupt Request Register
.GENAL0    = 00087870h ; Group AL0 Interrupt Request Enable Register
.GENAL1    = 00087874h ; Group AL1 Interrupt Request Enable Register
.PIAR0     = 00087900h ; Software Configurable Interrupt A Request Register 0
.PIAR1     = 00087901h ; Software Configurable Interrupt A Request Register 1
.PIAR2     = 00087902h ; Software Configurable Interrupt A Request Register 2
.PIAR3     = 00087903h ; Software Configurable Interrupt A Request Register 3
.PIAR4     = 00087904h ; Software Configurable Interrupt A Request Register 4
.PIAR5     = 00087905h ; Software Configurable Interrupt A Request Register 5
.PIAR6     = 00087906h ; Software Configurable Interrupt A Request Register 6
.PIAR7     = 00087907h ; Software Configurable Interrupt A Request Register 7
.PIAR8     = 00087908h ; Software Configurable Interrupt A Request Register 8
.PIAR9     = 00087909h ; Software Configurable Interrupt A Request Register 9
.PIARA     = 0008790Ah ; Software Configurable Interrupt A Request Register A
.PIARC     = 0008790Ch ; Software Configurable Interrupt A Request Register C
.SLIAR208  = 0008_79D0h ; Software Configurable Interrupt A Source Select Register 208
.SLIAR209  = 0008_79D1h ; Software Configurable Interrupt A Source Select Register 209
.SLIAR210  = 0008_79D2h ; Software Configurable Interrupt A Source Select Register 210
.SLIAR211  = 0008_79D3h ; Software Configurable Interrupt A Source Select Register 211
.SLIAR212  = 0008_79D4h ; Software Configurable Interrupt A Source Select Register 212
.SLIAR213  = 0008_79D5h ; Software Configurable Interrupt A Source Select Register 213
.SLIAR214  = 0008_79D6h ; Software Configurable Interrupt A Source Select Register 214
.SLIAR215  = 0008_79D7h ; Software Configurable Interrupt A Source Select Register 215
.SLIAR216  = 0008_79D8h ; Software Configurable Interrupt A Source Select Register 216
.SLIAR217  = 0008_79D9h ; Software Configurable Interrupt A Source Select Register 217
.SLIAR218  = 0008_79DAh ; Software Configurable Interrupt A Source Select Register 218
.SLIAR219  = 0008_79DBh ; Software Configurable Interrupt A Source Select Register 219
.SLIAR220  = 0008_79DCh ; Software Configurable Interrupt A Source Select Register 220
.SLIAR221  = 0008_79DDh ; Software Configurable Interrupt A Source Select Register 221
.SLIAR222  = 0008_79DEh ; Software Configurable Interrupt A Source Select Register 222
.SLIAR223  = 0008_79DFh ; Software Configurable Interrupt A Source Select Register 223
.SLIAR224  = 0008_79E0h ; Software Configurable Interrupt A Source Select Register 224
.SLIAR225  = 0008_79E1h ; Software Configurable Interrupt A Source Select Register 225
.SLIAR226  = 0008_79E2h ; Software Configurable Interrupt A Source Select Register 226
.SLIAR227  = 0008_79E3h ; Software Configurable Interrupt A Source Select Register 227
.SLIAR228  = 0008_79E4h ; Software Configurable Interrupt A Source Select Register 228
.SLIAR229  = 0008_79E5h ; Software Configurable Interrupt A Source Select Register 229
.SLIAR230  = 0008_79E6h ; Software Configurable Interrupt A Source Select Register 230
.SLIAR231  = 0008_79E7h ; Software Configurable Interrupt A Source Select Register 231
.SLIAR232  = 0008_79E8h ; Software Configurable Interrupt A Source Select Register 232
.SLIAR233  = 0008_79E9h ; Software Configurable Interrupt A Source Select Register 233
.SLIAR234  = 0008_79EAh ; Software Configurable Interrupt A Source Select Register 234
.SLIAR235  = 0008_79EBh ; Software Configurable Interrupt A Source Select Register 235
.SLIAR236  = 0008_79ECh ; Software Configurable Interrupt A Source Select Register 236
.SLIAR237  = 0008_79EDh ; Software Configurable Interrupt A Source Select Register 237
.SLIAR238  = 0008_79EEh ; Software Configurable Interrupt A Source Select Register 238
.SLIAR239  = 0008_79EFh ; Software Configurable Interrupt A Source Select Register 239
.SLIAR240  = 0008_79F0h ; Software Configurable Interrupt A Source Select Register 240
.SLIAR241  = 0008_79F1h ; Software Configurable Interrupt A Source Select Register 241
.SLIAR242  = 0008_79F2h ; Software Configurable Interrupt A Source Select Register 242
.SLIAR243  = 0008_79F3h ; Software Configurable Interrupt A Source Select Register 243
.SLIAR244  = 0008_79F4h ; Software Configurable Interrupt A Source Select Register 244
.SLIAR245  = 0008_79F5h ; Software Configurable Interrupt A Source Select Register 245
.SLIAR246  = 0008_79F6h ; Software Configurable Interrupt A Source Select Register 246
.SLIAR247  = 0008_79F7h ; Software Configurable Interrupt A Source Select Register 247
.SLIAR248  = 0008_79F8h ; Software Configurable Interrupt A Source Select Register 248
.SLIAR249  = 0008_79F9h ; Software Configurable Interrupt A Source Select Register 249
.SLIAR250  = 0008_79FAh ; Software Configurable Interrupt A Source Select Register 250
.SLIAR251  = 0008_79FBh ; Software Configurable Interrupt A Source Select Register 251
.SLIAR252  = 0008_79FCh ; Software Configurable Interrupt A Source Select Register 252
.SLIAR253  = 0008_79FDh ; Software Configurable Interrupt A Source Select Register 253
.SLIAR254  = 0008_79FEh ; Software Configurable Interrupt A Source Select Register 254
.SLIAR255  = 0008_79FFh ; Software Configurable Interrupt A Source Select Register 255
.SLIPRCR   = 0008_7A00h ; Software Configurable Interrupt Source Select Register Write Protect Register
.SELEXDR   = 0008_7A01h ; EXDMAC Trigger Select Register


CMT:
.CMSTR0 = 0008_8000h ; Compare Match Timer Start Register 0
.CMSTR1 = 0008_8010h ; Compare Match Timer Start Register 1

CMT0:

.CMCR  = 0008_8002h ; Compare Match Timer Control Register
.CMCNT = 0008_8004h ; Compare Match Counter
.CMCOR = 0008_8006h ; Compare Match Constant Register

CMT1:

.CMCR  = 0008_8008h ; Compare Match Timer Control Register
.CMCNT = 0008_800Ah ; Compare Match Counter
.CMCOR = 0008_800Ch ; Compare Match Constant Register


CMT2:

.CMCR  = 0008_8012h ; Compare Match Timer Control Register
.CMCNT = 0008_8014h ; Compare Match Counter
.CMCOR = 0008_8016h ; Compare Match Constant Register

CMT3:

.CMCR  = 0008_8018h ; Compare Match Timer Control Register
.CMCNT = 0008_801Ah ; Compare Match Counter
.CMCOR = 0008_801Ch ; Compare Match Constant Register

WDT:

.WDTRR  = 0008_8020h ; WDT Refresh Register
.WDTCR  = 0008_8022h ; WDT Control Register
.WDTSR  = 0008_8024h ; WDT Status Register
.WDTRCR = 0008_8026h ; WDT Reset Control Register

IWDT:

.IWDTRR    = 0008_8030h ; IWDT Refresh Register
.IWDTCR    = 0008_8032h ; IWDT Control Register
.IWDTSR    = 0008_8034h ; IWDT Status Register
.IWDTRCR   = 0008_8036h ; IWDT Reset Control Register
.IWDTCSTPR = 0008_8038h ; IWDT Count Stop Control Register

DA:

.DADR0   = 0008_8040h ; D/A Data Register 0
.DADR1   = 0008_8042h ; D/A Data Register 1
.DACR    = 0008_8044h ; D/A Control Register
.DADPR   = 0008_8045h ; Data Register Format Select Register
.DAADSCR = 0008_8046h ; D/A A/D Synchronous Start Control Register
.DAAMPCR = 0008_8048h ; D/A Output Amplifier Control Register
.DAASWCR = 0008_805Ch ; D/A Output Amplifier Stabilization Wait Control Register

TPUA:

.TSTR = 0008_8100h ; Timer Start Register
.TSYR = 0008_8101h ; Timer Synchronous Register

TPU0:

.NFCR  = 0008_8108h ; Noise Filter Control Register
.TCR   = 0008_8110h ; Timer Control Register
.TMDR  = 0008_8111h ; Timer Mode Register
.TIORH = 0008_8112h ; Timer I/O Control Register H
.TIORL = 0008_8113h ; Timer I/O Control Register L
.TIER  = 0008_8114h ; Timer Interrupt Enable Register
.TSR   = 0008_8115h ; Timer Status Register
.TCNT  = 0008_8116h ; Timer Counter
.TGRA  = 0008_8118h ; Timer General Register A
.TGRB  = 0008_811Ah ; Timer General Register B
.TGRC  = 0008_811Ch ; Timer General Register C
.TGRD  = 0008_811Eh ; Timer General Register D

TPU1:

.NFCR = 0008_8109h ; Noise Filter Control Register
.TCR  = 0008_8120h ; Timer Control Register
.TMDR = 0008_8121h ; Timer Mode Register
.TIOR = 0008_8122h ; Timer I/O Control Register
.TIER = 0008_8124h ; Timer Interrupt Enable Register
.TSR  = 0008_8125h ; Timer Status Register
.TCNT = 0008_8126h ; Timer Counter
.TGRA = 0008_8128h ; Timer General Register A
.TGRB = 0008_812Ah ; Timer General Register B

TPU2:

.NFCR = 0008_810Ah ; Noise Filter Control Register
.TCR  = 0008_8130h ; Timer Control Register
.TMDR = 0008_8131h ; Timer Mode Register
.TIOR = 0008_8132h ; Timer I/O Control Register
.TIER = 0008_8134h ; Timer Interrupt Enable Register
.TSR  = 0008_8135h ; Timer Status Register
.TCNT = 0008_8136h ; Timer Counter
.TGRA = 0008_8138h ; Timer General Register A
.TGRB = 0008_813Ah ; Timer General Register B

TPU3:

.NFCR  = 0008_810Bh ; Noise Filter Control Register
.TCR   = 008_8140h ; Timer Control Register
.TMDR  = 0008_8141h ; Timer Mode Register
.TIORH = 0008_8142h ; Timer I/O Control Register H
.TIORL = 0008_8143h ; Timer I/O Control Register L
.TIER  = 0008_8144h ; Timer Interrupt Enable Register
.TSR   = 0008_8145h ; Timer Status Register
.TCNT  = 0008_8146h ; Timer Counter
.TGRA  = 0008_8148h ; Timer General Register A
.TGRB  = 0008_814Ah ; Timer General Register B
.TGRC  = 0008_814Ch ; Timer General Register C
.TGRD  = 0008_814Eh ; Timer General Register D

TPU4:

.NFCR = 0008_810Ch ; Noise Filter Control Register
.TCR  = 0008_8150h ; Timer Control Register
.TMDR = 0008_8151h ; Timer Mode Register
.TIOR = 0008_8152h ; Timer I/O Control Register
.TIER = 0008_8154h ; Timer Interrupt Enable Register
.TSR  = 0008_8155h ; Timer Status Register
.TCNT = 0008_8156h ; Timer Counter
.TGRA = 0008_8158h ; Timer General Register A
.TGRB = 0008_815Ah ; Timer General Register B

TPU5:

.NFCR = 0008_810Dh ; Noise Filter Control Register
.TCR  = 0008_8160h ; Timer Control Register
.TMDR = 0008_8161h ; Timer Mode Register
.TIOR = 0008_8162h ; Timer I/O Control Register
.TIER = 0008_8164h ; Timer Interrupt Enable Register
.TSR  = 0008_8165h ; Timer Status Register
.TCNT = 0008_8166h ; Timer Counter
.TGRA = 0008_8168h ; Timer General Register A
.TGRB = 0008_816Ah ; Timer General Register B

PPG0:

.PCR   = 0008_81E6h ; PPG Output Control Register
.PMR   = 0008_81E7h ; PPG Output Mode Register
.NDERH = 0008_81E8h ; Next Data Enable Register H
.NDERL = 0008_81E9h ; Next Data Enable Register L
.PODRH = 0008_81EAh ; Output Data Register H
.PODRL = 0008_81EBh ; Output Data Register L
.NDRH  = 0008_81ECh ; Next Data Register H
.NDRL  = 0008_81EDh ; Next Data Register L
.NDRH2 = 0008_81EEh ; Next Data Register H2
.NDRL2 = 0008_81EFh ; Next Data Register L2

PPG1:

.PTRSLR = 0008_81F0h ; PPG Trigger Select Register
.PCR    = 0008_81F6h ; PPG Output Control Register
.PMR    = 0008_81F7h ; PPG Output Mode Register
.NDERH  = 0008_81F8h ; Next Data Enable Register H
.NDERL  = 0008_81F9h ; Next Data Enable Register L
.PODRH  = 0008_81FAh ; Output Data Register H
.PODRL  = 0008_81FBh ; Output Data Register L
.NDRH   = 0008_81FCh ; Next Data Register H
.NDRL   = 0008_81FDh ; Next Data Register L
.NDRH2  = 0008_81FEh ; Next Data Register H2
.NDRL2  = 0008_81FFh ; Next Data Register L2

TMR0:

.TCR   = 0008_8200h ; Timer Control Register
.TCSR  = 0008_8202h ; Timer Control/Status Register
.TCORA = 0008_8204h ; Time Constant Register A
.TCORB = 0008_8206h ; Time Constant Register B
.TCNT  = 0008_8208h ; Timer Counter
.TCCR  = 0008_820Ah ; Timer Counter Control Register
.TCSTR = 0008_820Ch ; Timer Counter Start Register

TMR1:

.TCR   = 0008_8201h ; Timer Control Register
.TCSR  = 0008_8203h ; Timer Control/Status Register
.TCORA = 0008_8205h ; Time Constant Register A
.TCORB = 0008_8207h ; Time Constant Register B
.TCNT  = 0008_8209h ; Timer Counter
.TCCR  = 0008_820Bh ; Timer Counter Control Register
.TCSTR = 0008_820Dh ; Timer Counter Start Register

TMR01:

.TCORA = 0008_8204h ; Time Constant Register A
.TCORB = 0008_8206h ; Time Constant Register B
.TCNT  = 0008_8208h ; Timer Counter
.TCCR  = 0008_820Ah ; Timer Counter Control Register

TMR2:

.TCR   = 0008_8210h ; Timer Control Register
.TCSR  = 0008_8212h ; Timer Control/Status Register
.TCORA = 0008_8214h ; Time Constant Register A
.TCORB = 0008_8216h ; Time Constant Register B
.TCNT  = 0008_8218h ; Timer Counter
.TCCR  = 0008_821Ah ; Timer Counter Control Register
.TCSTR = 0008_821Ch ; Timer Counter Start Register

TMR3:

.TCR   = 0008_8211h ; Timer Control Register
.TCSR  = 0008_8213h ; Timer Control/Status Register
.TCORA = 0008_8215h ; Time Constant Register A
.TCORB = 0008_8217h ; Time Constant Register B
.TCNT  = 0008_8219h ; Timer Counter
.TCCR  = 0008_821Bh ; Timer Counter Control Register
.TCSTR = 0008_821Dh ; Timer Counter Start Register

TMR23:

.TCORA = 0008_8214h ; Time Constant Register A
.TCORB = 0008_8216h ; Time Constant Register B
.TCNT  = 0008_8218h ; Timer Counter
.TCCR  = 0008_821Ah ; Timer Counter Control Register

CRC:

.CRCCR  = 0008_8280h ; CRC Control Register
.CRCDIR = 0008_8284h ; CRC Data Input Register
.CRCDOR = 0008_8288h ; CRC Data Output Register

RIIC0:

.ICCR1 = 0008_8300h ; I2C-bus Control Register 1
.ICCR2 = 0008_8301h ; I2C-bus Control Register 2
.ICMR1 = 0008_8302h ; I2C-bus Mode Register 1
.ICMR2 = 0008_8303h ; I2C-bus Mode Register 2
.ICMR3 = 0008_8304h ; I2C-bus Mode Register 3
.ICFER = 0008_8305h ; I2C-bus Function Enable Register
.ICSER = 0008_8306h ; I2C-bus Status Enable Register
.ICIER = 0008_8307h ; I2C-bus Interrupt Enable Register
.ICSR1 = 0008_8308h ; I2C-bus Status Register 1
.ICSR2 = 0008_8309h ; I2C-bus Status Register 2
.SARL0 = 0008_830Ah ; Slave Address Register L0
.SARU0 = 0008_830Bh ; Slave Address Register U0
.SARL1 = 0008_830Ch ; Slave Address Register L1
.SARU1 = 0008_830Dh ; Slave Address Register U1
.SARL2 = 0008_830Eh ; Slave Address Register L2
.SARU2 = 0008_830Fh ; Slave Address Register U2
.ICBRL = 0008_8310h ; I2C-bus Bit Rate Low-Level Register
.ICBRH = 0008_8311h ; I2C-bus Bit Rate High-Level Register
.ICDRT = 0008_8312h ; I2C-bus Transmit Data Register
.ICDRR = 0008_8313h ; I2C-bus Receive Data Register

RIIC1:

.ICCR1 = 0008_8320h ; I2C-bus Control Register 1
.ICCR2 = 0008_8321h ; I2C-bus Control Register 2
.ICMR1 = 0008_8322h ; I2C-bus Mode Register 1
.ICMR2 = 0008_8323h ; I2C-bus Mode Register 2
.ICMR3 = 0008_8324h ; I2C-bus Mode Register 3
.ICFER = 0008_8325h ; I2C-bus Function Enable Register
.ICSER = 0008_8326h ; I2C-bus Status Enable Register
.ICIER = 0008_8327h ; I2C-bus Interrupt Enable Register
.ICSR1 = 0008_8328h ; I2C-bus Status Register 1
.ICSR2 = 0008_8329h ; I2C-bus Status Register 2
.SARL0 = 0008_832Ah ; Slave Address Register L0
.SARU0 = 0008_832Bh ; Slave Address Register U0
.SARL1 = 0008_832Ch ; Slave Address Register L1
.SARU1 = 0008_832Dh ; Slave Address Register U1
.SARL2 = 0008_832Eh ; Slave Address Register L2
.SARU2 = 0008_832Fh ; Slave Address Register U2
.ICBRL = 0008_8330h ; I2C-bus Bit Rate Low-Level Register
.ICBRH = 0008_8331h ; I2C-bus Bit Rate High-Level Register
.ICDRT = 0008_8332h ; I2C-bus Transmit Data Register
.ICDRR = 0008_8333h ; I2C-bus Receive Data Register

RICC2:

.ICCR1 = 0008_8340h ; I2C-bus Control Register 1
.ICCR2 = 0008_8341h ; I2C-bus Control Register 2
.ICMR1 = 0008_8342h ; I2C-bus Mode Register 1
.ICMR2 = 0008_8343h ; I2C-bus Mode Register 2
.ICMR3 = 0008_8344h ; I2C-bus Mode Register 3
.ICFER = 0008_8345h ; I2C-bus Function Enable Register
.ICSER = 0008_8346h ; I2C-bus Status Enable Register
.ICIER = 0008_8347h ; I2C-bus Interrupt Enable Register
.ICSR1 = 0008_8348h ; I2C-bus Status Register 1
.ICSR2 = 0008_8349h ; I2C-bus Status Register 2
.SARL0 = 0008_834Ah ; Slave Address Register L0
.SARU0 = 0008_834Bh ; Slave Address Register U0
.SARL1 = 0008_834Ch ; Slave Address Register L1
.SARU1 = 0008_834Dh ; Slave Address Register U1
.SARL2 = 0008_834Eh ; Slave Address Register L2
.SARU2 = 0008_834Fh ; Slave Address Register U2
.ICBRL = 0008_8350h ; I2C-bus Bit Rate Low-Level Register
.ICBRH = 0008_8351h ; I2C-bus Bit Rate High-Level Register
.ICDRT = 0008_8352h ; I2C-bus Transmit Data Register
.ICDRR = 0008_8353h ; I2C-bus Receive Data Register

MMCIF:

.CECMDSET    = 0008_8500h ; Command Setting Register
.CEARG       = 0008_8508h ; Argument Register
.CEARGCMD12  = 0008_850Ch ; Automatically Issued CMD12 Argument Register
.CECMDCTRL   = 0008_8510h ; Command Control Register
.CEBLOCKSET  = 0008_8514h ; Transfer Block Setting Register
.CECLKCTRL   = 0008_8518h ; Clock Control Register
.CEBUFACC    = 0008_851Ch ; Buffer Access Setting Register
.CERESP3     = 0008_8520h ; Response Register 3
.CERESP2     = 0008_8524h ; Response Register 2
.CERESP1     = 0008_8528h ; Response Register 1
.CERESP0     = 0008_852Ch ; Response Register 0
.CERESPCMD12 = 0008_8530h ; Automatically Issued CMD12 Response Register
.CEDATA      = 0008_8534h ; Data Register
.CEBOOT      = 0008_853Ch ; Boot Operation Setting Register
.CEINT       = 0008_8540h ; Interrupt Status Flag Register
.CEINTEN     = 0008_8544h ; Interrupt Request Enable Register
.CEHOSTSTS1  = 0008_8548h ; Status Register 1
.CEHOSTSTS2  = 0008_854Ch ; Status Register 2
.CEDETECT    = 0008_8570h ; MMC Detection and Port Control Register
.CEADDMODE   = 0008_8574h ; Special Mode Setting Register
.CEVERSION   = 0008_857Ch ; Version Register

S12AD:

.ADCSR      = 0008_9000h ; A/D Control Register
.ADANSA0    = 0008_9004h ; A/D Channel Select Register A0
.ADADS0     = 0008_9008h ; A/D-Converted Value Addition/Average Function Channel Select Register 0
.ADADC      = 0008_900Ch ; A/D-Converted Value Addition/Average Count Select Register
.ADCER      = 0008_900Eh ; A/D Control Extended Register
.ADSTRGR    = 0008_9010h ; A/D Conversion Start Trigger Select Register
.ADANSB0    = 0008_9014h ; A/D Channel Select Register B0
.ADDBLDR    = 0008_9018h ; A/D Data Duplication Register
.ADRD       = 0008_901Eh ; A/D Self-Diagnosis Data Register
.ADDR0      = 0008_9020h ; A/D Data Register 0
.ADDR1      = 0008_9022h ; A/D Data Register 1
.ADDR2      = 0008_9024h ; A/D Data Register 2
.ADDR3      = 0008_9026h ; A/D Data Register 3
.ADDR4      = 0008_9028h ; A/D Data Register 4
.ADDR5      = 0008_902Ah ; A/D Data Register 5
.ADDR6      = 0008_902Ch ; A/D Data Register 6
.ADDR7      = 0008_902Eh ; A/D Data Register 7
.ADSAMPR    = 0008_9063h ; A/D Conversion Time Setting Protection Release Register
.ADSHCR     = 0008_9066h ; A/D Sample-and-Hold Circuit Control Register
.ADSAM      = 0008_906Eh ; A/D Conversion Time Setting Register
.ADDISCR    = 0008_907Ah ; A/D Disconnection Detection Control Register
.ADSHMSR    = 0008_907Ch ; A/D Sample-and-Hold Operating Mode Select Register
.ADGSPCR    = 0008_9080h ; A/D Group Scan Priority Control Register
.ADDBLDRA   = 0008_9084h ; A/D Data Duplication Register A
.ADDBLDRB   = 0008_9086h ; A/D Data Duplication Register B
.ADWINMON   = 0008_908Ch ; A/D Comparison Function Window A/B Status Monitoring Register
.ADCMPCR    = 0008_9090h ; A/D Comparison Function Control Register
.ADCMPANSR0 = 0008_9094h ; A/D Comparison Function Window A Channel Select Register 0
.ADCMPLR0   = 0008_9098h ; A/D Comparison Function Window A Comparison Condition Setting Register 0
.ADCMPDR0   = 0008_909Ch ; A/D Comparison Function Window A Lower Level Setting Register
.ADCMPDR1   = 0008_909Eh ; A/D Comparison Function Window A Upper Level Setting Register
.ADCMPSR0   = 0008_90A0h ; A/D Comparison Function Window A Channel Status Register 0
.ADCMPBNSR  = 0008_90A6h ; A/D Comparison Function Window B Channel Select Register
.ADWINLLB   = 0008_90A8h ; A/D Comparison Function Window B Lower Level Setting Register
.ADWINULB   = 0008_90AAh ; A/D Comparison Function Window B Upper Level Setting Register
.ADCMPBSR   = 0008_90ACh ; A/D Comparison Function Window B Channel Status Register
.ADANSC0    = 0008_90D4h ; A/D Channel Select Register C0
.ADGCTRGR   = 0008_90D9h ; A/D Group C Trigger Select Register
.ADSSTR0    = 0008_90E0h ; A/D Sampling State Register 0
.ADSSTR1    = 0008_90E1h ; A/D Sampling State Register 1
.ADSSTR2    = 0008_90E2h ; A/D Sampling State Register 2
.ADSSTR3    = 0008_90E3h ; A/D Sampling State Register 3
.ADSSTR4    = 0008_90E4h ; A/D Sampling State Register 4
.ADSSTR5    = 0008_90E5h ; A/D Sampling State Register 5
.ADSSTR6    = 0008_90E6h ; A/D Sampling State Register 6
.ADSSTR7    = 0008_90E7h ; A/D Sampling State Register 7

S12AD1:

.ADCSR      = 0008_9100h ; A/D Control Register
.ADANSA0    = 0008_9104h ; A/D Channel Select Register A0
.ADANSA1    = 0008_9106h ; A/D Channel Select Register A1
.ADADS0     = 0008_9108h ; A/D-Converted Value Addition/Average Function Channel Select Register 0
.ADADS1     = 0008_910Ah ; A/D-Converted Value Addition/Average Function Channel Select Register 1
.ADADC      = 0008_910Ch ; A/D-Converted Value Addition/Average Count Select Register
.ADCER      = 0008_910Eh ; A/D Control Extended Register
.ADSTRGR    = 0008_9110h ; A/D Conversion Start Trigger Select Register
.ADEXICR    = 0008_9112h ; A/D Conversion Extended Input Control Register
.ADANSB0    = 0008_9114h ; A/D Channel Select Register B0
.ADANSB1    = 0008_9116h ; A/D Channel Select Register B1
.ADDBLDR    = 0008_9118h ; A/D Data Duplication Register
.ADTSDR     = 0008_911Ah ; A/D Temperature Sensor Data Register
.ADOCDR     = 0008_911Ch ; A/D Internal Reference Voltage Data Register
.ADRD       = 0008_911Eh ; A/D Self-Diagnosis Data Register
.ADDR0      = 0008_9120h ; A/D Data Register 0
.ADDR1      = 0008_9122h ; A/D Data Register 1
.ADDR2      = 0008_9124h ; A/D Data Register 2
.ADDR3      = 0008_9126h ; A/D Data Register 3
.ADDR4      = 0008_9128h ; A/D Data Register 4
.ADDR5      = 0008_912Ah ; A/D Data Register 5
.ADDR6      = 0008_912Ch ; A/D Data Register 6
.ADDR7      = 0008_912Eh ; A/D Data Register 7
.ADDR8      = 0008_9130h ; A/D Data Register 8
.ADDR9      = 0008_9132h ; A/D Data Register 9
.ADDR10     = 0008_9134h ; A/D Data Register 10
.ADDR11     = 0008_9136h ; A/D Data Register 11
.ADDR12     = 0008_9138h ; A/D Data Register 12
.ADDR13     = 0008_913Ah ; A/D Data Register 13
.ADDR14     = 0008_913Ch ; A/D Data Register 14
.ADDR15     = 0008_913Eh ; A/D Data Register 15
.ADDR16     = 0008_9140h ; A/D Data Register 16
.ADDR17     = 0008_9142h ; A/D Data Register 17
.ADDR18     = 0008_9144h ; A/D Data Register 18
.ADDR19     = 0008_9146h ; A/D Data Register 19
.ADDR20     = 0008_9148h ; A/D Data Register 20
.ADSAMPR    = 0008_9163h ; A/D Conversion Time Setting Protection Release Register
.ADSAM      = 0008_916Eh ; A/D Conversion Time Setting Register
.ADDISCR    = 0008_917Ah ; A/D Disconnection Detection Control Register
.ADGSPCR    = 0008_9180h ; A/D Group Scan Priority Control Register
.ADDBLDRA   = 0008_9184h ; A/D Data Duplication Register A
.ADDBLDRB   = 0008_9186h ; A/D Data Duplication Register B
.ADWINMON   = 0008_918Ch ; A/D Comparison Function Window A/B Status Monitoring Register
.ADCMPCR    = 0008_9190h ; A/D Comparison Function Control Register
.ADCMPANSER = 0008_9192h ; A/D Comparison Function Window A Extended Input Select Register
.ADCMPLER   = 0008_9193h ; A/D Comparison Function Window A Extended Input Comparison Condition Setting Register
.ADCMPANSR0 = 0008_9194h ; A/D Comparison Function Window A Channel Select Register 0
.ADCMPANSR1 = 0008_9196h ; A/D Comparison Function Window A Channel Select Register 1
.ADCMPLR0   = 0008_9198h ; A/D Comparison Function Window A Comparison Condition Setting Register 0
.ADCMPLR1   = 0008_919Ah ; A/D Comparison Function Window A Comparison Condition Setting Register 1
.ADCMPDR0   = 0008_919Ch ; A/D Comparison Function Window A Lower Level Setting Register
.ADCMPDR1   = 0008_919Eh ; A/D Comparison Function Window A Upper Level Setting Register
.ADCMPSR0   = 0008_91A0h ; A/D Comparison Function Window A Channel Status Register 0
.ADCMPSR1   = 0008_91A2h ; A/D Comparison Function Window A Channel Status Register 1
.ADCMPSER   = 0008_91A4h ; A/D Comparison Function Window A Extended Input Channel Status Register
.ADCMPBNSR  = 0008_91A6h ; A/D Comparison Function Window B Channel Select Register
.ADWINLLB   = 0008_91A8h ; A/D Comparison Function Window B Lower Level Setting Register
.ADWINULB   = 0008_91AAh ; A/D Comparison Function Window B Upper Level Setting Register
.ADCMPBSR   = 0008_91ACh ; A/D Comparison Function Window B Channel Status Register
.ADANSC0    = 0008_91D4h ; A/D Channel Select Register C0
.ADANSC1    = 0008_91D6h ; A/D Channel Select Register C1
.ADGCEXCR   = 0008_91D8h ; A/D Group C Extended Input Control Register
.ADGCTRGR   = 0008_91D9h ; A/D Group C Trigger Select Register
.ADSSTRL    = 0008_91DDh ; A/D Sampling State Register L
.ADSSTRT    = 0008_91DEh ; A/D Sampling State Register T
.ADSSTRO    = 0008_91DFh ; A/D Sampling State Register O
.ADSSTR0    = 0008_91E0h ; A/D Sampling State Register 0
.ADSSTR1    = 0008_91E1h ; A/D Sampling State Register 1
.ADSSTR2    = 0008_91E2h ; A/D Sampling State Register 2
.ADSSTR3    = 0008_91E3h ; A/D Sampling State Register 3
.ADSSTR4    = 0008_91E4h ; A/D Sampling State Register 4
.ADSSTR5    = 0008_91E5h ; A/D Sampling State Register 5
.ADSSTR6    = 0008_91E6h ; A/D Sampling State Register 6
.ADSSTR7    = 0008_91E7h ; A/D Sampling State Register 7
.ADSSTR8    = 0008_91E8h ; A/D Sampling State Register 8
.ADSSTR9    = 0008_91E9h ; A/D Sampling State Register 9
.ADSSTR10   = 0008_91EAh ; A/D Sampling State Register 10
.ADSSTR11   = 0008_91EBh ; A/D Sampling State Register 11
.ADSSTR12   = 0008_91ECh ; A/D Sampling State Register 12
.ADSSTR13   = 0008_91EDh ; A/D Sampling State Register 13
.ADSSTR14   = 0008_91EEh ; A/D Sampling State Register 14
.ADSSTR15   = 0008_91EFh ; A/D Sampling State Register 15

QSPI:

.SPCR    = 0008_9E00h ; QSPI Control Register
.SSLP    = 0008_9E01h ; QSPI Slave Select Polarity Register
.SPPCR   = 0008_9E02h ; QSPI Pin Control Register
.SPSR    = 0008_9E03h ; QSPI Status Register
.SPDR    = 0008_9E04h ; QSPI Data Register
.SPSCR   = 0008_9E08h ; QSPI Sequence Control Register
.SPSSR   = 0008_9E09h ; QSPI Sequence Status Register
.SPBR    = 0008_9E0Ah ; QSPI Bit Rate Register
.SPDCR   = 0008_9E0Bh ; QSPI Data Control Register
.SPCKD   = 0008_9E0Ch ; QSPI Clock Delay Register
.SSLND   = 0008_9E0Dh ; QSPI Slave Select Negation Delay Register
.SPND    = 0008_9E0Eh ; QSPI Next-Access Delay Register
.SPCMD0  = 0008_9E10h ; QSPI Command Register 0
.SPCMD1  = 0008_9E12h ; QSPI Command Register 1
.SPCMD2  = 0008_9E14h ; QSPI Command Register 2
.SPCMD3  = 0008_9E16h ; QSPI Command Register 3
.SPBFCR  = 0008_9E18h ; QSPI Buffer Control Register
.SPBDCR  = 0008_9E1Ah ; QSPI Buffer Data Count Set Register
.SPBMUL0 = 0008_9E1Ch ; QSPI Transfer Data Length Multiplier Setting Register 0
.SPBMUL1 = 0008_9E20h ; QSPI Transfer Data Length Multiplier Setting Register 1
.SPBMUL2 = 0008_9E24h ; QSPI Transfer Data Length Multiplier Setting Register 2
.SPBMUL3 = 0008_9E28h ; QSPI Transfer Data Length Multiplier Setting Register 3

SCI0:

.SMR   = 0008_A000h ; Serial Mode Register
.BRR   = 0008_A001h ; Bit Rate Register
.SCR   = 0008_A002h ; Serial Control Register
.TDR   = 0008_A003h ; Transmit Data Register
.SSR   = 0008_A004h ; Serial Status Register
.RDR   = 0008_A005h ; Receive Data Register
.SCMR  = 0008_A006h ; Smart Card Mode Register
.SEMR  = 0008_A007h ; Serial Extended Mode Register
.SNFR  = 0008_A008h ; Noise Filter Setting Register
.SIMR1 = 0008_A009h ; I2C Mode Register 1
.SIMR2 = 0008_A00Ah ; I2C Mode Register 2
.SIMR3 = 0008_A00Bh ; I2C Mode Register 3
.SISR  = 0008_A00Ch ; I2C Status Register
.SPMR  = 0008_A00Dh ; SPI Mode Register
.TDRH  = 0008_A00Eh ; Transmit Data Register H
.TDRL  = 0008_A00Fh ; Transmit Data Register L
.TDRHL = 0008_A00Eh ; Transmit Data Register HL
.RDRH  = 0008_A010h ; Receive Data Register H
.RDRL  = 0008_A011h ; Receive Data Register L
.RDRHL = 0008_A010h ; Receive Data Register HL
.MDDR  = 0008_A012h ; Modulation Duty Register
.DCCR  = 0008_A013h ; Data Comparison Control Register
.CDR.H = 0008_A01Ah ; Comparison Data Register
.CDR.L = 0008_A01Bh ; Comparison Data Register
.CDR   = 0008_A01Ah ; Comparison Data Register
.SPTR  = 0008_A01Ch ; Serial Port Register

SCI1:

.SMR   = 0008_A020h ; Serial Mode Register
.BRR   = 0008_A021h ; Bit Rate Register
.SCR   = 0008_A022h ; Serial Control Register
.TDR   = 0008_A023h ; Transmit Data Register
.SSR   = 0008_A024h ; Serial Status Register
.RDR   = 0008_A025h ; Receive Data Register
.SCMR  = 0008_A026h ; Smart Card Mode Register
.SEMR  = 0008_A027h ; Serial Extended Mode Register
.SNFR  = 0008_A028h ; Noise Filter Setting Register
.SIMR1 = 0008_A029h ; I2C Mode Register 1
.SIMR2 = 0008_A02Ah ; I2C Mode Register 2
.SIMR3 = 0008_A02Bh ; I2C Mode Register 3
.SISR  = 0008_A02Ch ; I2C Status Register
.SPMR  = 0008_A02Dh ; SPI Mode Register
.TDRH  = 0008_A02Eh ; Transmit Data Register H
.TDRL  = 0008_A02Fh ; Transmit Data Register L
.TDRHL = 0008_A02Eh ; Transmit Data Register HL
.RDRH  = 0008_A030h ; Receive Data Register H
.RDRL  = 0008_A031h ; Receive Data Register L
.RDRHL = 0008_A030h ; Receive Data Register HL
.MDDR  = 0008_A032h ; Modulation Duty Register
.DCCR  = 0008_A033h ; Data Comparison Control Register
.CDR.H = 0008_A03Ah ; Comparison Data Register
.CDR.L = 0008_A03Bh ; Comparison Data Register
.CDR   = 0008_A03Ah ; Comparison Data Register
.SPTR  = 0008_A03Ch ; Serial Port Register
.SMR   = 0008_A040h ; Serial Mode Register

SCI2:

.SMR   = 0008_A040h ; Serial Mode Register
.BRR   = 0008_A041h ; Bit Rate Register
.SCR   = 0008_A042h ; Serial Control Register
.TDR   = 0008_A043h ; Transmit Data Register
.SSR   = 0008_A044h ; Serial Status Register
.RDR   = 0008_A045h ; Receive Data Register
.SCMR  = 0008_A046h ; Smart Card Mode Register
.SEMR  = 0008_A047h ; Serial Extended Mode Register
.SNFR  = 0008_A048h ; Noise Filter Setting Register
.SIMR1 = 0008_A049h ; I2C Mode Register 1
.SIMR2 = 0008_A04Ah ; I2C Mode Register 2
.SIMR3 = 0008_A04Bh ; I2C Mode Register 3
.SISR  = 0008_A04Ch ; I2C Status Register
.SPMR  = 0008_A04Dh ; SPI Mode Register
.TDRH  = 0008_A04Eh ; Transmit Data Register H
.TDRL  = 0008_A04Fh ; Transmit Data Register L
.TDRHL = 0008_A04Eh ; Transmit Data Register HL
.RDRH  = 0008_A050h ; Receive Data Register H
.RDRL  = 0008_A051h ; Receive Data Register L
.RDRHL = 0008_A050h ; Receive Data Register HL
.MDDR  = 0008_A052h ; Modulation Duty Register
.DCCR  = 0008_A053h ; Data Comparison Control Register
.CDR.H = 0008_A05Ah ; Comparison Data Register
.CDR.L = 0008_A05Bh ; Comparison Data Register
.CDR   = 0008_A05Ah ; Comparison Data Register
.SPTR  = 0008_A05Ch ; Serial Port Register

SCI3:

.SMR   = 0008_A060h ; Serial Mode Register
.BRR   = 0008_A061h ; Bit Rate Register
.SCR   = 0008_A062h ; Serial Control Register
.TDR   = 0008_A063h ; Transmit Data Register
.SSR   = 0008_A064h ; Serial Status Register
.RDR   = 0008_A065h ; Receive Data Register
.SCMR  = 0008_A066h ; Smart Card Mode Register
.SEMR  = 0008_A067h ; Serial Extended Mode Register
.SNFR  = 0008_A068h ; Noise Filter Setting Register
.SIMR1 = 0008_A069h ; I2C Mode Register 1
.SIMR2 = 0008_A06Ah ; I2C Mode Register 2
.SIMR3 = 0008_A06Bh ; I2C Mode Register 3
.SISR  = 0008_A06Ch ; I2C Status Register
.SPMR  = 0008_A06Dh ; SPI Mode Register
.TDRH  = 0008_A06Eh ; Transmit Data Register H
.TDRL  = 0008_A06Fh ; Transmit Data Register L
.TDRHL = 0008_A06Eh ; Transmit Data Register HL
.RDRH  = 0008_A070h ; Receive Data Register H
.RDRL  = 0008_A071h ; Receive Data Register L
.RDRHL = 0008_A070h ; Receive Data Register HL
.MDDR  = 0008_A072h ; Modulation Duty Register
.DCCR  = 0008_A073h ; Data Comparison Control Register
.CDR.H = 0008_A07Ah ; Comparison Data Register
.CDR.L = 0008_A07Bh ; Comparison Data Register
.CDR   = 0008_A07Ah ; Comparison Data Register
.SPTR  = 0008_A07Ch ; Serial Port Register

SCI4:

.SMR   = 0008_A080h ; Serial Mode Register
.BRR   = 0008_A081h ; Bit Rate Register
.SCR   = 0008_A082h ; Serial Control Register
.TDR   = 0008_A083h ; Transmit Data Register
.SSR   = 0008_A084h ; Serial Status Register
.RDR   = 0008_A085h ; Receive Data Register
.SCMR  = 0008_A086h ; Smart Card Mode Register
.SEMR  = 0008_A087h ; Serial Extended Mode Register
.SNFR  = 0008_A088h ; Noise Filter Setting Register
.SIMR1 = 0008_A089h ; I2C Mode Register 1
.SIMR2 = 0008_A08Ah ; I2C Mode Register 2
.SIMR3 = 0008_A08Bh ; I2C Mode Register 3
.SISR  = 0008_A08Ch ; I2C Status Register
.SPMR  = 0008_A08Dh ; SPI Mode Register
.TDRH  = 0008_A08Eh ; Transmit Data Register H
.TDRL  = 0008_A08Fh ; Transmit Data Register L
.TDRHL = 0008_A08Eh ; Transmit Data Register HL
.RDRH  = 0008_A090h ; Receive Data Register H
.RDRL  = 0008_A091h ; Receive Data Register L
.RDRHL = 0008_A090h ; Receive Data Register HL
.MDDR  = 0008_A092h ; Modulation Duty Register
.DCCR  = 0008_A093h ; Data Comparison Control Register
.CDR.H = 0008_A09Ah ; Comparison Data Register
.CDR.L = 0008_A09Bh ; Comparison Data Register
.CDR   = 0008_A09Ah ; Comparison Data Register
.SPTR  = 0008_A09Ch ; Serial Port Register

SCI5:

.SMR   = 0008_A0A0h ; Serial Mode Register
.BRR   = 0008_A0A1h ; Bit Rate Register
.SCR   = 0008_A0A2h ; Serial Control Register
.TDR   = 0008_A0A3h ; Transmit Data Register
.SSR   = 0008_A0A4h ; Serial Status Register
.RDR   = 0008_A0A5h ; Receive Data Register
.SCMR  = 0008_A0A6h ; Smart Card Mode Register
.SEMR  = 0008_A0A7h ; Serial Extended Mode Register
.SNFR  = 0008_A0A8h ; Noise Filter Setting Register
.SIMR1 = 0008_A0A9h ; I2C Mode Register 1
.SIMR2 = 0008_A0AAh ; I2C Mode Register 2
.SIMR3 = 0008_A0ABh ; I2C Mode Register 3
.SISR  = 0008_A0ACh ; I2C Status Register
.SPMR  = 0008_A0ADh ; SPI Mode Register
.TDRH  = 0008_A0AEh ; Transmit Data Register H
.TDRL  = 0008_A0AFh ; Transmit Data Register L
.TDRHL = 0008_A0AEh ; Transmit Data Register HL
.RDRH  = 0008_A0B0h ; Receive Data Register H
.RDRL  = 0008_A0B1h ; Receive Data Register L
.RDRHL = 0008_A0B0h ; Receive Data Register HL
.MDDR  = 0008_A0B2h ; Modulation Duty Register
.DCCR  = 0008_A0B3h ; Data Comparison Control Register
.CDR.H = 0008_A0BAh ; Comparison Data Register
.CDR.L = 0008_A0BBh ; Comparison Data Register
.CDR   = 0008_A0BAh ; Comparison Data Register
.SPTR  = 0008_A0BCh ; Serial Port Register

SCI6:

.SMR   = 0008_A0C0h ; Serial Mode Register
.BRR   = 0008_A0C1h ; Bit Rate Register
.SCR   = 0008_A0C2h ; Serial Control Register
.TDR   = 0008_A0C3h ; Transmit Data Register
.SSR   = 0008_A0C4h ; Serial Status Register
.RDR   = 0008_A0C5h ; Receive Data Register
.SCMR  = 0008_A0C6h ; Smart Card Mode Register
.SEMR  = 0008_A0C7h ; Serial Extended Mode Register
.SNFR  = 0008_A0C8h ; Noise Filter Setting Register
.SIMR1 = 0008_A0C9h ; I2C Mode Register 1
.SIMR2 = 0008_A0CAh ; I2C Mode Register 2
.SIMR3 = 0008_A0CBh ; I2C Mode Register 3
.SISR  = 0008_A0CCh ; I2C Status Register
.SPMR  = 0008_A0CDh ; SPI Mode Register
.TDRH  = 0008_A0CEh ; Transmit Data Register H
.TDRL  = 0008_A0CFh ; Transmit Data Register L
.TDRHL = 0008_A0CEh ; Transmit Data Register HL
.RDRH  = 0008_A0D0h ; Receive Data Register H
.RDRL  = 0008_A0D1h ; Receive Data Register L
.RDRHL = 0008_A0D0h ; Receive Data Register HL
.MDDR  = 0008_A0D2h ; Modulation Duty Register
.DCCR  = 0008_A0D3h ; Data Comparison Control Register
.CDR.H = 0008_A0DAh ; Comparison Data Register
.CDR.L = 0008_A0DBh ; Comparison Data Register
.CDR   = 0008_A0DAh ; Comparison Data Register
.SPTR  = 0008_A0DCh ; Serial Port Register

SCI7:

.SMR     = 000D_00E0h ; Serial Mode Register
.BRR     = 000D_00E1h ; Bit Rate Register
.SCR     = 000D_00E2h ; Serial Control Register
.TDR     = 000D_00E3h ; Transmit Data Register
.SSR     = 000D_00E4h ; Serial Status Register
.SSRFIFO = 000D_00E4h ; Serial Status Register
.RDR     = 000D_00E5h ; Receive Data Register
.SCMR    = 000D_00E6h ; Smart Card Mode Register
.SEMR    = 000D_00E7h ; Serial Extended Mode Register
.SNFR    = 000D_00E8h ; Noise Filter Setting Register
.SIMR1   = 000D_00E9h ; I2C Mode Register 1
.SIMR2   = 000D_00EAh ; I2C Mode Register 2
.SIMR3   = 000D_00EBh ; I2C Mode Register 3
.SISR    = 000D_00ECh ; I2C Status Register
.SPMR    = 000D_00EDh ; SPI Mode Register
.TDRH    = 000D_00EEh ; Transmit Data Register H
.TDRL    = 000D_00EFh ; Transmit Data Register L
.TDRHL   = 000D_00EEh ; Transmit Data Register HL
.FTDR.H  = 000D_00EEh ; Transmit FIFO Data Register
.FTDR.L  = 000D_00EFh ; Transmit FIFO Data Register
.FTDR    = 000D_00EEh ; Transmit FIFO Data Register
.RDRH    = 000D_00F0h ; Receive Data Register H
.RDRL    = 000D_00F1h ; Receive Data Register L
.RDRHL   = 000D_00F0h ; Receive Data Register HL
.FRDR.H  = 000D_00F0h ; Receive FIFO Data Register
.FRDR.L  = 000D_00F1h ; Receive FIFO Data Register
.FRDR    = 000D_00F0h ; Receive FIFO Data Register
.MDDR    = 000D_00F2h ; Modulation Duty Register
.DCCR    = 000D_00F3h ; Data Comparison Control Register
.FCR.H   = 000D_00F4h ; FIFO Control Register
.FCR.L   = 000D_00F5h ; FIFO Control Register
.FCR     = 000D_00F4h ; FIFO Control Register
.FDR.H   = 000D_00F6h ; FIFO Data Count Register
.FDR.L   = 000D_00F7h ; FIFO Data Count Register
.FDR     = 000D_00F6h ; FIFO Data Count Register
.LSR.H   = 000D_00F8h ; Line Status Register
.LSR.L   = 000D_00F9h ; Line Status Register
.LSR     = 000D_00F8h ; Line Status Register
.CDR.H   = 000D_00FAh ; Comparison Data Register
.CDR.L   = 000D_00FBh ; Comparison Data Register
.CDR     = 000D_00FAh ; Comparison Data Register
.SPTR    = 000D_00FCh ; Serial Port Register

SCI8:

.SMR     = 000D_0000h ; Serial Mode Register
.BRR     = 000D_0001h ; Bit Rate Register
.SCR     = 000D_0002h ; Serial Control Register
.TDR     = 000D_0003h ; Transmit Data Register
.SSR     = 000D_0004h ; Serial Status Register
.SSRFIFO = 000D_0004h ; Serial Status Register
.RDR     = 000D_0005h ; Receive Data Register
.SCMR    = 000D_0006h ; Smart Card Mode Register
.SEMR    = 000D_0007h ; Serial Extended Mode Register
.SNFR    = 000D_0008h ; Noise Filter Setting Register
.SIMR1   = 000D_0009h ; I2C Mode Register 1
.SIMR2   = 000D_000Ah ; I2C Mode Register 2
.SIMR3   = 000D_000Bh ; I2C Mode Register 3
.SISR    = 000D_000Ch ; I2C Status Register
.SPMR    = 000D_000Dh ; SPI Mode Register
.TDRH    = 000D_000Eh ; Transmit Data Register H
.TDRL    = 000D_000Fh ; Transmit Data Register L
.TDRHL   = 000D_000Eh ; Transmit Data Register HL
.FTDR.H  = 000D_000Eh ; Transmit FIFO Data Register
.FTDR.L  = 000D_000Fh ; Transmit FIFO Data Register
.FTDR    = 000D_000Eh ; Transmit FIFO Data Register
.RDRH    = 000D_0010h ; Receive Data Register H
.RDRL    = 000D_0011h ; Receive Data Register L
.RDRHL   = 000D_0010h ; Receive Data Register HL
.FRDR.H  = 000D_0010h ; Receive FIFO Data Register
.FRDR.L  = 000D_0011h ; Receive FIFO Data Register
.FRDR    = 000D_0010h ; Receive FIFO Data Register
.MDDR    = 000D_0012h ; Modulation Duty Register
.DCCR    = 000D_0013h ; Data Comparison Control Register
.FCR.H   = 000D_0014h ; FIFO Control Register
.FCR.L   = 000D_0015h ; FIFO Control Register
.FCR     = 000D_0014h ; FIFO Control Register
.FDR.H   = 000D_0016h ; FIFO Data Count Register
.FDR.L   = 000D_0017h ; FIFO Data Count Register
.FDR     = 000D_0016h ; FIFO Data Count Register
.LSR.H   = 000D_0018h ; Line Status Register
.LSR.L   = 000D_0019h ; Line Status Register
.LSR     = 000D_0018h ; Line Status Register
.CDR.H   = 000D_001Ah ; Comparison Data Register
.CDR.L   = 000D_001Bh ; Comparison Data Register
.CDR     = 000D_001Ah ; Comparison Data Register
.SPTR    = 000D_001Ch ; Serial Port Register

SCI9:

.SMR     = 000D_0020h ; Serial Mode Register
.BRR     = 000D_0021h ; Bit Rate Register
.SCR     = 000D_0022h ; Serial Control Register
.TDR     = 000D_0023h ; Transmit Data Register
.SSR     = 000D_0024h ; Serial Status Register
.SSRFIFO = 000D_0024h ; Serial Status Register
.RDR     = 000D_0025h ; Receive Data Register
.SCMR    = 000D_0026h ; Smart Card Mode Register
.SEMR    = 000D_0027h ; Serial Extended Mode Register
.SNFR    = 000D_0028h ; Noise Filter Setting Register
.SIMR1   = 000D_0029h ; I2C Mode Register 1
.SIMR2   = 000D_002Ah ; I2C Mode Register 2
.SIMR3   = 000D_002Bh ; I2C Mode Register 3
.SISR    = 000D_002Ch ; I2C Status Register
.SPMR    = 000D_002Dh ; SPI Mode Register
.TDRH    = 000D_002Eh ; Transmit Data Register H
.TDRL    = 000D_002Fh ; Transmit Data Register L
.TDRHL   = 000D_002Eh ; Transmit Data Register HL
.FTDR.H  = 000D_002Eh ; Transmit FIFO Data Register
.FTDR.L  = 000D_002Fh ; Transmit FIFO Data Register
.FTDR    = 000D_002Eh ; Transmit FIFO Data Register
.RDRH    = 000D_0030h ; Receive Data Register H
.RDRL    = 000D_0031h ; Receive Data Register L
.RDRHL   = 000D_0030h ; Receive Data Register HL
.FRDR.H  = 000D_0030h ; Receive FIFO Data Register
.FRDR.L  = 000D_0031h ; Receive FIFO Data Register
.FRDR    = 000D_0030h ; Receive FIFO Data Register
.MDDR    = 000D_0032h ; Modulation Duty Register
.DCCR    = 000D_0033h ; Data Comparison Control Register
.FCR.H   = 000D_0034h ; FIFO Control Register
.FCR.L   = 000D_0035h ; FIFO Control Register
.FCR     = 000D_0034h ; FIFO Control Register
.FDR.H   = 000D_0036h ; FIFO Data Count Register
.FDR.L   = 000D_0037h ; FIFO Data Count Register
.FDR     = 000D_0036h ; FIFO Data Count Register
.LSR.H   = 000D_0038h ; Line Status Register
.LSR.L   = 000D_0039h ; Line Status Register
.LSR     = 000D_0038h ; Line Status Register
.CDR.H   = 000D_003Ah ; Comparison Data Register
.CDR.L   = 000D_003Bh ; Comparison Data Register
.CDR     = 000D_003Ah ; Comparison Data Register
.SPTR    = 000D_003Ch ; Serial Port Register

SCI10:

.SMR     = 000D_0040h ; Serial Mode Register
.BRR     = 000D_0041h ; Bit Rate Register
.SCR     = 000D_0042h ; Serial Control Register
.TDR     = 000D_0043h ; Transmit Data Register
.SSR     = 000D_0044h ; Serial Status Register
.SSRFIFO = 000D_0044h ; Serial Status Register
.RDR     = 000D_0045h ; Receive Data Register
.SCMR    = 000D_0046h ; Smart Card Mode Register
.SEMR    = 000D_0047h ; Serial Extended Mode Register
.SNFR    = 000D_0048h ; Noise Filter Setting Register
.SIMR1   = 000D_0049h ; I2C Mode Register 1
.SIMR2   = 000D_004Ah ; I2C Mode Register 2
.SIMR3   = 000D_004Bh ; I2C Mode Register 3
.SISR    = 000D_004Ch ; I2C Status Register
.SPMR    = 000D_004Dh ; SPI Mode Register
.TDRH    = 000D_004Eh ; Transmit Data Register H
.TDRL    = 000D_004Fh ; Transmit Data Register L
.TDRHL   = 000D_004Eh ; Transmit Data Register HL
.FTDR.H  = 000D_004Eh ; Transmit FIFO Data Register
.FTDR.L  = 000D_004Fh ; Transmit FIFO Data Register
.FTDR    = 000D_004Eh ; Transmit FIFO Data Register
.RDRH    = 000D_0050h ; Receive Data Register H
.RDRL    = 000D_0051h ; Receive Data Register L
.RDRHL   = 000D_0050h ; Receive Data Register HL
.FRDR.H  = 000D_0050h ; Receive FIFO Data Register
.FRDR.L  = 000D_0051h ; Receive FIFO Data Register
.FRDR    = 000D_0050h ; Receive FIFO Data Register
.MDDR    = 000D_0052h ; Modulation Duty Register
.DCCR    = 000D_0053h ; Data Comparison Control Register
.FCR.H   = 000D_0054h ; FIFO Control Register
.FCR.L   = 000D_0055h ; FIFO Control Register
.FCR     = 000D_0054h ; FIFO Control Register
.FDR.H   = 000D_0056h ; FIFO Data Count Register
.FDR.L   = 000D_0057h ; FIFO Data Count Register
.FDR     = 000D_0056h ; FIFO Data Count Register
.LSR.H   = 000D_0058h ; Line Status Register
.LSR.L   = 000D_0059h ; Line Status Register
.LSR     = 000D_0058h ; Line Status Register
.CDR.H   = 000D_005Ah ; Comparison Data Register
.CDR.L   = 000D_005Bh ; Comparison Data Register
.CDR     = 000D_005Ah ; Comparison Data Register
.SPTR    = 000D_005Ch ; Serial Port Register

SCI11:

.SMR     = 000D_0060h ; Serial Mode Register
.BRR     = 000D_0061h ; Bit Rate Register
.SCR     = 000D_0062h ; Serial Control Register
.TDR     = 000D_0063h ; Transmit Data Register
.SSR     = 000D_0064h ; Serial Status Register
.SSRFIFO = 000D_0064h ; Serial Status Register
.RDR     = 000D_0065h ; Receive Data Register
.SCMR    = 000D_0066h ; Smart Card Mode Register
.SEMR    = 000D_0067h ; Serial Extended Mode Register
.SNFR    = 000D_0068h ; Noise Filter Setting Register
.SIMR1   = 000D_0069h ; I2C Mode Register 1
.SIMR2   = 000D_006Ah ; I2C Mode Register 2
.SIMR3   = 000D_006Bh ; I2C Mode Register 3
.SISR    = 000D_006Ch ; I2C Status Register
.SPMR    = 000D_006Dh ; SPI Mode Register
.TDRH    = 000D_006Eh ; Transmit Data Register H
.TDRL    = 000D_006Fh ; Transmit Data Register L
.TDRHL   = 000D_006Eh ; Transmit Data Register HL
.FTDR.H  = 000D_006Eh ; Transmit FIFO Data Register H
.FTDR.L  = 000D_006Fh ; Transmit FIFO Data Register L
.FTDR    = 000D_006Eh ; Transmit FIFO Data Register
.RDRH    = 000D_0070h ; Receive Data Register H
.RDRL    = 000D_0071h ; Receive Data Register L
.RDRHL   = 000D_0070h ; Receive Data Register HL
.FRDR.H  = 000D_0070h ; Receive FIFO Data Register H
.FRDR.L  = 000D_0071h ; Receive FIFO Data Register L
.FRDR    = 000D_0070h ; Receive FIFO Data Register
.MDDR    = 000D_0072h ; Modulation Duty Register
.DCCR    = 000D_0073h ; Data Comparison Control Register
.FCR.H   = 000D_0074h ; FIFO Control Register
.FCR.L   = 000D_0075h ; FIFO Control Register
.FCR     = 000D_0074h ; FIFO Control Register
.FDR.H   = 000D_0076h ; FIFO Data Count Register
.FDR.L   = 000D_0077h ; FIFO Data Count Register
.FDR     = 000D_0076h ; FIFO Data Count Register
.LSR.H   = 000D_0078h ; Line Status Register
.LSR.L   = 000D_0079h ; Line Status Register
.LSR     = 000D_0078h ; Line Status Register
.CDR.H   = 000D_007Ah ; Comparison Data Register
.CDR.L   = 000D_007Bh ; Comparison Data Register
.CDR     = 000D_007Ah ; Comparison Data Register
.SPTR    = 000D_007Ch ; Serial Port Register

SSIE0:

.SSICR   = 0008_A500h ; Control Register
.SSISR   = 0008_A504h ; Status Register
.SSIFCR  = 0008_A510h ; FIFO Control Register
.SSIFSR  = 0008_A514h ; FIFO Status Register
.SSIFTDR = 0008_A518h ; Transmit FIFO Data Register
.SSIFRDR = 0008_A51Ch ; Receive FIFO Data Register
.SSIOFR  = 0008_A520h ; Audio Format Register
.SSISCR  = 0008_A524h ; FIFO Status Control Register

SSIE1:

.SSICR   = 0008_A540h ; Control Register
.SSISR   = 0008_A544h ; Status Register
.SSIFCR  = 0008_A550h ; FIFO Control Register
.SSIFSR  = 0008_A554h ; FIFO Status Register
.SSIFTDR = 0008_A558h ; Transmit FIFO Data Register
.SSIFRDR = 0008_A55Ch ; Receive FIFO Data Register
.SSIOFR  = 0008_A560h ; Audio Format Register
.SSISCR  = 0008_A564h ; FIFO Status Control Register

SDHI:

.SDCMD    = 0008_AC00h ; Command Register
.SDARG    = 0008_AC08h ; Argument Register
.SDSTOP   = 0008_AC10h ; Data Stop Register
.SDBLKCNT = 0008_AC14h ; Block Count Register
.SDRSP10  = 0008_AC18h ; Response Register 10
.SDRSP32  = 0008_AC20h ; Response Register 32
.SDRSP54  = 0008_AC28h ; Response Register 54
.SDRSP76  = 0008_AC30h ; Response Register 76
.SDSTS1   = 0008_AC38h ; SD Status Register 1
.SDSTS2   = 0008_AC3Ch ; SD Status Register 2
.SDIMSK1  = 0008_AC40h ; SD Interrupt Mask Register 1
.SDIMSK2  = 0008_AC44h ; SD Interrupt Mask Register 2
.SDCLKCR  = 0008_AC48h ; SDHI Clock Control Register
.SDSIZE   = 0008_AC4Ch ; Transfer Data Size Register
.SDOPT    = 0008_AC50h ; Card Access Option Register
.SDERSTS1 = 0008_AC58h ; SD Error Status Register 1
.SDERSTS2 = 0008_AC5Ch ; SD Error Status Register 2
.SDBUFR   = 0008_AC60h ; SD Buffer Register
.SDIOMD   = 0008_AC68h ; SDIO Mode Control Register
.SDIOSTS  = 0008_AC6Ch ; SDIO Status Register
.SDIOIMSK = 0008_AC70h ; SDIO Interrupt Mask Register
.SDDMAEN  = 0008_ADB0h ; DMA Transfer Enable Register
.SDRST    = 0008_ADC0h ; SDHI Software Reset Register
.SDVER    = 0008_ADC4h ; Version Register
.SDSWAP   = 0008_ADE0h ; Swap Control Register

CAC:

.CACR0   = 0008_B000h ; CAC Control Register 0
.CACR1   = 0008_B001h ; CAC Control Register 1
.CACR2   = 0008_B002h ; CAC Control Register 2
.CAICR   = 0008_B003h ; CAC Interrupt Request Enable Register
.CASTR   = 0008_B004h ; CAC Status Register
.CAULVR  = 0008_B006h ; CAC Upper-Limit Value Setting Register
.CALLVR  = 0008_B008h ; CAC Lower-Limit Value Setting Register
.CACNTBR = 0008_B00Ah ; CAC Counter Buffer Register

DOC:

.DOCR  = 0008_B080h ; DOC Control Register
.DODIR = 0008_B082h ; DOC Data Input Register
.DODSR = 0008_B084h ; DOC Data Setting Register

ELC:

.ELCR   = 0008_B100h ; Event Link Control Register
.ELSR0  = 0008_B101h ; Event Link Setting Register 0
.ELSR3  = 0008_B104h ; Event Link Setting Register 3
.ELSR4  = 0008_B105h ; Event Link Setting Register 4
.ELSR7  = 0008_B108h ; Event Link Setting Register 7
.ELSR10 = 0008_B10Bh ; Event Link Setting Register 10
.ELSR11 = 0008_B10Ch ; Event Link Setting Register 11
.ELSR12 = 0008_B10Dh ; Event Link Setting Register 12
.ELSR13 = 0008_B10Eh ; Event Link Setting Register 13
.ELSR15 = 0008_B110h ; Event Link Setting Register 15
.ELSR16 = 0008_B111h ; Event Link Setting Register 16
.ELSR18 = 0008_B113h ; Event Link Setting Register 18
.ELSR19 = 0008_B114h ; Event Link Setting Register 19
.ELSR20 = 0008_B115h ; Event Link Setting Register 20
.ELSR21 = 0008_B116h ; Event Link Setting Register 21
.ELSR22 = 0008_B117h ; Event Link Setting Register 22
.ELSR23 = 0008_B118h ; Event Link Setting Register 23
.ELSR24 = 0008_B119h ; Event Link Setting Register 24
.ELSR25 = 0008_B11Ah ; Event Link Setting Register 25
.ELSR26 = 0008_B11Bh ; Event Link Setting Register 26
.ELSR27 = 0008_B11Ch ; Event Link Setting Register 27
.ELSR28 = 0008_B11Dh ; Event Link Setting Register 28
.ELOPA  = 0008_B11Fh ; Event Link Option Setting Register A
.ELOPB  = 0008_B120h ; Event Link Option Setting Register B
.ELOPC  = 0008_B121h ; Event Link Option Setting Register C
.ELOPD  = 0008_B122h ; Event Link Option Setting Register D
.PGR1   = 0008_B123h ; Port Group Setting Register 1
.PGR2   = 0008_B124h ; Port Group Setting Register 2
.PGC1   = 0008_B125h ; Port Group Control Register 1
.PGC2   = 0008_B126h ; Port Group Control Register 2
.PDBF1  = 0008_B127h ; Port Buffer Register 1
.PDBF2  = 0008_B128h ; Port Buffer Register 2
.PEL0   = 0008_B129h ; Event Link Port Setting Register 0
.PEL1   = 0008_B12Ah ; Event Link Port Setting Register 1
.PEL2   = 0008_B12Bh ; Event Link Port Setting Register 2
.PEL3   = 0008_B12Ch ; Event Link Port Setting Register 3
.ELSEGR = 0008_B12Dh ; Event Link Software Event Generation Register
.ELSR33 = 0008_B131h ; Event Link Setting Register 33
.ELSR35 = 0008_B133h ; Event Link Setting Register 35
.ELSR36 = 0008_B134h ; Event Link Setting Register 36
.ELSR37 = 0008_B135h ; Event Link Setting Register 37
.ELSR38 = 0008_B136h ; Event Link Setting Register 38
.ELSR45 = 0008_B13Dh ; Event Link Setting Register 45
.ELOPF  = 0008_B13Fh ; Event Link Option Setting Register F
.ELOPH  = 0008_B141h ; Event Link Option Setting Register H
.ELSR48 = 0008_B146h ; Event Link Setting Register 48
.ELSR49 = 0008_B147h ; Event Link Setting Register 49
.ELSR50 = 0008_B148h ; Event Link Setting Register 50
.ELSR51 = 0008_B149h ; Event Link Setting Register 51
.ELSR52 = 0008_B14Ah ; Event Link Setting Register 52
.ELSR53 = 0008_B14Bh ; Event Link Setting Register 53
.ELSR54 = 0008_B14Ch ; Event Link Setting Register 54
.ELSR55 = 0008_B14Dh ; Event Link Setting Register 55
.ELSR56 = 0008_B14Eh ; Event Link Setting Register 56
.ELSR57 = 0008_B14Fh ; Event Link Setting Register 57

SCI12:

.SMR    = 0008_B300h ; Serial Mode Register
.BRR    = 0008_B301h ; Bit Rate Register
.SCR    = 0008_B302h ; Serial Control Register
.TDR    = 0008_B303h ; Transmit Data Register
.SSR    = 0008_B304h ; Serial Status Register
.RDR    = 0008_B305h ; Receive Data Register
.SCMR   = 0008_B306h ; Smart Card Mode Register
.SEMR   = 0008_B307h ; Serial Extended Mode Register
.SNFR   = 0008_B308h ; Noise Filter Setting Register
.SIMR1  = 0008_B309h ; I2C Mode Register 1
.SIMR2  = 0008_B30Ah ; I2C Mode Register 2
.SIMR3  = 0008_B30Bh ; I2C Mode Register 3
.SISR   = 0008_B30Ch ; I2C Status Register
.SPMR   = 0008_B30Dh ; SPI Mode Register
.TDRH   = 0008_B30Eh ; Transmit Data Register H
.TDRL   = 0008_B30Fh ; Transmit Data Register L
.TDRHL  = 0008_B30Eh ; Transmit Data Register HL
.RDRH   = 0008_B310h ; Receive Data Register H
.RDRL   = 0008_B311h ; Receive Data Register L
.RDRHL  = 0008_B310h ; Receive Data Register HL
.MDDR   = 0008_B312h ; Modulation Duty Register
.ESMER  = 0008_B320h ; Extended Serial Module Enable Register
.CR0    = 0008_B321h ; Control Register 0
.CR1    = 0008_B322h ; Control Register 1
.CR2    = 0008_B323h ; Control Register 2
.CR3    = 0008_B324h ; Control Register 3
.PCR    = 0008_B325h ; Port Control Register
.ICR    = 0008_B326h ; Interrupt Control Register
.STR    = 0008_B327h ; Status Register
.STCR   = 0008_B328h ; Status Clear Register
.CF0DR  = 0008_B329h ; Control Field 0 Data Register
.CF0CR  = 0008_B32Ah ; Control Field 0 Compare Enable Register
.CF0RR  = 0008_B32Bh ; Control Field 0 Receive Data Register
.PCF1DR = 0008_B32Ch ; Primary Control Field 1 Data Register
.SCF1DR = 0008_B32Dh ; Secondary Control Field 1 Data Register
.CF1CR  = 0008_B32Eh ; Control Field 1 Compare Enable Register
.CF1RR  = 0008_B32Fh ; Control Field 1 Receive Data Register
.TCR    = 0008_B330h ; Timer Control Register
.TMR    = 0008_B331h ; Timer Mode Register
.TPRE   = 0008_B332h ; Timer Prescaler Register
.TCNT   = 0008_B333h ; Timer Count Register

PORT0:

.PDR   = 0008_C000h ; Port Direction Register
.PODR  = 0008_C020h ; Port Output Data Register
.PIDR  = 0008_C040h ; Port Input Register
.PMR   = 0008_C060h ; Port Mode Register
.ODR0  = 0008_C080h ; Open-Drain Control Register 0
.ODR1  = 0008_C081h ; Open-Drain Control Register 1
.PCR   = 0008_C0C0h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0E0h ; Drive Capacity Control Register
.DSCR2 = 0008_C128h ; Drive Capacity Control  2

PORT1:

.PDR   = 0008_C001h ; Port Direction Register
.PODR  = 0008_C021h ; Port Output Data Register
.PIDR  = 0008_C041h ; Port Input Register
.PMR   = 0008_C061h ; Port Mode Register
.ODR0  = 0008_C082h ; Open-Drain Control Register 0
.ODR1  = 0008_C083h ; Open-Drain Control Register 1
.PCR   = 0008_C0C1h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0E1h ; Drive Capacity Control Register
.DSCR2 = 0008_C129h ; Drive Capacity Control Register 2

PORT2:

.PDR   = 0008_C002h ; Port Direction Register
.PODR  = 0008_C022h ; Port Output Data Register
.PIDR  = 0008_C042h ; Port Input Register
.PMR   = 0008_C062h ; Port Mode Register
.ODR0  = 0008_C084h ; Open-Drain Control Register 0
.ODR1  = 0008_C085h ; Open-Drain Control Register 1
.PCR   = 0008_C0C2h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0E2h ; Drive Capacity Control Register
.DSCR2 = 0008_C12Ah ; Drive Capacity Control Register 2

Port3:

.PDR   = 0008_C003h ; Port Direction Register
.PODR  = 0008_C023h ; Port Output Data Register
.PIDR  = 0008_C043h ; Port Input Register
.PMR   = 0008_C063h ; Port Mode Register
.ODR0  = 0008_C086h ; Open-Drain Control Register 0
.ODR1  = 0008_C087h ; Open-Drain Control Register 1
.PCR   = 0008_C0C3h ; Pull-Up Resistor Control Register
.DSCR2 = 0008_C12Bh ; Drive Capacity Control Register 2

PORT4:

.PDR  = 0008_C004h ; Port Direction Register
.PODR = 0008_C024h ; Port Output Data Register
.PIDR = 0008_C044h ; Port Input Register
.PMR  = 0008_C064h ; Port Mode Register
.ODR0 = 0008_C088h ; Open-Drain Control Register 0
.ODR1 = 0008_C089h ; Open-Drain Control Register 1
.PCR  = 0008_C0C4h ; Pull-Up Resistor Control Register

PORT5:

.PDR   = 0008_C005h ; Port Direction Register
.PODR  = 0008_C025h ; Port Output Data Register
.PIDR  = 0008_C045h ; Port Input Register
.PMR   = 0008_C065h ; Port Mode Register
.ODR0  = 0008_C08Ah ; Open-Drain Control Register 0
.ODR1  = 0008_C08Bh ; Open-Drain Control Register 1
.PCR   = 0008_C0C5h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0E5h ; Drive Capacity Control Register
.DSCR2 = 0008_C12Dh; Drive Capacity Control Register 2

PORT6:

.PDR   = 0008_C006h ; Port Direction Register
.PODR  = 0008_C026h ; Port Output Data Register
.PIDR  = 0008_C046h ; Port Input Register
.PMR   = 0008_C066h ; Port Mode Register
.ODR0  = 0008_C08Ch ; Open-Drain Control Register 0
.ODR1  = 0008_C08Dh ; Open-Drain Control Register 1
.PCR   = 0008_C0C6h ; Pull-Up Resistor Control Register
.DSCR2 = 0008_C12Eh ; Drive Capacity Control Register 2

PORT7:

.PDR   = 0008_C007h ; Port Direction Register
.PODR  = 0008_C027h ; Port Output Data Register
.PIDR  = 0008_C047h ; Port Input Register
.PMR   = 0008_C067h ; Port Mode Register
.ODR0  = 0008_C08Eh ; Open-Drain Control Register 0
.ODR1  = 0008_C08Fh ; Open-Drain Control Register 1
.PCR   = 0008_C0C7h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0E7h ; Drive Capacity Control Register
.DSCR2 = 0008_C12Fh ; Drive Capacity Control Register 2

PORT8:

.PDR   = 0008_C008h ; Port Direction Register
.PODR  = 0008_C028h ; Port Output Data Register
.PIDR  = 0008_C048h ; Port Input Register
.PMR   = 0008_C068h ; Port Mode Register
.ODR0  = 0008_C090h ; Open-Drain Control Register 0
.ODR1  = 0008_C091h ; Open-Drain Control Register 1
.PCR   = 0008_C0C8h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0E8h ; Drive Capacity Control Register
.DSCR2 = 0008_C130h ; Drive Capacity Control Register 2

PORT9:

.PDR   = 0008_C009h ; Port Direction Register
.PODR  = 0008_C029h ; Port Output Data Register
.PIDR  = 0008_C049h ; Port Input Register
.PMR   = 0008_C069h ; Port Mode Register
.ODR0  = 0008_C092h ; Open-Drain Control Register 0
.ODR1  = 0008_C093h ; Open-Drain Control Register 1
.PCR   = 0008_C0C9h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0E9h ; Drive Capacity Control Register
.DSCR2 = 0008_C131h ; Drive Capacity Control Register 2

PORTA:

.PDR   = 0008_C00Ah ; Port Direction Register
.PODR  = 0008_C02Ah ; Port Output Data Register
.PIDR  = 0008_C04Ah ; Port Input Register
.PMR   = 0008_C06Ah ; Port Mode Register
.ODR0  = 0008_C094h ; Open-Drain Control Register 0
.ODR1  = 0008_C095h ; Open-Drain Control Register 1
.PCR   = 0008_C0CAh ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0EAh ; Drive Capacity Control Register
.DSCR2 = 0008_C132h ; Drive Capacity Control Register 2

PORTB:

.PDR   = 0008_C00Bh ; Port Direction Register
.PODR  = 0008_C02Bh ; Port Output Data Register
.PIDR  = 0008_C04Bh ; Port Input Register
.PMR   = 0008_C06Bh ; Port Mode Register
.ODR0  = 0008_C096h ; Open-Drain Control Register 0
.ODR1  = 0008_C097h ; Open-Drain Control Register 1
.PCR   = 0008_C0CBh ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0EBh ; Drive Capacity Control Register
.DSCR2 = 0008_C133h; Drive Capacity Control Register 2

PORTC:

.PDR   = 0008_C00Ch ; Port Direction Register
.PODR  = 0008_C02Ch ; Port Output Data Register
.PIDR  = 0008_C04Ch ; Port Input Register
.PMR   = 0008_C06Ch ; Port Mode Register
.ODR0  = 0008_C098h ; Open-Drain Control Register 0
.ODR1  = 0008_C099h ; Open-Drain Control Register 1
.PCR   = 0008_C0CCh ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0ECh ; Drive Capacity Control Register
.DSCR2 = 0008_C134h; Drive Capacity Control Register 2

PORTD:

.PDR   = 0008_C00Dh ; Port Direction Register
.PODR  = 0008_C02Dh ; Port Output Data Register
.PIDR  = 0008_C04Dh ; Port Input Register
.PMR   = 0008_C06Dh ; Port Mode Register
.ODR0  = 0008_C09Ah ; Open-Drain Control Register 0
.ODR1  = 0008_C09Bh ; Open-Drain Control Register 1
.PCR   = 0008_C0CDh ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0EDh ; Drive Capacity Control Register
.DSCR2 = 0008_C135h; Drive Capacity Control Register 2

PORTE:

.PDR   = 0008_C00Eh ; Port Direction Register
.PODR  = 0008_C02Eh ; Port Output Data Register
.PIDR  = 0008_C04Eh ; Port Input Register
.PMR   = 0008_C06Eh ; Port Mode Register
.ODR0  = 0008_C09Ch ; Open-Drain Control Register 0
.ODR1  = 0008_C09Dh ; Open-Drain Control Register 1
.PCR   = 0008_C0CEh ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0EEh ; Drive Capacity Control Register
.DSCR2 = 0008_C136h; Drive Capacity Control Register 2

PORTF:

.PDR  = 0008_C00Fh ; Port Direction Register
.PODR = 0008_C02Fh ; Port Output Data Register
.PIDR = 0008_C04Fh ; Port Input Register
.PMR  = 0008_C06Fh ; Port Mode Register
.ODR0 = 0008_C09Eh ; Open-Drain Control Register 0
.ODR1 = 0008_C09Fh ; Open-Drain Control Register 1
.PCR  = 0008_C0CFh ; Pull-Up Resistor Control Register

PORTG:

.PDR   = 0008_C010h ; Port Direction Register
.PODR  = 0008_C030h ; Port Output Data Register
.PIDR  = 0008_C050h ; Port Input Register
.PMR   = 0008_C070h ; Port Mode Register
.ODR0  = 0008_C0A0h ; Open-Drain Control Register 0
.ODR1  = 0008_C0A1h ; Open-Drain Control Register 1
.PCR   = 0008_C0D0h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0F0h ; Drive Capacity Control Register
.DSCR2 = 0008_C138h; Drive Capacity Control Register 2

PORTH:

.PDR   = 0008_C011h ; Port Direction Register
.PODR  = 0008_C031h ; Port Output Data Register
.PIDR  = 0008_C051h ; Port Input Register
.PMR   = 0008_C071h ; Port Mode Register
.ODR0  = 0008_C0A2h ; Open-Drain Control Register 0
.ODR1  = 0008_C0A3h ; Open-Drain Control Register 1
.PCR   = 0008_C0D1h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0F1h ; Drive Capacity Control Register
.DSCR2 = 0008_C139h; Drive Capacity Control Register 2

PORTJ:

.PDR   = 0008_C012h ; Port Direction 
.PODR  = 0008_C032h ; Port Output Data Register
.PIDR  = 0008_C052h ; Port Input Register
.PMR   = 0008_C072h ; Port Mode Register
.ODR0  = 0008_C0A4h ; Open-Drain Control Register 0
.ODR1  = 0008_C0A5h ; Open-Drain Control Register 1
.PCR   = 0008_C0D2h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0F2h ; Drive Capacity Control Register
.DSCR2 = 0008_C13Ah; Drive Capacity Control Register 2

PORTK:

.PDR   = 0008_C013h ; Port Direction Register
.PODR  = 0008_C033h ; Port Output Data Register
.PIDR  = 0008_C053h ; Port Input Register
.PMR   = 0008_C073h ; Port Mode Register
.ODR0  = 0008_C0A6h ; Open-Drain Control Register 0
.ODR1  = 0008_C0A7h ; Open-Drain Control Register 1
.PCR   = 0008_C0D3h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0F3h ; Drive Capacity Control Register
.DSCR2 = 0008_C13Bh; Drive Capacity Control Register 2

PORTL:

.PDR   = 0008_C014h ; Port Direction Register
.PODR  = 0008_C034h ; Port Output Data Register
.PIDR  = 0008_C054h ; Port Input Register
.PMR   = 0008_C074h ; Port Mode Register
.ODR0  = 0008_C0A8h ; Open-Drain Control Register 0
.ODR1  = 0008_C0A9h ; Open-Drain Control Register 1
.PCR   = 0008_C0D4h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0F4h ; Drive Capacity Control Register
.DSCR2 = 0008_C13Ch; Drive Capacity Control Register 2

PORTM:

.PDR   = 0008_C015h ; Port Direction Register
.PODR  = 0008_C035h ; Port Output Data Register
.PIDR  = 0008_C055h ; Port Input Register
.PMR   = 0008_C075h ; Port Mode Register
.ODR0  = 0008_C0AAh ; Open-Drain Control Register 0
.ODR1  = 0008_C0ABh ; Open-Drain Control Register 1
.PCR   = 0008_C0D5h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0F5h ; Drive Capacity Control Register
.DSCR2 = 0008_C13Dh; Drive Capacity Control Register 2

PORTN:

.PDR   = 0008_C016h ; Port Direction Register
.PODR  = 0008_C036h ; Port Output Data Register
.PIDR  = 0008_C056h ; Port Input Register
.PMR   = 0008_C076h ; Port Mode Register
.ODR0  = 0008_C0ACh ; Open-Drain Control Register 0
.ODR1  = 0008_C0ADh ; Open-Drain Control Register 1
.PCR   = 0008_C0D6h ; Pull-Up Resistor Control Register
.DSCR  = 0008_C0F6h ; Drive Capacity Control Register
.DSCR2 = 0008_C13Eh; Drive Capacity Control Register 2

PORTQ:

.PDR   = 0008_C017h ; Port Direction Register
.PODR  = 0008_C037h ; Port Output Data Register
.PIDR  = 0008_C057h ; Port Input Register
.PMR   = 0008_C077h ; Port Mode Register
.ODR0  = 0008_C0AEh ; Open-Drain Control Register 0
.ODR1  = 0008_C0AFh ; Open-Drain Control Register 1
.PCR   = 008_C0D7h ; Pull-Up Resistor Control Register
.DSCR  = 008_C0F7h ; Drive Capacity Control Register
.DSCR2 = 0008_C13Fh; Drive Capacity Control Register 2

MPC:

.PFCSE  = 0008_C100h ; CS Output Enable Register
.PFCSS0 = 0008_C102h ; CS Output Pin Select Register 0
.PFCSS1 = 0008_C103h ; CS Output Pin Select Register 1
.PFAOE0 = 0008_C104h ; Address Output Enable Register 0
.PFAOE1 = 0008_C105h ; Address Output Enable Register 1
.PFBCR0 = 0008_C106h ; External Bus Control Register 0
.PFBCR1 = 0008_C107h ; External Bus Control Register 1
.PFBCR2 = 0008_C108h ; External Bus Control Register 2
.PFBCR3 = 0008_C109h ; External Bus Control Register 3
.PFENET = 0008_C10Eh ; Ethernet Control Register
.PWPR   = 0008_C11Fh ; Write-Protect Register
.P00PFS = 0008_C140h ; P00 Pin Function Control Register
.P01PFS = 0008_C141h ; P01 Pin Function Control Register
.P02PFS = 0008_C142h ; P02 Pin Function Control Register
.P03PFS = 0008_C143h ; P03 Pin Function Control Register
.P05PFS = 0008_C145h ; P05 Pin Function Control Register
.P07PFS = 0008_C147h ; P07 Pin Function Control Register
.P10PFS = 0008_C148h ; P10 Pin Function Control Register
.P11PFS = 0008_C149h ; P11 Pin Function Control Register
.P12PFS = 0008_C14Ah ; P12 Pin Function Control Register
.P13PFS = 0008_C14Bh ; P13 Pin Function Control Register
.P14PFS = 0008_C14Ch ; P14 Pin Function Control Register
.P15PFS = 0008_C14Dh ; P15 Pin Function Control Register
.P16PFS = 0008_C14Eh ; P16 Pin Function Control Register
.P17PFS = 0008_C14Fh ; P17 Pin Function Control Register
.P20PFS = 0008_C150h ; P20 Pin Function Control Register
.P21PFS = 0008_C151h ; P21 Pin Function Control Register
.P22PFS = 0008_C152h ; P22 Pin Function Control Register
.P23PFS = 0008_C153h ; P23 Pin Function Control Register
.P24PFS = 0008_C154h ; P24 Pin Function Control Register
.P25PFS = 0008_C155h ; P25 Pin Function Control Register
.P26PFS = 0008_C156h ; P26 Pin Function Control Register
.P27PFS = 0008_C157h ; P27 Pin Function Control Register
.P30PFS = 0008_C158h ; P30 Pin Function Control Register
.P31PFS = 0008_C159h ; P31 Pin Function Control Register
.P32PFS = 0008_C15Ah ; P32 Pin Function Control Register
.P33PFS = 0008_C15Bh ; P33 Pin Function Control Register
.P34PFS = 0008_C15Ch ; P34 Pin Function Control Register
.P40PFS = 0008_C160h ; P40 Pin Function Control Register
.P41PFS = 0008_C161h ; P41 Pin Function Control Register
.P42PFS = 0008_C162h ; P42 Pin Function Control Register
.P43PFS = 0008_C163h ; P43 Pin Function Control Register
.P44PFS = 0008_C164h ; P44 Pin Function Control Register
.P45PFS = 0008_C165h ; P45 Pin Function Control Register
.P46PFS = 0008_C166h ; P46 Pin Function Control Register
.P47PFS = 0008_C167h ; P47 Pin Function Control Register
.P50PFS = 0008_C168h ; P50 Pin Function Control Register
.P51PFS = 0008_C169h ; P51 Pin Function Control Register
.P52PFS = 0008_C16Ah ; P52 Pin Function Control Register
.P54PFS = 0008_C16Ch ; P54 Pin Function Control Register
.P55PFS = 0008_C16Dh ; P55 Pin Function Control Register
.P56PFS = 0008_C16Eh ; P56 Pin Function Control Register
.P57PFS = 0008_C16Fh ; P57 Pin Function Control Register
.P60PFS = 0008_C170h ; P60 Pin Function Control Register
.P61PFS = 0008_C171h ; P61 Pin Function Control Register
.P62PFS = 0008_C172h ; P62 Pin Function Control Register
.P63PFS = 0008_C173h ; P63 Pin Function Control Register
.P64PFS = 0008_C174h ; P64 Pin Function Control Register
.P66PFS = 0008_C176h ; P66 Pin Function Control Register
.P67PFS = 0008_C177h ; P67 Pin Function Control Register
.P71PFS = 0008_C179h ; P71 Pin Function Control Register
.P72PFS = 0008_C17Ah ; P72 Pin Function Control Register
.P73PFS = 0008_C17Bh ; P73 Pin Function Control Register
.P74PFS = 0008_C17Ch ; P74 Pin Function Control Register
.P75PFS = 0008_C17Dh ; P75 Pin Function Control Register
.P76PFS = 0008_C17Eh ; P76 Pin Function Control Register
.P77PFS = 0008_C17Fh ; P77 Pin Function Control Register
.P80PFS = 0008_C180h ; P80 Pin Function Control Register
.P81PFS = 0008_C181h ; P81 Pin Function Control Register
.P82PFS = 0008_C182h ; P82 Pin Function Control Register
.P83PFS = 0008_C183h ; P83 Pin Function Control Register
.P84PFS = 0008_C184h ; P84 Pin Function Control Register
.P85PFS = 0008_C185h ; P85 Pin Function Control Register
.P86PFS = 0008_C186h ; P86 Pin Function Control Register
.P87PFS = 0008_C187h ; P87 Pin Function Control Register
.P90PFS = 0008_C188h ; P90 Pin Function Control Register
.P91PFS = 0008_C189h ; P91 Pin Function Control Register
.P92PFS = 0008_C18Ah ; P92 Pin Function Control Register
.P93PFS = 0008_C18Bh ; P93 Pin Function Control Register
.P94PFS = 0008_C18Ch ; P94 Pin Function Control Register
.P95PFS = 0008_C18Dh ; P95 Pin Function Control Register
.P96PFS = 0008_C18Eh ; P96 Pin Function Control Register
.P97PFS = 0008_C18Fh ; P97 Pin Function Control Register
.PA0PFS = 0008_C190h ; PA0 Pin Function Control Register
.PA1PFS = 0008_C191h ; PA1 Pin Function Control Register
.PA2PFS = 0008_C192h ; PA2 Pin Function Control Register
.PA3PFS = 0008_C193h ; PA3 Pin Function Control Register
.PA4PFS = 0008_C194h ; PA4 Pin Function Control Register
.PA5PFS = 0008_C195h ; PA5 Pin Function Control Register
.PA6PFS = 0008_C196h ; PA6 Pin Function Control Register
.PA7PFS = 0008_C197h ; PA7 Pin Function Control Register
.PB0PFS = 0008_C198h ; PB0 Pin Function Control Register
.PB1PFS = 0008_C199h ; PB1 Pin Function Control Register
.PB2PFS = 0008_C19Ah ; PB2 Pin Function Control Register
.PB3PFS = 0008_C19Bh ; PB3 Pin Function Control Register
.PB4PFS = 0008_C19Ch ; PB4 Pin Function Control Register
.PB5PFS = 0008_C19Dh ; PB5 Pin Function Control Register
.PB6PFS = 0008_C19Eh ; PB6 Pin Function Control Register
.PB7PFS = 0008_C19Fh ; PB7 Pin Function Control Register
.PC0PFS = 0008_C1A0h ; PC0 Pin Function Control Register
.PC1PFS = 0008_C1A1h ; PC1 Pin Function Control Register
.PC2PFS = 0008_C1A2h ; PC2 Pin Function Control Register
.PC3PFS = 0008_C1A3h ; PC3 Pin Function Control Register
.PC4PFS = 0008_C1A4h ; PC4 Pin Function Control Register
.PC5PFS = 0008_C1A5h ; PC5 Pin Function Control Register
.PC6PFS = 0008_C1A6h ; PC6 Pin Function Control Register
.PC7PFS = 0008_C1A7h ; PC7 Pin Function Control Register
.PD0PFS = 0008_C1A8h ; PD0 Pin Function Control Register
.PD1PFS = 0008_C1A9h ; PD1 Pin Function Control Register
.PD2PFS = 0008_C1AAh ; PD2 Pin Function Control Register
.PD3PFS = 0008_C1ABh ; PD3 Pin Function Control Register
.PD4PFS = 0008_C1ACh ; PD4 Pin Function Control Register
.PD5PFS = 0008_C1ADh ; PD5 Pin Function Control Register
.PD6PFS = 0008_C1AEh ; PD6 Pin Function Control Register
.PD7PFS = 0008_C1AFh ; PD7 Pin Function Control Register
.PE0PFS = 0008_C1B0h ; PE0 Pin Function Control Register
.PE1PFS = 0008_C1B1h ; PE1 Pin Function Control Register
.PE2PFS = 0008_C1B2h ; PE2 Pin Function Control Register
.PE3PFS = 0008_C1B3h ; PE3 Pin Function Control Register
.PE4PFS = 0008_C1B4h ; PE4 Pin Function Control Register
.PE5PFS = 0008_C1B5h ; PE5 Pin Function Control Register
.PE6PFS = 0008_C1B6h ; PE6 Pin Function Control Register
.PE7PFS = 0008_C1B7h ; PE7 Pin Function Control Register
.PF0PFS = 0008_C1B8h ; PF0 Pin Function Control Register
.PF1PFS = 0008_C1B9h ; PF1 Pin Function Control Register
.PF2PFS = 0008_C1BAh ; PF2 Pin Function Control Register
.PF5PFS = 0008_C1BDh ; PF5 Pin Function Control Register
.PG0PFS = 0008_C1C0h ; PG0 Pin Function Control Register
.PG1PFS = 0008_C1C1h ; PG1 Pin Function Control Register
.PG2PFS = 0008_C1C2h ; PG2 Pin Function Control Register
.PG3PFS = 0008_C1C3h ; PG3 Pin Function Control Register
.PG4PFS = 0008_C1C4h ; PG4 Pin Function Control Register
.PG5PFS = 0008_C1C5h ; PG5 Pin Function Control Register
.PG6PFS = 0008_C1C6h ; PG6 Pin Function Control Register
.PG7PFS = 0008_C1C7h ; PG7 Pin Function Control Register
.PH0PFS = 0008_C1C8h ; PH0 Pin Function Control Register
.PH1PFS = 0008_C1C9h ; PH1 Pin Function Control Register
.PH2PFS = 0008_C1CAh ; PH2 Pin Function Control Register
.PH3PFS = 0008_C1CBh ; PH3 Pin Function Control Register
.PH4PFS = 0008_C1CCh ; PH4 Pin Function Control Register
.PH5PFS = 0008_C1CDh ; PH5 Pin Function Control Register
.PH6PFS = 0008_C1CEh ; PH6 Pin Function Control Register
.PH7PFS = 0008_C1CFh ; PH7 Pin Function Control Register
.PJ0PFS = 0008_C1D0h ; PJ0 Pin Function Control Register
.PJ1PFS = 0008_C1D1h ; PJ1 Pin Function Control Register
.PJ2PFS = 0008_C1D2h ; PJ2 Pin Function Control Register
.PJ3PFS = 0008_C1D3h ; PJ3 Pin Function Control Register
.PJ5PFS = 0008_C1D5h ; PJ5 Pin Function Control Register
.PK0PFS = 0008_C1D8h ; PK0 Pin Function Control Register
.PK1PFS = 0008_C1D9h ; PK1 Pin Function Control Register
.PK2PFS = 0008_C1DAh ; PK2 Pin Function Control Register
.PK3PFS = 0008_C1DBh ; PK3 Pin Function Control Register
.PK4PFS = 0008_C1DCh ; PK4 Pin Function Control Register
.PK5PFS = 0008_C1DDh ; PK5 Pin Function Control Register
.PK6PFS = 0008_C1DEh ; PK6 Pin Function Control Register
.PK7PFS = 0008_C1DFh ; PK7 Pin Function Control Register
.PL0PFS = 0008_C1E0h ; PL0 Pin Function Control Register
.PL1PFS = 0008_C1E1h ; PL1 Pin Function Control Register
.PL2PFS = 0008_C1E2h ; PL2 Pin Function Control Register
.PL3PFS = 0008_C1E3h ; PL3 Pin Function Control Register
.PL4PFS = 0008_C1E4h ; PL4 Pin Function Control Register
.PL5PFS = 0008_C1E5h ; PL5 Pin Function Control Register
.PL6PFS = 0008_C1E6h ; PL6 Pin Function Control Register
.PL7PFS = 0008_C1E7h ; PL7 Pin Function Control Register
.PM0PFS = 0008_C1E8h ; PM0 Pin Function Control Register
.PM1PFS = 0008_C1E9h ; PM1 Pin Function Control Register
.PM2PFS = 0008_C1EAh ; PM2 Pin Function Control Register
.PM3PFS = 0008_C1EBh ; PM3 Pin Function Control Register
.PM4PFS = 0008_C1ECh ; PM4 Pin Function Control Register
.PM5PFS = 0008_C1EDh ; PM5 Pin Function Control Register
.PM6PFS = 0008_C1EEh ; PM6 Pin Function Control Register
.PM7PFS = 0008_C1EFh ; PM7 Pin Function Control Register
.PN0PFS = 0008_C1F0h ; PN0 Pin Function Control Register
.PN1PFS = 0008_C1F1h ; PN1 Pin Function Control Register
.PN2PFS = 0008_C1F2h ; PN2 Pin Function Control Register
.PN3PFS = 0008_C1F3h ; PN3 Pin Function Control Register
.PN4PFS = 0008_C1F4h ; PN4 Pin Function Control Register
.PN5PFS = 0008_C1F5h ; PN5 Pin Function Control Register
.PQ0PFS = 0008_C1F8h ; PQ0 Pin Function Control Register
.PQ1PFS = 0008_C1F9h ; PQ1 Pin Function Control Register
.PQ2PFS = 0008_C1FAh ; PQ2 Pin Function Control Register
.PQ3PFS = 0008_C1FBh ; PQ3 Pin Function Control Register
.PQ4PFS = 0008_C1FCh ; PQ4 Pin Function Control Register
.PQ5PFS = 0008_C1FDh ; PQ5 Pin Function Control Register
.PQ6PFS = 0008_C1FEh ; PQ6 Pin Function Control Register
.PQ7PFS = 0008_C1FFh ; PQ7 Pin Function Control Register

RTC:

.R64CNT   = 0008_C400h ; 64-Hz Counter
.RSECCNT  = 0008_C402h ; Second Counter
.BCNT0    = 0008_C402h ; Binary Counter 0
.RMINCNT  = 0008_C404h ; Minute Counter
.BCNT1    = 0008_C404h ; Binary Counter 1
.RHRCNT   = 0008_C406h ; Hour Counter
.BCNT2    = 0008_C406h ; Binary Counter 2
.RWKCNT   = 0008_C408h ; Day-of-Week Counter
.BCNT3    = 0008_C408h ; Binary Counter 3
.RDAYCNT  = 0008_C40Ah ; Date Counter
.RMONCNT  = 0008_C40Ch ; Month Counter
.RYRCNT   = 0008_C40Eh ; Year Counter
.RSECAR   = 0008_C410h ; Second Alarm Register
.BCNT0AR  = 0008_C410h ; Binary Counter 0 Alarm Register
.RMINAR   = 0008_C412h ; Minute Alarm Register
.BCNT1AR  = 0008_C412h ; Binary Counter 1 Alarm Register
.RHRAR    = 0008_C414h ; Hour Alarm Register
.BCNT2AR  = 0008_C414h ; Binary Counter 2 Alarm Register
.RWKAR    = 0008_C416h ; Day-of-Week Alarm Register
.BCNT3AR  = 0008_C416h ; Binary Counter 3 Alarm Register
.RDAYAR   = 0008_C418h ; Date Alarm Register
.BCNT0AER = 0008_C418h ; Binary Counter 0 Alarm Enable Register
.RMONAR   = 0008_C41Ah ; Month Alarm Register
.BCNT1AER = 0008_C41Ah ; Binary Counter 1 Alarm Enable Register
.RYRAR    = 0008_C41Ch ; Year Alarm Register
.BCNT2AER = 0008_C41Ch ; Binary Counter 2 Alarm Enable Register
.RYRAREN  = 0008_C41Eh ; Year Alarm Enable Register
.BCNT3AER = 0008_C41Eh ; Binary Counter 3 Alarm Enable Register
.RCR1     = 0008_C422h ; RTC Control Register 1
.RCR2     = 0008_C424h ; RTC Control Register 2
.RCR3     = 0008_C426h ; RTC Control Register 3
.RCR4     = 0008_C428h ; RTC Control Register 4
.RFRH     = 0008_C42Ah ; Frequency Register H
.RFRL     = 0008_C42Ch ; Frequency Register L
.RADJ     = 0008_C42Eh ; Time Error Adjustment Register
.RTCCR0   = 0008_C440h ; Time Capture Control Register 0
.RTCCR1   = 0008_C442h ; Time Capture Control Register 1
.RTCCR2   = 0008_C444h ; Time Capture Control Register 2
.RSECCP0  = 0008_C452h ; Second Capture Register 0
.BCNT0CP0 = 0008_C452h ; BCNT0 Capture Register 0
.RMINCP0  = 0008_C454h ; Minute Capture Register 0
.BCNT1CP0 = 0008_C454h ; BCNT1 Capture Register 0
.RHRCP0   = 0008_C456h ; Hour Capture Register 0
.BCNT2CP0 = 0008_C456h ; BCNT2 Capture Register 0
.RDAYCP0  = 0008_C45Ah ; Date Capture Register 0
.BCNT3CP0 = 0008_C45Ah ; BCNT3 Capture Register 0
.RMONCP0  = 0008_C45Ch ; Month Capture Register 0
.RSECCP1  = 0008_C462h ; Second Capture Register 1
.BCNT0CP1 = 0008_C462h ; BCNT0 Capture Register 1
.RMINCP1  = 0008_C464h ; Minute Capture Register 1
.BCNT1CP1 = 0008_C464h ; BCNT1 Capture Register 1
.RHRCP1   = 0008_C466h ; Hour Capture Register 1
.BCNT2CP1 = 0008_C466h ; BCNT2 Capture Register 1
.RDAYCP1  = 0008_C46Ah ; Date Capture Register 1
.BCNT3CP1 = 0008_C46Ah ; BCNT3 Capture Register 1
.RMONCP1  = 0008_C46Ch ; Month Capture Register 1
.RSECCP2  = 0008_C472h ; Second Capture Register 2
.BCNT0CP2 = 0008_C472h ; BCNT0 Capture Register 2
.RMINCP2  = 0008_C474h ; Minute Capture Register 2
.BCNT1CP2 = 0008_C474h ; BCNT1 Capture Register 2
.RHRCP2   = 0008_C476h ; Hour Capture Register 2
.BCNT2CP2 = 0008_C476h ; BCNT2 Capture Register 2
.RDAYCP2  = 0008_C47Ah ; Date Capture Register 2
.BCNT3CP2 = 0008_C47Ah ; BCNT3 Capture Register 2
.RMONCP2  = 0008 C47C_ ; Month Capture Register 2

POE3:

.ICSR1   = 0008_C4C0h ; Input Level Control/Status Register 1
.OCSR1   = 0008_C4C2h ; Output Level Control/Status Register 1
.ICSR2   = 0008_C4C4h ; Input Level Control/Status Register 2
.OCSR2   = 0008_C4C6h ; Output Level Control/Status Register 2
.ICSR3   = 0008_C4C8h ; Input Level Control/Status Register 3
.SPOER   = 0008_C4CAh ; Software Port Output Enable Register
.POECR1  = 0008_C4CBh ; Port Output Enable Control Register 1
.POECR2  = 0008_C4CCh ; Port Output Enable Control Register 2
.POECR4  = 0008_C4D0h ; Port Output Enable Control Register 4
.POECR5  = 0008_C4D2h ; Port Output Enable Control Register 5
.ICSR4   = 0008_C4D6h ; Input Level Control/Status Register 4
.ICSR5   = 0008_C4D8h ; Input Level Control/Status Register 5
.ALR1    = 0008_C4DAh ; Active Level Setting Register 1
.ICSR6   = 0008_C4DCh ; Input Level Control/Status Register 6
.M0SELR1 = 0008_C4E4h ; MTU0 Pin Select Register 1
.M0SELR2 = 0008_C4E5h ; MTU0 Pin Select Register 2
.M3SELR  = 0008_C4E6h ; MTU3 Pin Select Register
.M4SELR1 = 0008_C4E7h ; MTU4 Pin Select Register 1
.M4SELR2 = 0008_C4E8h ; MTU4 Pin Select Register 2
.M6SELR  = 0008_C4EAh ; MTU6 Pin Select Register

TEMPS:

TSCR  = 0008 C500h ; Temperature Sensor Control Register
TSCDR = FE7F_7D7Ch ; Temperature Sensor Calibration Data Register

DA:

.DAADUSR = 0008 C5C0h ; D/A A/D Synchronous Unit Select Register

CAN0:

;0009_0200h to 0009_03FFh
;Mailbox Register 0 to 31
;MB0 to MB31

.repeat 32, i:0
   .MB#i = 0009_0200h + 10h * i
end repeat

;0009_0400h to 0009_041Fh
;Mask Register 0 to 7
;MKR0 to MKR7

repeat 8, i:0
   .MKR#i = 0009_0400h + 04h * i
end repeat

.FIDCR0 = 0009_0420h ; FIFO Received ID Compare Register 0
.FIDCR1 = 0009_0424h ; FIFO Received ID Compare Register 1
.MKIVLR = 0009_0428h ; Mask Invalid Register
.MIER   = 0009_042Ch ; Mailbox Interrupt Enable Register

;0009_0820h to 0009_083Fh
;Message Control Register 0 to 31
;MCTL0 to MCTL31

repeat 32, i:0
   .MCTL#i = 0009_0820h + i
end repeat


.CTLR  = 0009_0840h ;Control Register
.STR   = 0009_0842h ;Status Register
.BCR   = 0009_0844h ;Bit Configuration Register
.RFCR  = 0009_0848h ; Receive FIFO Control Register
.RFPCR = 0009_0849h ; Receive FIFO Pointer Control Register
.TFCR  = 0009_084Ah ; Transmit FIFO Control Register
.TFPCR = 0009_084Bh ; Transmit FIFO Pointer Control Register
.EIER  = 0009_084Ch ; Error Interrupt Enable Register
.EIFR  = 0009_084Dh ; Error Interrupt Factor Judge Register
.RECR  = 0009_084Eh ; Receive Error Count Register
.TECR  = 0009_084Fh ; Transmit Error Count Register
.ECSR  = 0009_0850h ; Error Code Store Register
.CSSR  = 0009_0851h ; Channel Search Support Register
.MSSR  = 0009_0852h ; Mailbox Search Status Register
.MSMR  = 0009_0853h ; Mailbox Search Mode Register
.TSR   = 0009_0854h ; Time Stamp Register
.AFSR  = 0009_0856h ; Acceptance Filter Support Register
.TCR   = 0009_0858h ; Test Control Register

CAN1:

;0009_1200h to 0009_13FFh
;Mailbox Register 0 to 31
;MB0 to MB31

repeat 32, i:0
   .MB#i = 0009_1200h + 10h * i
end repeat

;0009_1400h to 0009_141Fh
;Mask Register 0 to 7
;MKR0 to MKR7

repeat 8, i:0
   .MKR#i = 0009_1400h + 04h * i
end repeat

.FIDCR0 = 0009_1420h ; FIFO Received ID Compare Register 0
.FIDCR1 = 0009_1424h ; FIFO Received ID Compare Register 1
.MKIVLR = 0009_1428h ; Mask Invalid Register
.MIER   = 0009_142Ch ; Mailbox Interrupt Enable Register

;0009_1820h to 0009_183Fh
;Message Control Register 0 to 31
;MCTL0 to MCTL31

repeat 32, i:0
   .MCTL#i = 0009_1820h + i
end repeat

.CTLR  = 0009_1840h ; Control Register
.STR   = 0009_1842h ; Status Register
.BCR   = 0009_1844h ; Bit Configuration Register
.RFCR  = 0009_1848h ; Receive FIFO Control Register
.RFPCR = 0009_1849h ; Receive FIFO Pointer Control Register
.TFCR  = 0009_184Ah ; Transmit FIFO Control Register
.TFPCR = 0009_184Bh ; Transmit FIFO Pointer Control Register
.EIER  = 0009_184Ch ; Error Interrupt Enable Register
.EIFR  = 0009_184Dh ; Error Interrupt Factor Judge Register
.RECR  = 0009_184Eh ; Receive Error Count Register
.TECR  = 0009_184Fh ; Transmit Error Count Register
.ECSR  = 0009_1850h ; Error Code Store Register
.CSSR  = 0009_1851h ; Channel Search Support Register
.MSSR  = 0009_1852h ; Mailbox Search Status Register
.MSMR  = 0009_1853h ; Mailbox Search Mode Register
.TSR   = 0009_1854h ; Time Stamp Register
.AFSR  = 0009_1856h ; Acceptance Filter Support Register
.TCR   = 0009_1858h ; Test Control Register

CAN2:

;0009_2200h to 0009_23FFh
;Mailbox Register 0 to 31
;MB0 to MB31

repeat 32, i:0
   .MB#i = 0009_2200h + 10h * i
end repeat

;0009_2400h to 0009_241Fh
;Mask Register 0 to 7
;MKR0 to MKR7

repeat 8, i:0
   .MKR#i = 0009_2400h + 04h * i
end repeat

.FIDCR0 = 0009_2420h ; FIFO Received ID Compare Register 0
.FIDCR1 = 0009_2424h ; FIFO Received ID Compare Register 1
.MKIVLR = 0009_2428h ; Mask Invalid Register
.MIER   = 0009_242Ch ; Mailbox Interrupt Enable Register

;0009_2820h to 0009_283Fh
;Message Control Register 0 to 31
;MCTL0 to MCTL31

repeat 32, i:0
   .MCTL#i = 0009_2820h + i
end repeat

.CTLR  = 0009_2840h ; Control Register
.STR   = 0009_2842h ; Status Register
.BCR   = 0009_2844h ; Bit Configuration Register
.RFCR  = 0009_2848h ; Receive FIFO Control Register
.RFPCR = 0009_2849h ; Receive FIFO Pointer Control Register
.TFCR  = 0009_284Ah ; Transmit FIFO Control Register
.TFPCR = 0009_284Bh ; Transmit FIFO Pointer Control Register
.EIER  = 0009_284Ch ; Error Interrupt Enable Register
.EIFR  = 0009_284Dh ; Error Interrupt Factor Judge Register
.RECR  = 0009_284Eh ; Receive Error Count Register
.TECR  = 0009_284Fh ; Transmit Error Count Register
.ECSR  = 0009_2850h ; Error Code Store Register
.CSSR  = 0009_2851h ; Channel Search Support Register
.MSSR  = 0009_2852h ; Mailbox Search Status Register
.MSMR  = 0009_2853h ; Mailbox Search Mode Register
.TSR   = 0009_2854h ; Time Stamp Register
.AFSR  = 0009_2856h ; Acceptance Filter Support Register
.TCR   = 0009_2858h ; Test Control Register

CMTW0:

.CMWSTR  = 0009_4200h ; Timer Start Register
.CMWCR   = 0009_4204h ; Timer Control Register
.CMWIOR  = 0009_4208h ; Timer I/O Control Register
.CMWCNT  = 0009_4210h ; Timer Counter
.CMWCOR  = 0009_4214h ; Compare Match Constant Register
.CMWICR0 = 0009_4218h ; Input Capture Register 0
.CMWICR1 = 0009_421Ch ; Input Capture Register 1
.CMWOCR0 = 0009_4220h ; Output Compare Register 0
.CMWOCR1 = 0009_4224h ; Output Compare Register 1

CMTW1:

.CMWSTR  = 0009_4280h ; Timer Start Register
.CMWCR   = 0009_4284h ; Timer Control Register
.CMWIOR  = 0009_4288h ; Timer I/O Control Register
.CMWCNT  = 0009_4290h ; Timer Counter
.CMWCOR  = 0009_4294h ; Compare Match Constant Register
.CMWICR0 = 0009_4298h ; Input Capture Register 0
.CMWICR1 = 0009_429Ch ; Input Capture Register 1
.CMWOCR0 = 0009_42A0h ; Output Compare Register 0
.CMWOCR1 = 0009_42A4h ; Output Compare Register 1

POEG:

.POEGGA = 0009_E000h ; POEG Group A Setting Register
.POEGGB = 0009_E100h ; POEG Group B Setting Register
.POEGGC = 0009_E200h ; POEG Group C Setting Register
.POEGGD = 0009_E300h ; POEG Group D Setting Register

USB0:

.SYSCFG    = 000A_0000h ; System Configuration Control Register
.SYSSTS0   = 000A_0004h ; System Configuration Status Register 0
.DVSTCTR0  = 000A_0008h ; Device State Control Register 0
.CFIFO     = 000A_0014h ; CFIFO Port Register
.D0FIFO    = 000A_0018h ; D0FIFO Port Register
.D1FIFO    = 000A_001Ch ; D1FIFO Port Register
.CFIFOSEL  = 000A_0020h ; CFIFO Port Select Register
.CFIFOCTR  = 000A_0022h ; CFIFO Port Control Register
.D0FIFOSEL = 000A_0028h ; D0FIFO Port Select Register
.D0FIFOCTR = 000A_002Ah ; D0FIFO Port Control Register
.D1FIFOSEL = 000A_002Ch ; D1FIFO Port Select Register
.D1FIFOCTR = 000A_002Eh ; D1FIFO Port Control Register
.INTENB0   = 000A_0030h ; Interrupt Enable Register 0
.INTENB1   = 000A_0032h ; Interrupt Enable Register 1
.BRDYENB   = 000A_0036h ; BRDY Interrupt Enable Register
.NRDYENB   = 000A_0038h ; NRDY Interrupt Enable Register
.BEMPENB   = 000A_003Ah ; BEMP Interrupt Enable Register
.SOFCFG    = 000A_003Ch ; SOF Output Configuration Register
.INTSTS0   = 000A_0040h ; Interrupt Status Register 0
.INTSTS1   = 000A_0042h ; Interrupt Status Register 1
.BRDYSTS   = 000A_0046h ; BRDY Interrupt Status Register
.NRDYSTS   = 000A_0048h ; NRDY Interrupt Status Register
.BEMPSTS   = 000A_004Ah ; BEMP Interrupt Status Register
.FRMNUM    = 000A_004Ch ; Frame Number Register
.DVCHGR    = 000A_004Eh ; Device State Change Register
.USBADDR   = 000A_0050h ; USB Address Register
.USBREQ    = 000A_0054h ; USB Request Type Register
.USBVAL    = 000A_0056h ; USB Request Value Register
.USBINDX   = 000A_0058h ; USB Request Index Register
.USBLENG   = 000A_005Ah ; USB Request Length Register
.DCPCFG    = 000A_005Ch ; DCP Configuration Register
.DCPMAXP   = 000A_005Eh ; DCP Maximum Packet Size Register
.DCPCTR    = 000A_0060h ; DCP Control Register
.PIPESEL   = 000A_0064h ; Pipe Window Select Register
.PIPECFG   = 000A_0068h ; Pipe Configuration Register
.PIPEMAXP  = 000A_006Ch ; Pipe Maximum Packet Size Register
.PIPEPERI  = 000A_006Eh ; Pipe Cycle Control Register
.PIPE1CTR  = 000A_0070h ; Pipe 1 Control Register
.PIPE2CTR  = 000A_0072h ; Pipe 2 Control Register
.PIPE3CTR  = 000A_0074h ; Pipe 3 Control Register
.PIPE4CTR  = 000A_0076h ; Pipe 4 Control Register
.PIPE5CTR  = 000A_0078h ; Pipe 5 Control Register
.PIPE6CTR  = 000A_007Ah ; Pipe 6 Control Register
.PIPE7CTR  = 000A_007Ch ; Pipe 7 Control Register
.PIPE8CTR  = 000A_007Eh ; Pipe 8 Control Register
.PIPE9CTR  = 000A_0080h ; Pipe 9 Control Register
.PIPE1TRE  = 000A_0090h ; Pipe 1 Transaction Counter Enable Register
.PIPE1TRN  = 000A_0092h ; Pipe 1 Transaction Counter Register
.PIPE2TRE  = 000A_0094h ; Pipe 2 Transaction Counter Enable Register
.PIPE2TRN  = 000A_0096h ; Pipe 2 Transaction Counter Register
.PIPE3TRE  = 000A_0098h ; Pipe 3 Transaction Counter Enable Register
.PIPE3TRN  = 000A_009Ah ; Pipe 3 Transaction Counter Register
.PIPE4TRE  = 000A_009Ch ; Pipe 4 Transaction Counter Enable Register
.PIPE4TRN  = 000A_009Eh ; Pipe 4 Transaction Counter Register
.PIPE5TRE  = 000A_00A0h ; Pipe 5 Transaction Counter Enable Register
.PIPE5TRN  = 000A_00A2h ; Pipe 5 Transaction Counter Register
.DEVADD0   = 000A_00D0h ; Device Address 0 Configuration Register
.DEVADD1   = 000A_00D2h ; Device Address 1 Configuration Register
.DEVADD2   = 000A_00D4h ; Device Address 2 Configuration Register
.DEVADD3   = 000A_00D6h ; Device Address 3 Configuration Register
.DEVADD4   = 000A_00D8h ; Device Address 4 Configuration Register
.DEVADD5   = 000A_00DAh ; Device Address 5 Configuration Register
.PHYSLEW   = 000A_00F0h ; PHY Cross Point Adjustment Register

USB:

.DPUSR0R = 000A_0400h ; Deep Standby USB Transceiver Control/Pin Monitoring Register
.DPUSR1R = 000A_0404h ; Deep Standby USB Suspend/Resume Interrupt Register

PDC:

.PCCR0  = 000A_0500h ; PDC Control Register 0
.PCCR1  = 000A_0504h ; PDC Control Register 1
.PCSR   = 000A_0508h ; PDC Status Register
.PCMONR = 000A_050Ch ; PDC Pin Monitor Register
.PCDR   = 000A_0510h ; PDC Receive Data Register
.VCR    = 000A_0514h ; Vertical Capture Register
.HCR    = 000A_0518h ; Horizontal Capture Register

EDMAC0:

.EDMR   = 000C_0000h ; EDMAC Mode Register
.EDTRR  = 000C_0008h ; EDMAC Transmit Request Register
.EDRRR  = 000C_0010h ; EDMAC Receive Request Register
.TDLAR  = 000C_0018h ; Transmit Descriptor List Start Address Register
.RDLAR  = 000C_0020h ; Receive Descriptor List Start Address Register
.EESR   = 000C_0028h ; ETHERC/EDMAC Status Register
.EESIPR = 000C_0030h ; ETHERC/EDMAC Status Interrupt Enable Register
.TRSCER = 000C_0038h ; ETHERC/EDMAC Transmit/Receive Status Copy Enable Register
.RMFCR  = 000C_0040h ; Missed-Frame Counter Register
.TFTR   = 000C_0048h ; Transmit FIFO Threshold Register
.FDR    = 000C_0050h ; FIFO Depth Register
.RMCR   = 000C_0058h ; Receive Method Control Register
.TFUCR  = 000C_0064h ; Transmit FIFO Underflow Counter
.RFOCR  = 000C_0068h ; Receive FIFO Overflow Counter
.IOSR   = 000C_006Ch ; Independent Output Signal Setting Register
.FCFTR  = 000C_0070h ; Flow Control Start FIFO Threshold Setting Register
.RPADIR = 000C_0078h ; Receive Data Padding Insert Register
.TRIMD  = 000C_007Ch ; Transmit Interrupt Setting Register
.RBWAR  = 000C_00C8h ; Receive Buffer Write Address Register
.RDFAR  = 000C_00CCh ; Receive Descriptor Fetch Address Register
.TBRAR  = 000C_00D4h ; Transmit Buffer Read Address Register
.TDFAR  = 000C_00D8h ; Transmit Descriptor Fetch Address Register

ETHERC0:

.ECMR     = 000C_0100h ; ETHERC Mode Register
.RFLR     = 000C_0108h ; Receive Frame Maximum Length Register
.ECSR     = 000C_0110h ; ETHERC Status Register
.ECSIPR   = 000C_0118h ; ETHERC Interrupt Enable Register
.PIR      = 000C_0120h ; PHY Interface Register
.PSR      = 000C_0128h ; PHY Status Register
.RDMLR    = 000C_0140h ; Random Number Generation Counter Limit Setting Register
.IPGR     = 000C_0150h ; Interpacket Gap Register
.APR      = 000C_0154h ; Automatic PAUSE Frame Register
.MPR      = 000C_0158h ; Manual PAUSE Frame Register
.RFCF     = 000C_0160h ; Received PAUSE Frame Counter
.TPAUSER  = 000C_0164h ; PAUSE Frame Retransmit Count Setting Register
.TPAUSECR = 000C_0168h ; PAUSE Frame Retransmit Counter
.BCFRR    = 000C_016Ch ; Broadcast Frame Receive Count Setting Register
.MAHR     = 000C_01C0h ; MAC Address Upper Bit Register
.MALR     = 000C_01C8h ; MAC Address Lower Bit Register
.TROCR    = 000C_01D0h ; Transmit Retry Over Counter Register
.CDCR     = 000C_01D4h ; Late Collision Detect Counter Register
.LCCR     = 000C_01D8h ; Lost Carrier Counter Register
.CNDCR    = 000C_01DCh ; Carrier Not Detect Counter Register
.CEFCR    = 000C_01E4h ; CRC Error Frame Receive Counter Register
.FRECR    = 000C_01E8h ; Frame Receive Error Counter Register
.TSFRCR   = 000C_01ECh ; Too-Short Frame Receive Counter Register
.TLFRCR   = 000C_01F0h ; Too-Long Frame Receive Counter Register
.RFCR     = 000C_01F4h ; Received Alignment Error Frame Counter Register
.MAFCR    = 000C_01F8h ; Multicast Address Frame Receive Counter Register

EDMAC1:

.EDMR   = 000C_0200h ; EDMAC Mode Register
.EDTRR  = 000C_0208h ; EDMAC Transmit Request Register
.EDRRR  = 000C_0210h ; EDMAC Receive Request Register
.TDLAR  = 000C_0218h ; Transmit Descriptor List Start Address Register
.RDLAR  = 000C_0220h ; Receive Descriptor List Start Address Register
.EESR   = 000C_0228h ; ETHERC/EDMAC Status Register
.EESIPR = 000C_0230h ; ETHERC/EDMAC Status Interrupt Enable Register
.TRSCER = 000C_0238h ; ETHERC/EDMAC Transmit/Receive Status Copy Enable Register
.RMFCR  = 000C_0240h ; Missed-Frame Counter Register
.TFTR   = 000C_0248h ; Transmit FIFO Threshold Register
.FDR    = 000C_0250h ; FIFO Depth Register
.RMCR   = 000C_0258h ; Receive Method Control Register
.TFUCR  = 000C_0264h ; Transmit FIFO Underflow Counter
.RFOCR  = 000C_0268h ; Receive FIFO Overflow Counter
.IOSR   = 000C_026Ch ; Independent Output Signal Setting Register
.FCFTR  = 000C_0270h ; Flow Control Start FIFO Threshold Setting Register
.RPADIR = 000C_0278h ; Receive Data Padding Insert Register
.TRIMD  = 000C_027Ch ; Transmit Interrupt Setting Register
.RBWAR  = 000C_02C8h ; Receive Buffer Write Address Register
.RDFAR  = 000C_02CCh ; Receive Descriptor Fetch Address Register
.TBRAR  = 000C_02D4h ; Transmit Buffer Read Address Register
.TDFAR  = 000C_02D8h ; Transmit Descriptor Fetch Address Register

ETHER1:

.ECMR     = 000C_0300h ; ETHERC Mode Register
.RFLR     = 000C_0308h ; Receive Frame Maximum Length Register
.ECSR     = 000C_0310h ; ETHERC Status Register
.ECSIPR   = 000C_0318h ; ETHERC Interrupt Enable Register
.PIR      = 000C_0320h ; PHY Interface Register
.PSR      = 000C_0328h ; PHY Status Register
.RDMLR    = 000C_0340h ; Random Number Generation Counter Limit Setting Register
.IPGR     = 000C_0350h ; Interpacket Gap Register
.APR      = 000C_0354h ; Automatic PAUSE Frame Register
.MPR      = 000C_0358h ; Manual PAUSE Frame Register
.RFCF     = 000C_0360h ; Received PAUSE Frame Counter
.TPAUSER  = 000C_0364h ; PAUSE Frame Retransmit Count Setting Register
.TPAUSECR = 000C_0368h ; PAUSE Frame Retransmit Counter
.BCFRR    = 000C_036Ch ; Broadcast Frame Receive Count Setting Register
.MAHR     = 000C_03C0h ; MAC Address Upper Bit Register
.MALR     = 000C_03C8h ; MAC Address Lower Bit Register
.TROCR    = 000C_03D0h ; Transmit Retry Over Counter Register
.CDCR     = 000C_03D4h ; Late Collision Detect Counter Register
.LCCR     = 000C_03D8h ; Lost Carrier Counter Register
.CNDCR    = 000C_03DCh ; Carrier Not Detect Counter Register
.CEFCR    = 000C_03E4h ; CRC Error Frame Receive Counter Register
.FRECR    = 000C_03E8h ; Frame Receive Error Counter Register
.TSFRCR   = 000C_03ECh ; Too-Short Frame Receive Counter Register
.TLFRCR   = 000C_03F0h ; Too-Long Frame Receive Counter Register
.RFCR     = 000C_03F4h ; Received Alignment Error Frame Counter Register
.MAFCR    = 000C_03F8h ; Multicast Address Frame Receive Counter Register

PTPEDMAC:

.EDMR   = 000C_0400h ; PTPEDMAC EDMAC Mode Register
.EDTRR  = 000C_0408h ; PTPEDMAC EDMAC Transmit Request Register
.EDRRR  = 000C_0410h ; PTPEDMAC EDMAC Receive Request Register
.TDLAR  = 000C_0418h ; PTPEDMAC Transmit Descriptor List Start Address Register
.RDLAR  = 000C_0420h ; PTPEDMAC Receive Descriptor List Start Address Register
.EESR   = 000C_0428h ; PTPEDMAC PTP/EDMAC Status Register
.EESIPR = 000C_0430h ; PTPEDMAC PTP/EDMAC Status Interrupt Enable Register
.RMFCR  = 000C_0440h ; PTPEDMAC Missed-Frame Counter Register
.TFTR   = 000C_0448h ; PTPEDMAC Transmit FIFO Threshold Register
.FDR    = 000C_0450h ; PTPEDMAC FIFO Depth Register
.RMCR   = 000C_0458h ; PTPEDMAC Receive Method Control Register
.TFUCR  = 000C_0464h ; PTPEDMAC Transmit FIFO Underflow Counter
.RFOCR  = 000C_0468h ; PTPEDMAC Receive FIFO Overflow Counter
.FCFTR  = 000C_0470h ; PTPEDMAC Flow Control Start FIFO Threshold Setting Register
.RPADIR = 000C_0478h ; PTPEDMAC Receive Data Padding Insert Register
.TRIMD  = 000C_047Ch ; PTPEDMAC Transmit Interrupt Setting Register
.RBWAR  = 000C_04C8h ; PTPEDMAC Receive Buffer Write Address Register
.RDFAR  = 000C_04CCh ; PTPEDMAC Receive Descriptor Fetch Address Register
.TBRAR  = 000C_04D4h ; PTPEDMAC Transmit Buffer Read Address Register
.TDFAR  = 000C_04D8h ; PTPEDMAC Transmit Descriptor Fetch Address Register

EPTPC:

.PTRSTR    = 000C_0500h ; PTP Reset Register
.STCSELR   = 000C_0504h ; STCA Clock Select Register
.SYBYPSR   = 000C_0508h ; SYNFP Bypass Register
.MIESR     = 000C_4000h ; MINT Interrupt Source Status Register
.MIEIPR    = 000C_4004h ; MINT Interrupt Request Enable Register
.ELIPPR    = 000C_4010h ; ELC Output/IPLS Interrupt Request Enable Register
.ELIPACR   = 000C_4014h ; ELC Output/IPLS Interrupt Enable Automatic Clearing Register
.STSR      = 000C_4040h ; STCA Status Register
.STIPR     = 000C_4044h ; STCA Status Notification Enable Register
.STCFR     = 000C_4050h ; STCA Clock Frequency Setting Register
.STMR      = 000C_4054h ; STCA Operating Mode Register
.SYNTOR    = 000C_4058h ; Sync Message Reception Timeout Register
.IPTSELR   = 000C_4060h ; IPLS Interrupt Request Timer Select Register
.MITSELR   = 000C_4064h ; MINT Interrupt Request Timer Select Register
.ELTSELR   = 000C_4068h ; ELC Output Timer Select Register
.STCHSELR  = 000C_406Ch ; Time Synchronization Channel Select Register
.SYNSTARTR = 000C_4080h ; Slave Time Synchronization Start Register
.LCIVLDR   = 000C_4084h ; Local Clock Counter Initial Value Load Directive Register
.SYNTDARU  = 000C_4090h ; Synchronization Loss Detection Threshold Register
.SYNTDARL  = 000C_4094h ; Synchronization Loss Detection Threshold Register
.SYNTDBRU  = 000C_4098h ; Synchronization Detection Threshold Register
.SYNTDBRL  = 000C_409Ch ; Synchronization Detection Threshold Register
.LCIVRU    = 000C_40B0h ; Local Clock Counter Initial Value Register
.LCIVRM    = 000C_40B4h ; Local Clock Counter Initial Value Register
.LCIVRL    = 000C_40B8h ; Local Clock Counter Initial Value Register
.GETW10R   = 000C_4124h ; Worst 10 Acquisition Directive Register
.PLIMITRU  = 000C_4128h ; Positive Gradient Limit Register
.PLIMITRM  = 000C_412Ch ; Positive Gradient Limit Register
.PLIMITRL  = 000C_4130h ; Positive Gradient Limit Register
.MLIMITRU  = 000C_4134h ; Negative Gradient Limit Register
.MLIMITRM  = 000C_4138h ; Negative Gradient Limit Register
.MLIMITRL  = 000C_413Ch ; Negative Gradient Limit Register
.GETINFOR  = 000C_4140h ; Statistical Information Retention Control Register
.LCCVRU    = 000C_4170h ; Local Clock Counter
.LCCVRM    = 000C_4174h ; Local Clock Counter
.LCCVRL    = 000C_4178h ; Local Clock Counter
.PW10VRU   = 000C_4210h ; Positive Gradient Worst 10 Value Register
.PW10VRM   = 000C_4214h ; Positive Gradient Worst 10 Value Register
.PW10VRL   = 000C_4218h ; Positive Gradient Worst 10 Value Register
.MW10RU    = 000C_42D0h ; Negative Gradient Worst 10 Value Register
.MW10RM    = 000C_42D4h ; Negative Gradient Worst 10 Value Register
.MW10RL    = 000C_42D8h ; Negative Gradient Worst 10 Value Register
.TMSTTRU0  = 000C_4300h ; Timer Start Time Setting Register
.TMSTTRL0  = 000C_4304h ; Timer Start Time Setting Register
.TMCYCR0   = 000C_4308h ; Timer Cycle Setting Register 0
.TMPLSR0   = 000C_430Ch ; Timer Pulse Width Setting Register 0
.TMSTTRU1  = 000C_4310h ; Timer Start Time Setting Register
.TMSTTRL1  = 000C_4314h ; Timer Start Time Setting Register
.TMCYCR1   = 000C_4318h ; Timer Cycle Setting Register 1
.TMPLSR1   = 000C_431Ch ; Timer Pulse Width Setting Register 1
.TMSTTRU2  = 000C_4320h ; Timer Start Time Setting Register
.TMSTTRL2  = 000C_4324h ; Timer Start Time Setting Register
.TMCYCR2   = 000C_4328h ; Timer Cycle Setting Register 2
.TMPLSR2   = 000C_432Ch ; Timer Pulse Width Setting Register 2
.TMSTTRU3  = 000C_4330h ; Timer Start Time Setting Register
.TMSTTRL3  = 000C_4334h ; Timer Start Time Setting Register
.TMCYCR3   = 000C_4338h ; Timer Cycle Setting Register 3
.TMPLSR3   = 000C_433Ch ; Timer Pulse Width Setting Register 3
.TMSTTRU4  = 000C_4340h ; Timer Start Time Setting Register
.TMSTTRL4  = 000C_4344h ; Timer Start Time Setting Register
.TMCYCR4   = 000C_4348h ; Timer Cycle Setting Register 4
.TMPLSR4   = 000C_434Ch ; Timer Pulse Width Setting Register 4
.TMSTTRU5  = 000C_4350h ; Timer Start Time Setting Register
.TMSTTRL5  = 000C_4354h ; Timer Start Time Setting Register
.TMCYCR5   = 000C_4358h ; Timer Cycle Setting Register 5
.TMPLSR5   = 000C_435Ch ; Timer Pulse Width Setting Register 5
.TMSTARTR  = 000C_437Ch ; Timer Start Register
.PRSR      = 000C_4400h ; PRC-TC Status Register
.PRIPR     = 000C_4404h ; PRC-TC Status Notification Enable Register
.PRMACRU0  = 000C_4410h ; Channel 0 Local MAC Address Register
.PRMACRL0  = 000C_4414h ; Channel 0 Local MAC Address Register
.PRMACRU1  = 000C_4418h ; Channel 1 Local MAC Address Register
.PRMACRL1  = 000C_441Ch ; Channel 1 Local MAC Address Register
.TRNDISR   = 000C_4420h ; Packet Transmission Control Register
.TRNMR     = 000C_4430h ; Relay Mode Register
.TRNCTTDR  = 000C_4434h ; Cut-Through Transfer Start Threshold Register

EPTPC0:

.SYSR      = 000C_4800h ; SYNFP Status Register
.SYIPR     = 000C_4804h ; SYNFP Status Notification Enable Register
.SYMACRU   = 000C_4810h ; SYNFP MAC Address Register
.SYMACRL   = 000C_4814h ; SYNFP MAC Address Register
.SYLLCCTLR = 000C_4818h ; SYNFP LLC-CTL Value Register
.SYIPADDRR = 000C_481Ch ; SYNFP Local IP Address Register
.SYSPVRR   = 000C_4840h ; SYNFP Specification Version Setting Register
.SYDOMR    = 000C_4844h ; SYNFP Domain Number Setting Register
.ANFR      = 000C_4850h ; Announce Message Flag Field Setting Register
.SYNFR     = 000C_4854h ; Sync Message Flag Field Setting Register
.DYRQFR    = 000C_4858h ; Delay_Req Message Flag Field Setting Register
.DYRPFR    = 000C_485Ch ; Delay_Resp Message Flag Field Setting Register
.SYCIDRU   = 000C_4860h ; SYNFP Local Clock ID Register
.SYCIDRL   = 000C_4864h ; SYNFP Local Clock ID Register
.SYPNUMR   = 000C_4868h ; SYNFP Local Port Number Register
.SYRVLDR   = 000C_4880h ; SYNFP Register Value Load Directive Register
.SYRFL1R   = 000C_4890h ; SYNFP Reception Filter Register 1
.SYRFL2R   = 000C_4894h ; SYNFP Reception Filter Register 2
.SYTRENR   = 000C_4898h ; SYNFP Transmission Enable Register
.MTCIDU    = 000C_48A0h ; Master Clock ID Register
.MTCIDL    = 000C_48A4h ; Master Clock ID Register
.MTPID     = 000C_48A8h ; Master Clock Port Number Register
.SYTLIR    = 000C_48C0h ; SYNFP Transmission Interval Setting Register
.SYRLIR    = 000C_48C4h ; SYNFP Received logMessageInterval Value Indication Register
.OFMRU     = 000C_48C8h ; offsetFromMaster Value Register
.OFMRL     = 000C_48CCh ; offsetFromMaster Value Register
.MPDRU     = 000C_48D0h ; meanPathDelay Value Register
.MPDRL     = 000C_48D4h ; meanPathDelay Value Register
.GMPR      = 000C_48E0h ; grandmasterPriority Field Setting Register
.GMCQR     = 000C_48E4h ; grandmasterClockQuality Field Setting Register
.GMIDRU    = 000C_48E8h ; grandmasterIdentity Field Setting Register
.GMIDRL    = 000C_48ECh ; grandmasterIdentity Field Setting Register
.CUOTSR    = 000C_48F0h ; currentUtcOffset/timeSource Field Setting Register
.SRR       = 000C_48F4h ; stepsRemoved Field Setting Register
.PPMACRU   = 000C_4900h ; PTP-primary Message Destination MAC Address Setting Register
.PPMACRL   = 000C_4904h ; PTP-primary Message Destination MAC Address Setting Register
.PDMACRU   = 000C_4908h ; PTP-pdelay Message MAC Address Setting Register
.PDMACRL   = 000C_490Ch ; PTP-pdelay Message MAC Address Setting Register
.PETYPER   = 000C_4910h ; PTP Message Ethertype Setting Register
.PPIPR     = 000C_4920h ; PTP-primary Message Destination IP Address Setting Register
.PDIPR     = 000C_4924h ; PTP-pdelay Message Destination IP Address Setting Register
.PETOSR    = 000C_4928h ; PTP Event Message TOS Setting Register
.PGTOSR    = 000C_492Ch ; PTP general Message TOS Setting Register
.PPTTLR    = 000C_4930h ; PTP-primary Message TTL Setting Register
.PDTTLR    = 000C_4934h ; PTP-pdelay Message TTL Setting Register
.PEUDPR    = 000C_4938h ; PTP Event Message UDP Destination Port Number Setting Register
.PGUDPR    = 000C_493Ch ; PTP general Message UDP Destination Port Number Setting Register
.FFLTR     = 000C_4940h ; Frame Reception Filter Setting Register
.FMAC0RU   = 000C_4960h ; Frame Reception Filter MAC Address 0 Setting Register
.FMAC0RL   = 000C_4964h ; Frame Reception Filter MAC Address 0 Setting Register
.FMAC1RU   = 000C_4968h ; Frame Reception Filter MAC Address 1 Setting Register
.FMAC1RL   = 000C_496Ch ; Frame Reception Filter MAC Address 1 Setting Register
.DASYMRU   = 000C_49C0h ; Asymmetric Delay Setting Register
.DASYMRL   = 000C_49C4h ; Asymmetric Delay Setting Register
.TSLATR    = 000C_49C8h ; Timestamp Latency Setting Register
.SYCONFR   = 000C_49CCh ; SYNFP Operation Setting Register
.SYFORMR   = 000C_49D0h ; SYNFP Frame Format Setting Register
.RSTOUTR   = 000C_49D4h ; Response Message Reception Timeout Register

EPTPC1:

.SYSR      = 000C_4C00h ; SYNFP Status Register
.SYIPR     = 000C_4C04h ; SYNFP Status Notification Enable Register
.SYMACRU   = 000C_4C10h ; SYNFP MAC Address Register
.SYMACRL   = 000C_4C14h ; SYNFP MAC Address Register
.SYLLCCTLR = 000C_4C18h ; SYNFP LLC-CTL Value Register
.SYIPADDRR = 000C_4C1Ch ; SYNFP Local IP Address Register
.SYSPVRR   = 000C_4C40h ; SYNFP Specification Version Setting Register
.SYDOMR    = 000C_4C44h ; SYNFP Domain Number Setting Register
.ANFR      = 000C_4C50h ; Announce Message Flag Field Setting Register
.SYNFR     = 000C_4C54h ; Sync Message Flag Field Setting Register
.DYRQFR    = 000C_4C58h ; Delay_Req Message Flag Field Setting Register
.DYRPFR    = 000C_4C5Ch ; Delay_Resp Message Flag Field Setting Register
.SYCIDRU   = 000C_4C60h ; SYNFP Local Clock ID Register
.SYCIDRL   = 000C_4C64h ; SYNFP Local Clock ID Register
.SYPNUMR   = 000C_4C68h ; SYNFP Local Port Number Register
.SYRVLDR   = 000C_4C80h ; SYNFP Register Value Load Directive Register
.SYRFL1R   = 000C_4C90h ; SYNFP Reception Filter Register 1
.SYRFL2R   = 000C_4C94h ; SYNFP Reception Filter Register 2
.SYTRENR   = 000C_4C98h ; SYNFP Transmission Enable Register
.MTCIDU    = 000C_4CA0h ; Master Clock ID Register
.MTCIDL    = 000C_4CA4h ; Master Clock ID Register
.MTPID     = 000C_4CA8h ; Master Clock Port Number Register
.SYTLIR    = 000C_4CC0h ; SYNFP Transmission Interval Setting Register
.SYRLIR    = 000C_4CC4h ; SYNFP Received logMessageInterval Value Indication Register
.OFMRU     = 000C_4CC8h ; offsetFromMaster Value Register
.OFMRL     = 000C_4CCCh ; offsetFromMaster Value Register
.MPDRU     = 000C_4CD0h ; meanPathDelay Value Register
.MPDRL     = 000C_4CD4h ; meanPathDelay Value Register
.GMPR      = 000C_4CE0h ; grandmasterPriority Field Setting Register
.GMCQR     = 000C_4CE4h ; grandmasterClockQuality Field Setting Register
.GMIDRU    = 000C_4CE8h ; grandmasterIdentity Field Setting Register
.GMIDRL    = 000C_4CECh ; grandmasterIdentity Field Setting Register
.CUOTSR    = 000C_4CF0h ; currentUtcOffset/timeSource Field Setting Register
.SRR       = 000C_4CF4h ; stepsRemoved Field Setting Register
.PPMACRU   = 000C_4D00h ; PTP-primary Message Destination MAC Address Setting Register
.PPMACRL   = 000C_4D04h ; PTP-primary Message Destination MAC Address Setting Register
.PDMACRU   = 000C_4D08h ; PTP-pdelay Message MAC Address Setting Register
.PDMACRL   = 000C_4D0Ch ; PTP-pdelay Message MAC Address Setting Register
.PETYPER   = 000C_4D10h ; PTP Message Ethertype Setting Register
.PPIPR     = 000C_4D20h ; PTP-primary Message Destination IP Address Setting Register
.PDIPR     = 000C_4D24h ; PTP-pdelay Message Destination IP Address Setting Register
.PETOSR    = 000C_4D28h ; PTP Event Message TOS Setting Register
.PGTOSR    = 000C_4D2Ch ; PTP general Message TOS Setting Register
.PPTTLR    = 000C_4D30h ; PTP-primary Message TTL Setting Register
.PDTTLR    = 000C_4D34h ; PTP-pdelay Message TTL Setting Register
.PEUDPR    = 000C_4D38h ; PTP Event Message UDP Destination Port Number Setting Register
.PGUDPR    = 000C_4D3Ch ; PTP general Message UDP Destination Port Number Setting Register
.FFLTR     = 000C_4D40h ; Frame Reception Filter Setting Register
.FMAC0RU   = 000C_4D60h ; Frame Reception Filter MAC Address 0 Setting Register
.FMAC0RL   = 000C_4D64h ; Frame Reception Filter MAC Address 0 Setting Register
.FMAC1RU   = 000C_4D68h ; Frame Reception Filter MAC Address 1 Setting Register
.FMAC1RL   = 000C_4D6Ch ; Frame Reception Filter MAC Address 1 Setting Register
.DASYMRU   = 000C_4DC0h ; Asymmetric Delay Setting Register
.DASYMRL   = 000C_4DC4h ; Asymmetric Delay Setting Register
.TSLATR    = 000C_4DC8h ; Timestamp Latency Setting Register
.SYCONFR   = 000C_4DCCh ; SYNFP Operation Setting Register
.SYFORMR   = 000C_4DD0h ; SYNFP Frame Format Setting Register
.RSTOUTR   = 000C_4DD4h ; Response Message Reception Timeout Register

MTU3:

.TCR   = 000C_1200h ; Timer Control Register
.TMDR1 = 000C_1202h ; Timer Mode Register 1
.TIORH = 000C_1204h ; Timer I/O Control Register H
.TIORL = 000C_1205h ; Timer I/O Control Register L
.TIER  = 000C_1208h ; Timer Interrupt Enable Register
.TCNT  = 000C_1210h ; Timer Counter
.TGRA  = 000C_1218h ; Timer General Register A
.TGRB  = 000C_121Ah ; Timer General Register B
.TGRC  = 000C_1224h ; Timer General Register C
.TGRD  = 000C_1226h ; Timer General Register D
.TSR   = 000C_122Ch ; Timer Status Register
.TBTM  = 000C_1238h ; Timer Buffer Operation Transfer Mode Register
.TCR2  = 000C_124Ch ; Timer Control Register 2
.TGRE  = 000C_1272h ; Timer General Register E

MTU4:

.TCR      = 000C_1201h ; Timer Control Register
.TMDR1    = 000C_1203h ; Timer Mode Register 1
.TIORH    = 000C_1206h ; Timer I/O Control Register H
.TIORL    = 000C_1207h ; Timer I/O Control Register L
.TIER     = 000C_1209h ; Timer Interrupt Enable Register
.TCNT     = 000C_1212h ; Timer Counter
.TGRA     = 000C_121Ch ; Timer General Register A
.TGRB     = 000C_121Eh ; Timer General Register B
.TGRC     = 000C_1228h ; Timer General Register C
.TGRD     = 000C_122Ah ; Timer General Register D
.TSR      = 000C_122Dh ; Timer Status Register
.TBTM     = 000C_1239h ; Timer Buffer Operation Transfer Mode Register
.TADCR    = 000C_1240h ; Timer A/D Converter Start Request Control Register
.TADCORA  = 000C_1244h ; Timer A/D Converter Start Request Cycle Set Register A
.TADCORB  = 000C_1246h ; Timer A/D Converter Start Request Cycle Set Register B
.TADCOBRA = 000C_1248h ; Timer A/D Converter Start Request Cycle Set Buffer Register A
.TADCOBRB = 000C_124Ah ; Timer A/D Converter Start Request Cycle Set Buffer Register B
.TCR2     = 000C_124Dh ; Timer Control Register 2
.TGRE     = 000C_1274h ; Timer General Register E
.TGRF     = 000C_1276h ; Timer General Register F

MTU:

.TOERA    = 000C_120Ah ; Timer Output Master Enable Register A
.TGCRA    = 000C_120Dh ; Timer Gate Control Register A
.TOCR1A   = 000C_120Eh ; Timer Output Control Register 1A
.TOCR2A   = 000C_120Fh ; Timer Output Control Register 2A
.TCDRA    = 000C_1214h ; Timer Period Data Register A
.TDDRA    = 000C_1216h ; Timer Dead Time Data Register A
.TCNTSA   = 000C_1220h ; Timer Subcounter A
.TCBRA    = 000C_1222h ; Timer Period Buffer Register A
.TITCR1A  = 000C_1230h ; Timer Interrupt Skipping Set Register 1A
.TITCNT1A = 000C_1231h ; Timer Interrupt Skipping Counter 1A
.TBTERA   = 000C_1232h ; Timer Buffer Transfer Set Register A
.TDERA    = 000C_1234h ; Timer Dead Time Enable Register A
.TOLBRA   = 000C_1236h ; Timer Output Level Buffer Register A
.TITMRA   = 000C_123Ah ; Timer Interrupt Skipping Mode Register A
.TITCR2A  = 000C_123Bh ; Timer Interrupt Skipping Set Register 2A
.TITCNT2A = 000C_123Ch ; Timer Interrupt Skipping Counter 2A
.TWCRA    = 000C_1260h ; Timer Waveform Control Register A
.TMDR2A   = 000C_1270h ; Timer Mode Register 2A
.TSTRA    = 000C_1280h ; Timer Start Register A
.TSYRA    = 000C_1281h ; Timer Synchronous Register A
.TCSYSTR  = 000C_1282h ; Timer Counter Synchronous Start Register
.TRWERA   = 000C_1284h ; Timer Read/Write Enable Register A
.TOERB    = 000C_1A0Ah ; Timer Output Master Enable Register B
.TOCR1B   = 000C_1A0Eh ; Timer Output Control Register 1B
.TOCR2B   = 000C_1A0Fh ; Timer Output Control Register 2B
.TCDRB    = 000C_1A14h ; Timer Period Data Register B
.TDDRB    = 000C_1A16h ; Timer Dead Time Data Register B
.TCNTSB   = 000C_1A20h ; Timer Subcounter B
.TCBRB    = 000C_1A22h ; Timer Period Buffer Register B
.TITCR1B  = 000C_1A30h ; Timer Interrupt Skipping Set Register 1B
.TITCNT1B = 000C_1A31h ; Timer Interrupt Skipping Counter 1B
.TBTERB   = 000C_1A32h ; Timer Buffer Transfer Set Register B
.TDERB    = 000C_1A34h ; Timer Dead Time Enable Register B
.TOLBRB   = 000C_1A36h ; Timer Output Level Buffer Register B
.TITMRB   = 000C_1A3Ah ; Timer Interrupt Skipping Mode Register B
.TITCR2B  = 000C_1A3Bh ; Timer Interrupt Skipping Set Register 2B
.TITCNT2B = 000C_1A3Ch ; Timer Interrupt Skipping Counter 2B
.TWCRB    = 000C_1A60h ; Timer Waveform Control Register B
.TMDR2B   = 000C_1A70h ; Timer Mode Register 2B
.TSTRB    = 000C_1A80h ; Timer Start Register B
.TSYRB    = 000C_1A81h ; Timer Synchronous Register B
.TRWERB   = 000C_1A84h ; Timer Read/Write Enable Register B

MTU0:

.NFCR0 = 000C_1290h ; Noise Filter Control Register 0
.NFCRC = 000C_1299h ; Noise Filter Control Register C
.TCR   = 000C_1300h ; Timer Control Register
.TMDR1 = 000C_1301h ; Timer Mode Register 1
.TIORH = 000C_1302h ; Timer I/O Control Register H
.TIORL = 000C_1303h ; Timer I/O Control Register L
.TIER  = 000C_1304h ; Timer Interrupt Enable Register
.TCNT  = 000C_1306h ; Timer Counter
.TGRA  = 000C_1308h ; Timer General Register A
.TGRB  = 000C_130Ah ; Timer General Register B
.TGRC  = 000C_130Ch ; Timer General Register C
.TGRD  = 000C_130Eh ; Timer General Register D
.TGRE  = 000C_1320h ; Timer General Register E
.TGRF  = 000C_1322h ; Timer General Register F
.TIER2 = 000C_1324h ; Timer Interrupt Enable Register 2
.TBTM  = 000C_1326h ; Timer Buffer Operation Transfer Mode Register
.TCR2  = 000C_1328h ; Timer Control Register 2

MTU1:

.NFCR1  = 000C_1291h ; Noise Filter Control Register 1
.TCR    = 000C_1380h ; Timer Control Register
.TMDR1  = 000C_1381h ; Timer Mode Register 1
.TIOR   = 000C_1382h ; Timer I/O Control Register
.TIER   = 000C_1384h ; Timer Interrupt Enable Register
.TSR    = 000C_1385h ; Timer Status Register
.TCNT   = 000C_1386h ; Timer Counter
.TGRA   = 000C_1388h ; Timer General Register A
.TGRB   = 000C_138Ah ; Timer General Register B
.TICCR  = 000C_1390h ; Timer Input Capture Control Register
.TMDR3  = 000C_1391h ; Timer Mode Register 3
.TCR2   = 000C_1394h ; Timer Control Register 2
.TCNTLW = 000C_13A0h ; Timer Longword Counter
.TGRALW = 000C_13A4h ; Timer Longword General Register
.TGRBLW = 000C_13A8h ; Timer Longword General Register

MTU2:

.NFCR2 = 000C_1292h ; Noise Filter Control Register 2
.TCR   = 000C_1400h ; Timer Control Register
.TMDR1 = 000C_1401h ; Timer Mode Register 1
.TIOR  = 000C_1402h ; Timer I/O Control Register
.TIER  = 000C_1404h ; Timer Interrupt Enable Register
.TSR   = 000C_1405h ; Timer Status Register
.TCNT  = 000C_1406h ; Timer Counter
.TGRA  = 000C_1408h ; Timer General Register A
.TGRB  = 000C_140Ah ; Timer General Register B
.TCR2  = 000C_140Ch ; Timer Control Register 2

MTU3:

.NFCR3 = 000C_1293h ; Noise Filter Control Register 3

MTU4:

.NFCR4 = 000C_1294h ; Noise Filter Control Register 4

MTU5:

.NFCR5      = 000C_1A95h ; Noise Filter Control Register 5
.TCNTU      = 000C_1C80h ; Timer Counter U
.TGRU       = 000C_1C82h ; Timer General Register U
.TCRU       = 000C_1C84h ; Timer Control Register U
.TCR2U      = 000C_1C85h ; Timer Control Register 2
.TIORU      = 000C_1C86h ; Timer I/O Control Register U
.TCNTV      = 000C_1C90h ; Timer Counter V
.TGRV       = 000C_1C92h ; Timer General Register V
.TCRV       = 000C_1C94h ; Timer Control Register V
.TCR2V      = 000C_1C95h ; Timer Control Register 2
.TIORV      = 000C_1C96h ; Timer I/O Control Register V
.TCNTW      = 000C_1CA0h ; Timer Counter W
.TGRW       = 000C_1CA2h ; Timer General Register W
.TCRW       = 000C_1CA4h ; Timer Control Register W
.TCR2W      = 000C_1CA5h ; Timer Control Register 2
.TIORW      = 000C_1CA6h ; Timer I/O Control Register W
.TIER       = 000C_1CB2h ; Timer Interrupt Enable Register
.TSTR       = 000C_1CB4h ; Timer Start Register
.TCNTCMPCLR = 000C_1CB6h ; Timer Compare Match Clear Register

MTU6:

.TCR   = 000C_1A00h ; Timer Control Register
.TMDR1 = 000C_1A02h ; Timer Mode Register 1
.TIORH = 000C_1A04h ; Timer I/O Control Register H
.TIORL = 000C_1A05h ; Timer I/O Control Register L
.TIER  = 000C_1A08h ; Timer Interrupt Enable Register
.TCNT  = 000C_1A10h ; Timer Counter
.TGRA  = 000C_1A18h ; Timer General Register A
.TGRB  = 000C_1A1Ah ; Timer General Register B
.TGRC  = 000C_1A24h ; Timer General Register C
.TGRD  = 000C_1A26h ; Timer General Register D
.TSR   = 000C_1A2Ch ; Timer Status Register
.TBTM  = 000C_1A38h ; Timer Buffer Operation Transfer Mode Register
.TCR2  = 000C_1A4Ch ; Timer Control Register 2
.TSYCR = 000C_1A50h ; Timer Synchronous Clear Register
.TGRE  = 000C_1A72h ; Timer General Register E
.NFCR6 = 000C_1A93h ; Noise Filter Control Register 6

MTU7:

.TCR      = 000C_1A01h ; Timer Control Register
.TMDR1    = 000C_1A03h ; Timer Mode Register 1
.TIORH    = 000C_1A06h ; Timer I/O Control Register H
.TIORL    = 000C_1A07h ; Timer I/O Control Register L
.TIER     = 000C_1A09h ; Timer Interrupt Enable Register
.TCNT     = 000C_1A12h ; Timer Counter
.TGRA     = 000C_1A1Ch ; Timer General Register A
.TGRB     = 000C_1A1Eh ; Timer General Register B
.TGRC     = 000C_1A28h ; Timer General Register C
.TGRD     = 000C_1A2Ah ; Timer General Register D
.TSR      = 000C_1A2Dh ; Timer Status Register
.TBTM     = 000C_1A39h ; Timer Buffer Operation Transfer Mode Register
.TADCR    = 000C_1A40h ; Timer A/D Converter Start Request Control Register
.TADCORA  = 000C_1A44h ; Timer A/D Converter Start Request Cycle Set Register A
.TADCORB  = 000C_1A46h ; Timer A/D Converter Start Request Cycle Set Register B
.TADCOBRA = 000C_1A48h ; Timer A/D Converter Start Request Cycle Set Buffer Register A
.TADCOBRB = 000C_1A4Ah ; Timer A/D Converter Start Request Cycle Set Buffer Register B
.TCR2     = 000C_1A4Dh ; Timer Control Register 2
.TGRE     = 000C_1A74h ; Timer General Register E
.TGRF     = 000C_1A76h ; Timer General Register F
.NFCR7    = 000C_1A94h ; Noise Filter Control Register 7

MTU8:

.NFCR8 = 000C_1298h ; Noise Filter Control Register 8
.TCR   = 000C_1600h ; Timer Control Register
.TMDR1 = 000C_1601h ; Timer Mode Register 1
.TIORH = 000C_1602h ; Timer I/O Control Register H
.TIORL = 000C_1603h ; Timer I/O Control Register L
.TIER  = 000C_1604h ; Timer Interrupt Enable Register
.TCR2  = 000C_1606h ; Timer Control Register 2
.TCNT  = 000C_1608h ; Timer Counter
.TGRA  = 000C_160Ch ; Timer General Register A
.TGRB  = 000C_1610h ; Timer General Register B
.TGRC  = 000C_1614h ; Timer General Register C
.TGRD  = 000C_1618h ; Timer General Register D

GPTW0:

.GTWP      = 000C_2000h ; General PWM Timer Write-Protection Register
.GTSTR     = 000C_2004h ; General PWM Timer Software Start Register
.GTSTP     = 000C_2008h ; General PWM Timer Software Stop Register
.GTCLR     = 000C_200Ch ; General PWM Timer Software Clear Register
.GTSSR     = 000C_2010h ; General PWM Timer Start Source Select Register
.GTPSR     = 000C_2014h ; General PWM Timer Stop Source Select Register
.GTCSR     = 000C_2018h ; General PWM Timer Clear Source Select Register
.GTUPSR    = 000C_201Ch ; General PWM Timer Count-Up Source Select Register
.GTDNSR    = 000C_2020h ; General PWM Timer Count-Down Source Select Register
.GTICASR   = 000C_2024h ; General PWM Timer Input Capture Source Select Register A
.GTICBSR   = 000C_2028h ; General PWM Timer Input Capture Source Select Register B
.GTCR      = 000C_202Ch ; General PWM Timer Control Register
.GTUDDTYC  = 000C_2030h ; General PWM Timer Count Direction and Duty Setting Register
.GTIOR     = 000C_2034h ; General PWM Timer I/O Control Register
.GTINTAD   = 000C_2038h ; General PWM Timer Interrupt Output Setting Register
.GTST      = 000C_203Ch ; General PWM Timer Status Register
.GTBER     = 000C_2040h ; General PWM Timer Buffer Enable Register
.GTITC     = 000C_2044h ; General PWM Timer Interrupt and A/D Converter Start Request Skipping Setting Register
.GTCNT     = 000C_2048h ; General PWM Timer Counter
.GTCCRA    = 000C_204Ch ; General PWM Timer Compare Capture Register A
.GTCCRB    = 000C_2050h ; General PWM Timer Compare Capture Register B
.GTCCRC    = 000C_2054h ; General PWM Timer Compare Capture Register C
.GTCCRE    = 000C_2058h ; General PWM Timer Compare Capture Register D
.GTCCRD    = 000C_205Ch ; General PWM Timer Compare Capture Register E
.GTCCRF    = 000C_2060h ; General PWM Timer Compare Capture Register F
.GTPR      = 000C_2064h ; General PWM Timer Period Setting Register
.GTPBR     = 000C_2068h ; General PWM Timer Period Setting Buffer Register
.GTPDBR    = 000C_206Ch ; General PWM Timer Period Setting Double-Buffer Register
.GTADTRA   = 000C_2070h ; A/D Converter Start Request Timing Register A
.GTADTBRA  = 000C_2074h ; A/D Converter Start Request Timing Buffer Register A
.GTADTDBRA = 000C_2078h ; A/D Converter Start Request Timing Double-Buffer Register A
.GTADTRB   = 000C_207Ch ; A/D Converter Start Request Timing Register B
.GTADTBRB  = 000C_2080h ; A/D Converter Start Request Timing Buffer Register B
.GTADTDBRB = 000C_2084h ; A/D Converter Start Request Timing Double-Buffer Register B
.GTDTCR    = 000C_2088h ; General PWM Timer Dead Time Control Register
.GTDVU     = 000C_208Ch ; General PWM Timer Dead Time Value Register U
.GTDVD     = 000C_2090h ; General PWM Timer Dead Time Value Register D
.GTDBU     = 000C_2094h ; General PWM Timer Dead Time Value Buffer Register U
.GTDBD     = 000C_2098h ; General PWM Timer Dead Time Value Buffer Register D
.GTSOS     = 000C_209Ch ; General PWM Timer Output Protection Function Status Register
.GTSOTR    = 000C_20A0h ; General PWM Timer Output Protection Function Temporary Release Register
.GTADSMR   = 000C_20A4h ; General PWM Timer A/D Converter Start Request Signal Monitoring Register
.GTEITC    = 000C_20A8h ; General PWM Timer Extended Interrupt Skipping Counter Control Register
.GTEITLI1  = 000C_20ACh ; General PWM Timer Extended Interrupt Skipping Setting Register 1
.GTEITLI2  = 000C_20B0h ; General PWM Timer Extended Interrupt Skipping Setting Register 2
.GTEITLB   = 000C_20B4h ; General PWM Timer Extended Buffer Transfer Skipping Setting Register
.GTSECSR   = 000C_20D0h ; General PWM Timer Operation Enable Bit Simultaneous Control Channel Select Register
.GTSECR    = 000C_20D4h ; General PWM Timer Operation Enable Bit Simultaneous Control Register

GPTW1:

.GTWP      = 000C_2100h ; General PWM Timer Write-Protection Register
.GTSTR     = 000C_2104h ; General PWM Timer Software Start Register
.GTSTP     = 000C_2108h ; General PWM Timer Software Stop Register
.GTCLR     = 000C_210Ch ; General PWM Timer Software Clear Register
.GTSSR     = 000C_2110h ; General PWM Timer Start Source Select Register
.GTPSR     = 000C_2114h ; General PWM Timer Stop Source Select Register
.GTCSR     = 000C_2118h ; General PWM Timer Clear Source Select Register
.GTUPSR    = 000C_211Ch ; General PWM Timer Count-Up Source Select Register
.GTDNSR    = 000C_2120h ; General PWM Timer Count-Down Source Select Register
.GTICASR   = 000C_2124h ; General PWM Timer Input Capture Source Select Register A
.GTICBSR   = 000C_2128h ; General PWM Timer Input Capture Source Select Register B
.GTCR      = 000C_212Ch ; General PWM Timer Control Register
.GTUDDTYC  = 000C_2130h ; General PWM Timer Count Direction and Duty Setting Register
.GTIOR     = 000C_2134h ; General PWM Timer I/O Control Register
.GTINTAD   = 000C_2138h ; General PWM Timer Interrupt Output Setting Register
.GTST      = 000C_213Ch ; General PWM Timer Status Register
.GTBER     = 000C_2140h ; General PWM Timer Buffer Enable Register
.GTITC     = 000C_2144h ; General PWM Timer Interrupt and A/D Converter Start Request Skipping Setting Register
.GTCNT     = 000C_2148h ; General PWM Timer Counter
.GTCCRA    = 000C_214Ch ; General PWM Timer Compare Capture Register A
.GTCCRB    = 000C_2150h ; General PWM Timer Compare Capture Register B
.GTCCRC    = 000C_2154h ; General PWM Timer Compare Capture Register C
.GTCCRE    = 000C_2158h ; General PWM Timer Compare Capture Register D
.GTCCRD    = 000C_215Ch ; General PWM Timer Compare Capture Register E
.GTCCRF    = 000C_2160h ; General PWM Timer Compare Capture Register F
.GTPR      = 000C_2164h ; General PWM Timer Period Setting Register
.GTPBR     = 000C_2168h ; General PWM Timer Period Setting Buffer Register
.GTPDBR    = 000C_216Ch ; General PWM Timer Period Setting Double-Buffer Register
.GTADTRA   = 000C_2170h ; A/D Converter Start Request Timing Register A
.GTADTBRA  = 000C_2174h ; A/D Converter Start Request Timing Buffer Register A
.GTADTDBRA = 000C_2178h ; A/D Converter Start Request Timing Double-Buffer Register A
.GTADTRB   = 000C_217Ch ; A/D Converter Start Request Timing Register B
.GTADTBRB  = 000C_2180h ; A/D Converter Start Request Timing Buffer Register B
.GTADTDBRB = 000C_2184h ; A/D Converter Start Request Timing Double-Buffer Register B
.GTDTCR    = 000C_2188h ; General PWM Timer Dead Time Control Register
.GTDVU     = 000C_218Ch ; General PWM Timer Dead Time Value Register U
.GTDVD     = 000C_2190h ; General PWM Timer Dead Time Value Register D
.GTDBU     = 000C_2194h ; General PWM Timer Dead Time Value Buffer Register U
.GTDBD     = 000C_2198h ; General PWM Timer Dead Time Value Buffer Register D
.GTSOS     = 000C_219Ch ; General PWM Timer Output Protection Function Status Register
.GTSOTR    = 000C_21A0h ; General PWM Timer Output Protection Function Temporary Release Register
.GTADSMR   = 000C_21A4h ; General PWM Timer A/D Converter Start Request Signal Monitoring Register
.GTEITC    = 000C_21A8h ; General PWM Timer Extended Interrupt Skipping Counter Control Register
.GTEITLI1  = 000C_21ACh ; General PWM Timer Extended Interrupt Skipping Setting Register 1
.GTEITLI2  = 000C_21B0h ; General PWM Timer Extended Interrupt Skipping Setting Register 2
.GTEITLB   = 000C_21B4h ; General PWM Timer Extended Buffer Transfer Skipping Setting Register
.GTSECSR   = 000C_21D0h ; General PWM Timer Operation Enable Bit Simultaneous Control Channel Select Register
.GTSECR    = 000C_21D4h ; General PWM Timer Operation Enable Bit Simultaneous Control Register

GPTW2:

.GTWP      = 000C_2200h ; General PWM Timer Write-Protection Register
.GTSTR     = 000C_2204h ; General PWM Timer Software Start Register
.GTSTP     = 000C_2208h ; General PWM Timer Software Stop Register
.GTCLR     = 000C_220Ch ; General PWM Timer Software Clear Register
.GTSSR     = 000C_2210h ; General PWM Timer Start Source Select Register
.GTPSR     = 000C_2214h ; General PWM Timer Stop Source Select Register
.GTCSR     = 000C_2218h ; General PWM Timer Clear Source Select Register
.GTUPSR    = 000C_221Ch ; General PWM Timer Count-Up Source Select Register
.GTDNSR    = 000C_2220h ; General PWM Timer Count-Down Source Select Register
.GTICASR   = 000C_2224h ; General PWM Timer Input Capture Source Select Register A
.GTICBSR   = 000C_2228h ; General PWM Timer Input Capture Source Select Register B
.GTCR      = 000C_222Ch ; General PWM Timer Control Register
.GTUDDTYC  = 000C_2230h ; General PWM Timer Count Direction and Duty Setting Register
.GTIOR     = 000C_2234h ; General PWM Timer I/O Control Register
.GTINTAD   = 000C_2238h ; General PWM Timer Interrupt Output Setting Register
.GTST      = 000C_223Ch ; General PWM Timer Status Register
.GTBER     = 000C_2240h ; General PWM Timer Buffer Enable Register
.GTITC     = 000C_2244h ; General PWM Timer Interrupt and A/D Converter Start Request Skipping Setting Register
.GTCNT     = 000C_2248h ; General PWM Timer Counter
.GTCCRA    = 000C_224Ch ; General PWM Timer Compare Capture Register A
.GTCCRB    = 000C_2250h ; General PWM Timer Compare Capture Register B
.GTCCRC    = 000C_2254h ; General PWM Timer Compare Capture Register C
.GTCCRE    = 000C_2258h ; General PWM Timer Compare Capture Register D
.GTCCRD    = 000C_225Ch ; General PWM Timer Compare Capture Register E
.GTCCRF    = 000C_2260h ; General PWM Timer Compare Capture Register F
.GTPR      = 000C_2264h ; General PWM Timer Period Setting Register
.GTPBR     = 000C_2268h ; General PWM Timer Period Setting Buffer Register
.GTPDBR    = 000C_226Ch ; General PWM Timer Period Setting Double-Buffer Register
.GTADTRA   = 000C_2270h ; A/D Converter Start Request Timing Register A
.GTADTBRA  = 000C_2274h ; A/D Converter Start Request Timing Buffer Register A
.GTADTDBRA = 000C_2278h ; A/D Converter Start Request Timing Double-Buffer Register A
.GTADTRB   = 000C_227Ch ; A/D Converter Start Request Timing Register B
.GTADTBRB  = 000C_2280h ; A/D Converter Start Request Timing Buffer Register B
.GTADTDBRB = 000C_2284h ; A/D Converter Start Request Timing Double-Buffer Register B
.GTDTCR    = 000C_2288h ; General PWM Timer Dead Time Control Register
.GTDVU     = 000C_228Ch ; General PWM Timer Dead Time Value Register U
.GTDVD     = 000C_2290h ; General PWM Timer Dead Time Value Register D
.GTDBU     = 000C_2294h ; General PWM Timer Dead Time Value Buffer Register U
.GTDBD     = 000C_2298h ; General PWM Timer Dead Time Value Buffer Register D
.GTSOS     = 000C_229Ch ; General PWM Timer Output Protection Function Status Register
.GTSOTR    = 000C_22A0h ; General PWM Timer Output Protection Function Temporary Release Register
.GTADSMR   = 000C_22A4h ; General PWM Timer A/D Converter Start Request Signal Monitoring Register
.GTEITC    = 000C_22A8h ; General PWM Timer Extended Interrupt Skipping Counter Control Register
.GTEITLI1  = 000C_22ACh ; General PWM Timer Extended Interrupt Skipping Setting Register 1
.GTEITLI2  = 000C_22B0h ; General PWM Timer Extended Interrupt Skipping Setting Register 2
.GTEITLB   = 000C_22B4h ; General PWM Timer Extended Buffer Transfer Skipping Setting Register
.GTSECSR   = 000C_22D0h ; General PWM Timer Operation Enable Bit Simultaneous Control Channel Select Register
.GTSECR    = 000C_22D4h ; General PWM Timer Operation Enable Bit Simultaneous Control Register

GPTW3:

.GTWP      = 000C_2300h ; General PWM Timer Write-Protection Register
.GTSTR     = 000C_2304h ; General PWM Timer Software Start Register
.GTSTP     = 000C_2308h ; General PWM Timer Software Stop Register
.GTCLR     = 000C_230Ch ; General PWM Timer Software Clear Register
.GTSSR     = 000C_2310h ; General PWM Timer Start Source Select Register
.GTPSR     = 000C_2314h ; General PWM Timer Stop Source Select Register
.GTCSR     = 000C_2318h ; General PWM Timer Clear Source Select Register
.GTUPSR    = 000C_231Ch ; General PWM Timer Count-Up Source Select Register
.GTDNSR    = 000C_2320h ; General PWM Timer Count-Down Source Select Register
.GTICASR   = 000C_2324h ; General PWM Timer Input Capture Source Select Register A
.GTICBSR   = 000C_2328h ; General PWM Timer Input Capture Source Select Register B
.GTCR      = 000C_232Ch ; General PWM Timer Control Register
.GTUDDTYC  = 000C_2330h ; General PWM Timer Count Direction and Duty Setting Register
.GTIOR     = 000C_2334h ; General PWM Timer I/O Control Register
.GTINTAD   = 000C_2338h ; General PWM Timer Interrupt Output Setting Register
.GTST      = 000C_233Ch ; General PWM Timer Status Register
.GTBER     = 000C_2340h ; General PWM Timer Buffer Enable Register
.GTITC     = 000C_2344h ; General PWM Timer Interrupt and A/D Converter Start Request Skipping Setting Register
.GTCNT     = 000C_2348h ; General PWM Timer Counter
.GTCCRA    = 000C_234Ch ; General PWM Timer Compare Capture Register A
.GTCCRB    = 000C_2350h ; General PWM Timer Compare Capture Register B
.GTCCRC    = 000C_2354h ; General PWM Timer Compare Capture Register C
.GTCCRE    = 000C_2358h ; General PWM Timer Compare Capture Register D
.GTCCRD    = 000C_235Ch ; General PWM Timer Compare Capture Register E
.GTCCRF    = 000C_2360h ; General PWM Timer Compare Capture Register F
.GTPR      = 000C_2364h ; General PWM Timer Period Setting Register
.GTPBR     = 000C_2368h ; General PWM Timer Period Setting Buffer Register
.GTPDBR    = 000C_236Ch ; General PWM Timer Period Setting Double-Buffer Register
.GTADTRA   = 000C_2370h ; A/D Converter Start Request Timing Register A
.GTADTBRA  = 000C_2374h ; A/D Converter Start Request Timing Buffer Register A
.GTADTDBRA = 000C_2378h ; A/D Converter Start Request Timing Double-Buffer Register A
.GTADTRB   = 000C_237Ch ; A/D Converter Start Request Timing Register B
.GTADTBRB  = 000C_2380h ; A/D Converter Start Request Timing Buffer Register B
.GTADTDBRB = 000C_2384h ; A/D Converter Start Request Timing Double-Buffer Register B
.GTDTCR    = 000C_2388h ; General PWM Timer Dead Time Control Register
.GTDVU     = 000C_238Ch ; General PWM Timer Dead Time Value Register U
.GTDVD     = 000C_2390h ; General PWM Timer Dead Time Value Register D
.GTDBU     = 000C_2394h ; General PWM Timer Dead Time Value Buffer Register U
.GTDBD     = 000C_2398h ; General PWM Timer Dead Time Value Buffer Register D
.GTSOS     = 000C_239Ch ; General PWM Timer Output Protection Function Status Register
.GTSOTR    = 000C_23A0h ; General PWM Timer Output Protection Function Temporary Release Register
.GTADSMR   = 000C_23A4h ; General PWM Timer A/D Converter Start Request Signal Monitoring Register
.GTEITC    = 000C_23A8h ; General PWM Timer Extended Interrupt Skipping Counter Control Register
.GTEITLI1  = 000C_23ACh ; General PWM Timer Extended Interrupt Skipping Setting Register 1
.GTEITLI2  = 000C_23B0h ; General PWM Timer Extended Interrupt Skipping Setting Register 2
.GTEITLB   = 000C_23B4h ; General PWM Timer Extended Buffer Transfer Skipping Setting Register
.GTSECSR   = 000C_23D0h ; General PWM Timer Operation Enable Bit Simultaneous Control Channel Select Register
.GTSECR    = 000C_23D4h ; General PWM Timer Operation Enable Bit Simultaneous Control Register

PMGI0:

.PMGCR = 000C_5880h ; PMGI Configuration Register
.PSMR  = 000C_5884h ; PHY Station Management Register

PMGI1:

.PMGCR = 000C_5890h ; PMGI Configuration Register
.PSMR  = 000C_5894h ; PHY Station Management Register

RSPI0:

.SPCR   = 000D_0100h ; RSPI Control Register
.SSLP   = 000D_0101h ; RSPI Slave Select Polarity Register
.SPPCR  = 000D_0102h ; RSPI Pin Control Register
.SPSR   = 000D_0103h ; RSPI Status Register
.SPDR   = 000D_0104h ; RSPI Data Register
.SPSCR  = 000D_0108h ; RSPI Sequence Control Register
.SPSSR  = 000D_0109h ; RSPI Sequence Status Register
.SPBR   = 000D_010Ah ; RSPI Bit Rate Register
.SPDCR  = 000D_010Bh ; RSPI Data Control Register
.SPCKD  = 000D_010Ch ; RSPI Clock Delay Register
.SSLND  = 000D_010Dh ; RSPI Slave Select Negation Delay Register
.SPND   = 000D_010Eh ; RSPI Next-Access Delay Register
.SPCR2  = 000D_010Fh ; RSPI Control Register 2
.SPCMD0 = 000D_0110h ; RSPI Command Register 0
.SPCMD1 = 000D_0112h ; RSPI Command Register 1
.SPCMD2 = 000D_0114h ; RSPI Command Register 2
.SPCMD3 = 000D_0116h ; RSPI Command Register 3
.SPCMD4 = 000D_0118h ; RSPI Command Register 4
.SPCMD5 = 000D_011Ah ; RSPI Command Register 5
.SPCMD6 = 000D_011Ch ; RSPI Command Register 6
.SPCMD7 = 000D_011Eh ; RSPI Command Register 7
.SPDCR2 = 000D_0120h ; RSPI Data Control Register 2


RSPI1:

.SPCR   = 000D_0140h ; RSPI Control Register
.SSLP   = 000D_0141h ; RSPI Slave Select Polarity Register
.SPPCR  = 000D_0142h ; RSPI Pin Control Register
.SPSR   = 000D_0143h ; RSPI Status Register
.SPDR   = 000D_0144h ; RSPI Data Register
.SPSCR  = 000D_0148h ; RSPI Sequence Control Register
.SPSSR  = 000D_0149h ; RSPI Sequence Status Register
.SPBR   = 000D_014Ah ; RSPI Bit Rate Register
.SPDCR  = 000D_014Bh ; RSPI Data Control Register
.SPCKD  = 000D_014Ch ; RSPI Clock Delay Register
.SSLND  = 000D_014Dh ; RSPI Slave Select Negation Delay Register
.SPND   = 000D_014Eh ; RSPI Next-Access Delay Register
.SPCR2  = 000D_014Fh ; RSPI Control Register 2
.SPCMD0 = 000D_0150h ; RSPI Command Register 0
.SPCMD1 = 000D_0152h ; RSPI Command Register 1
.SPCMD2 = 000D_0154h ; RSPI Command Register 2
.SPCMD3 = 000D_0156h ; RSPI Command Register 3
.SPCMD4 = 000D_0158h ; RSPI Command Register 4
.SPCMD5 = 000D_015Ah ; RSPI Command Register 5
.SPCMD6 = 000D_015Ch ; RSPI Command Register 6
.SPCMD7 = 000D_015Eh ; RSPI Command Register 7
.SPDCR2 = 000D_0160h ; RSPI Data Control Register 2


RSPI2:

.SPCR   = 000D_0300h ; RSPI Control Register
.SSLP   = 000D_0301h ; RSPI Slave Select Polarity Register
.SPPCR  = 000D_0302h ; RSPI Pin Control Register
.SPSR   = 000D_0303h ; RSPI Status Register
.SPDR   = 000D_0304h ; RSPI Data Register
.SPSCR  = 000D_0308h ; RSPI Sequence Control Register
.SPSSR  = 000D_0309h ; RSPI Sequence Status Register
.SPBR   = 000D_030Ah ; RSPI Bit Rate Register
.SPDCR  = 000D_030Bh ; RSPI Data Control Register
.SPCKD  = 000D_030Ch ; RSPI Clock Delay Register
.SSLND  = 000D_030Dh ; RSPI Slave Select Negation Delay Register
.SPND   = 000D_030Eh ; RSPI Next-Access Delay Register
.SPCR2  = 000D_030Fh ; RSPI Control Register 2
.SPCMD0 = 000D_0310h ; RSPI Command Register 0
.SPCMD1 = 000D_0312h ; RSPI Command Register 1
.SPCMD2 = 000D_0314h ; RSPI Command Register 2
.SPCMD3 = 000D_0316h ; RSPI Command Register 3
.SPCMD4 = 000D_0318h ; RSPI Command Register 4
.SPCMD5 = 000D_031Ah ; RSPI Command Register 5
.SPCMD6 = 000D_031Ch ; RSPI Command Register 6
.SPCMD7 = 000D_031Eh ; RSPI Command Register 7
.SPDCR2 = 000D_0320h ; RSPI Data Control Register 2

GLCDC:

;000E_0000h to 000E_03FCh
;Graphic 1 Color Look-up Table 0, 0 to 255
;GR1CLUT00 to GR1CLUT0255

repeat 256, i:0
   .GR1CLUT0#i = 000E_0000h + (4 * i)
end repeat

;000E_0400h to 000E_07FCh
;Graphic 1 Color Look-up Table 1, 0 to 255
;GR1CLUT10 to GR1CLUT1255

repeat 256, i:0
   .GR1CLUT1#i = 000E_0400h + (4 * i)
end repeat

;000E_0800h to 000E_0BFCh
;Graphic 2 Color Look-up Table 0, 0 to 255
;GR2CLUT00 to GR2CLUT0255

repeat 256, i:0
   .GR2CLUT0#i = 000E_0800h + (4 * i)
end repeat

;000E_0C00h to 000E_0FFCh
;Graphic 2 Color Look-up Table 1, 0 to 255
;GR2CLUT10 to GR2CLUT1255

repeat 256, i:0
   .GR2CLUT1#i = 000E_0C00h + (4 * i)
end repeat

.BGEN       = 000E_1000h ; Background Generating Block Operation Control Register
.BGPERI     = 000E_1004h ; Free-Running Period Register
.BGSYNC     = 000E_1008h ; Synchronization Position Register
.BGVSIZE    = 000E_100Ch ; Vertical Size Register
.BGHSIZE    = 000E_1010h ; Horizontal Size Register
.BGCOLOR    = 000E_1014h ; Background Color Register
.BGMON      = 000E_1018h ; Background Generating Block Status Monitor Register
.GR1VEN     = 000E_1100h ; Graphic 1 Register Update Control Register
.GR1FLMRD   = 000E_1104h ; Graphic 1 Frame Buffer Read Control Register
.GR1FLM2    = 000E_110Ch ; Graphic 1 Frame Buffer Control Register 2
.GR1FLM3    = 000E_1110h ; Graphic 1 Frame Buffer Control Register 3
.GR1FLM5    = 000E_1118h ; Graphic 1 Frame Buffer Control Register 5
.GR1FLM6    = 000E_111Ch ; Graphic 1 Frame Buffer Control Register 6
.GR1AB1     = 000E_1120h ; Graphic 1 Alpha Blending Control Register 1
.GR1AB2     = 000E_1124h ; Graphic 1 Alpha Blending Control Register 2
.GR1AB3     = 000E_1128h ; Graphic 1 Alpha Blending Control Register 3
.GR1AB4     = 000E_112Ch ; Graphic 1 Alpha Blending Control Register 4
.GR1AB5     = 000E_1130h ; Graphic 1 Alpha Blending Control Register 5
.GR1AB6     = 000E_1134h ; Graphic 1 Alpha Blending Control Register 6
.GR1AB7     = 000E_1138h ; Graphic 1 Alpha Blending Control Register 7
.GR1AB8     = 000E_113Ch ; Graphic 1 Alpha Blending Control Register 8
.GR1AB9     = 000E_1140h ; Graphic 1 Alpha Blending Control Register 9
.GR1BASE    = 000E_114Ch ; Graphic 1 Background Color Control Register
.GR1CLUTINT = 000E_1150h ; Graphic 1 CLUT/Interrupt Control Register
.GR1MON     = 000E_1154h ; Graphic 1 Status Monitor Register
.GR2VEN     = 000E_1200h ; Graphic 2 Register Update Control Register
.GR2FLMRD   = 000E_1204h ; Graphic 2 Frame Buffer Read Control Register
.GR2FLM2    = 000E_120Ch ; Graphic 2 Frame Buffer Control Register 2
.GR2FLM3    = 000E_1210h ; Graphic 2 Frame Buffer Control Register 3
.GR2FLM5    = 000E_1218h ; Graphic 2 Frame Buffer Control Register 5
.GR2FLM6    = 000E_121Ch ; Graphic 2 Frame Buffer Control Register 6
.GR2AB1     = 000E_1220h ; Graphic 2 Alpha Blending Control Register 1
.GR2AB2     = 000E_1224h ; Graphic 2 Alpha Blending Control Register 2
.GR2AB3     = 000E_1228h ; Graphic 2 Alpha Blending Control Register 3
.GR2AB4     = 000E_122Ch ; Graphic 2 Alpha Blending Control Register 4
.GR2AB5     = 000E_1230h ; Graphic 2 Alpha Blending Control Register 5
.GR2AB6     = 000E_1234h ; Graphic 2 Alpha Blending Control Register 6
.GR2AB7     = 000E_1238h ; Graphic 2 Alpha Blending Control Register 7
.GR2AB8     = 000E_123Ch ; Graphic 2 Alpha Blending Control Register 8
.GR2AB9     = 000E_1240h ; Graphic 2 Alpha Blending Control Register 9
.GR2BASE    = 000E_124Ch ; Graphic 2 Background Color Control Register
.GR2CLUTINT = 000E_1250h ; Graphic 2 CLUT/Interrupt Control Register
.GR2MON     = 000E_1254h ; Graphic 2 Status Monitor Register
.GAMGVEN    = 000E_1300h ; Gamma Correction G Block Register Update Control Register
.GAMSW      = 000E_1304h ; Gamma Correction Block Function Switch Register
.GAMGLUT1   = 000E_1308h ; Gamma Correction G Table Setting Register 1
.GAMGLUT2   = 000E_130Ch ; Gamma Correction G Table Setting Register 2
.GAMGLUT3   = 000E_1310h ; Gamma Correction G Table Setting Register 3
.GAMGLUT4   = 000E_1314h ; Gamma Correction G Table Setting Register 4
.GAMGLUT5   = 000E_1318h ; Gamma Correction G Table Setting Register 5
.GAMGLUT6   = 000E_131Ch ; Gamma Correction G Table Setting Register 6
.GAMGLUT7   = 000E_1320h ; Gamma Correction G Table Setting Register 7
.GAMGLUT8   = 000E_1324h ; Gamma Correction G Table Setting Register 8
.GAMGAREA   = 000E_1328h ; Gamma Correction G Area Setting Register 1
.GAMGAREA   = 000E_132Ch ; Gamma Correction G Area Setting Register 2
.GAMGAREA   = 000E_1330h ; Gamma Correction G Area Setting Register 3
.GAMGAREA   = 000E_1334h ; Gamma Correction G Area Setting Register 4
.GAMGAREA   = 000E_1338h ; Gamma Correction G Area Setting Register 5
.GAMBVEN    = 000E_1340h ; Gamma Correction B Block Register Update Control Register
.GAMBLUT1   = 000E_1348h ; Gamma Correction B Table Setting Register 1
.GAMBLUT2   = 000E_134Ch ; Gamma Correction B Table Setting Register 2
.GAMBLUT3   = 000E_1350h ; Gamma Correction B Table Setting Register 3
.GAMBLUT4   = 000E_1354h ; Gamma Correction B Table Setting Register 4
.GAMBLUT5   = 000E_1358h ; Gamma Correction B Table Setting Register 5
.GAMBLUT6   = 000E_135Ch ; Gamma Correction B Table Setting Register 6
.GAMBLUT7   = 000E_1360h ; Gamma Correction B Table Setting Register 7
.GAMBLUT8   = 000E_1364h ; Gamma Correction B Table Setting Register 8
.GAMBAREA1  = 000E_1368h ; Gamma Correction B Area Setting Register 1
.GAMBAREA2  = 000E_136Ch ; Gamma Correction B Area Setting Register 2
.GAMBAREA3  = 000E_1370h ; Gamma Correction B Area Setting Register 3
.GAMBAREA4  = 000E_1374h ; Gamma Correction B Area Setting Register 4
.GAMBAREA5  = 000E_1378h ; Gamma Correction B Area Setting Register 5
.GAMRVEN    = 000E_1380h ; Gamma Correction R Block Register Update Control Register
.GAMRLUT1   = 000E_1388h ; Gamma Correction R Table Setting Register 1
.GAMRLUT2   = 000E_138Ch ; Gamma Correction R Table Setting Register 2
.GAMRLUT3   = 000E_1390h ; Gamma Correction R Table Setting Register 3
.GAMRLUT4   = 000E_1394h ; Gamma Correction R Table Setting Register 4
.GAMRLUT5   = 000E_1398h ; Gamma Correction R Table Setting Register 5
.GAMRLUT6   = 000E_139Ch ; Gamma Correction R Table Setting Register 6
.GAMRLUT7   = 000E_13A0h ; Gamma Correction R Table Setting Register 7
.GAMRLUT8   = 000E_13A4h ; Gamma Correction R Table Setting Register 8
.GAMRAREA1  = 000E_13A8h ; Gamma Correction R Area Setting Register 1
.GAMRAREA2  = 000E_13ACh ; Gamma Correction R Area Setting Register 2
.GAMRAREA3  = 000E_13B0h ; Gamma Correction R Area Setting Register 3
.GAMRAREA4  = 000E_13B4h ; Gamma Correction R Area Setting Register 4
.GAMRAREA5  = 000E_13B8h ; Gamma Correction R Area Setting Register 5
.OUTVEN     = 000E_13C0h ; Output Control Block Register Update Control Register
.OUTSET     = 000E_13C4h ; Output Interface Register
.BRIGHT1    = 000E_13C8h ; Brightness Adjustment Register 1
.BRIGHT2    = 000E_13CCh ; Brightness Adjustment Register 2
.CONTRAST   = 000E_13D0h ; Contrast Adjustment Register
.PANELDTHA  = 000E_13D4h ; Panel Dither Control Register
.CLKPHASE   = 000E_13E4h ; Output Phase Control Register
.TCONTIM    = 000E_1404h ; Reference Timing Setting Register
.TCONSTVA1  = 000E_1408h ; Vertical Timing Setting Register A1
.TCONSTVA2  = 000E_140Ch ; Vertical Timing Setting Register A2
.TCONSTVB1  = 000E_1410h ; Vertical Timing Setting Register B1
.TCONSTVB2  = 000E_1414h ; Vertical Timing Setting Register B2
.TCONSTHA1  = 000E_1418h ; Horizontal Timing Setting Register A1
.TCONSTHA2  = 000E_141Ch ; Horizontal Timing Setting Register A2
.TCONSTHB1  = 000E_1420h ; Horizontal Timing Setting Register B1
.TCONSTHB2  = 000E_1424h ; Horizontal Timing Setting Register B2
.TCONDE     = 000E_1428h ; Data Enable Polarity Setting Register
.DTCTEN     = 000E_1440h ; Status Detection Control Register
.INTEN      = 000E_1444h ; Interrupt Request Enable Control Register
.STCLR      = 000E_1448h ; Detected Status Clear Register
.STMON      = 000E_144Ch ; Detected Status Monitor Register
.PANELCLK   = 000E_1450h ; Panel Clock Control Register


DRW2D:

.CONTROL   = 000E_3000h ; Geometry Control Register
.STATUS    = 000E_3000h ; Status Register
.CONTROL2  = 000E_3004h ; Surface Control Register
.HWVER     = 000E_3004h ; Hardware Version Register
.L1START   = 000E_3010h ; Limiter 1 Start Value Register
.L2START   = 000E_3014h ; Limiter 2 Start Value Register
.L3START   = 000E_3018h ; Limiter 3 Start Value Register
.L4START   = 000E_301Ch ; Limiter 4 Start Value Register
.L5START   = 000E_3020h ; Limiter 5 Start Value Register
.L6START   = 000E_3024h ; Limiter 6 Start Value Register
.L1XADD    = 000E_3028h ; Limiter 1 X-Axis Increment Register
.L2XADD    = 000E_302Ch ; Limiter 2 X-Axis Increment Register
.L3XADD    = 000E_3030h ; Limiter 3 X-Axis Increment Register
.L4XADD    = 000E_3034h ; Limiter 4 X-Axis Increment Register
.L5XADD    = 000E_3038h ; Limiter 5 X-Axis Increment Register
.L6XADD    = 000E_303Ch ; Limiter 6 X-Axis Increment Register
.L1YADD    = 000E_3040h ; Limiter 1 Y-Axis Increment Register
.L2YADD    = 000E_3044h ; Limiter 2 Y-Axis Increment Register
.L3YADD    = 000E_3048h ; Limiter 3 Y-Axis Increment Register
.L4YADD    = 000E_304Ch ; Limiter 4 Y-Axis Increment Register
.L5YADD    = 000E_3050h ; Limiter 5 Y-Axis Increment Register
.L6YADD    = 000E_3054h ; Limiter 6 Y-Axis Increment Register
.L1BAND    = 000E_3058h ; Limiter 1 Band Width Parameter Register
.L2BAND    = 000E_305Ch ; Limiter 2 Band Width Parameter Register
.COLOR1    = 000E_3064h ; Base Color Register
.COLOR2    = 000E_3068h ; Secondary Color Register
.PATTERN   = 000E_3074h ; Pattern Register
.SIZE      = 000E_3078h ; Bounding Box Dimension Register
.PITCH     = 000E_307Ch ; Frame Buffer Pitch Register
.ORIGIN    = 000E_3080h ; Frame Buffer Base Address Register
.LUST      = 000E_3090h ; U Limiter Start Value Register
.LUXADD    = 000E_3094h ; U Limiter X-Axis Increment Register
.LUYADD    = 000E_3098h ; U Limiter Y-Axis Increment Register
.LVSTI     = 000E_309Ch ; V Limiter Start Value Integer Part Register
.LVSTF     = 000E_30A0h ; V Limiter Start Value Fractional Part Register
.LVXADDI   = 000E_30A4h ; V Limiter X-Axis Increment Integer Part Register
.LVYADDI   = 000E_30A8h ; V Limiter Y-Axis Increment Integer Part Register
.LVYXADDF  = 000E_30ACh ; V Limiter Increment Fractional Parts Register
.TEXPITCH  = 000E_30B4h ; Texels Per Texture Line Register
.TEXMSK    = 000E_30B8h ; Texture Mask Register
.TEXORG    = 000E_30BCh ; Texture Base Address Register
.IRQCTL    = 000E_30C0h ; Interrupt Control Register
.CACHECTL  = 000E_30C4h ; Cache Control Register
.DLISTST   = 000E_30C8h ; Display List Start Address Register
.PERFCNT1  = 000E_30CCh ; Performance Counter 1
.PERFCNT2  = 000E_30D0h ; Performance Counter 2
.PERFTRG   = 000E_30D4h ; Performance Counters Control Register
.TEXCLADDR = 000E_30DCh ; CLUT Start Address Register
.TEXCLDATA = 000E_30E0h ; CLUT Data Register
.TEXCLOFST = 000E_30E4h ; CLUT Offset Register
.COLKEY    = 000E_30E8h ; Chroma Key Register

OFSM:

.MDE     = FE7F_5D00h ; Endian Select Register
.OFS0    = FE7F_5D04h ; Option Function Select Register 0
.OFS1    = FE7F_5D08h ; Option Function Select Register 1
.TMINF   = FE7F_5D10h ; TM Identification Data Register
.BANKSEL = FE7F_5D20h ; Bank Select Register
.SPCC    = FE7F_5D40h ; Serial Programmer Command Control Register
.TMEF    = FE7F_5D48h ; TM Enable Flag Register
.OSIS    = FE7F_5D50h ; OCD/Serial Programmer ID Setting Register
.FAW     = FE7F_5D64h ; Flash Access Window Setting Register
.ROMCODE = FE7F_5D70h ; ROM Code Protection Register
