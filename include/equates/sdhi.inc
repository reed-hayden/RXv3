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