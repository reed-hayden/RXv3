FLASH:

.ROMCE    = 0008_1000h ; ROM Cache Enable Register
.ROMCIV   = 0008_1004h ; ROM Cache Invalidate Register
.NCRG0    = 0008_1040h ; Non-Cacheable Area 0 Address Register
.NCRC0    = 0008_1044h ; Non-Cacheable Area 0 Setting Register
.NCRG1    = 0008_1048h ; Non-Cacheable Area 1 Address Register
.NCRC1    = 0008_104Ch ; Non-Cacheable Area 1 Setting Register
.FWEPROR  = 0008_C296h ; Flash P/E Protect Register
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
.UIDR0 = 0FE7F_7D90h ; Unique ID Register 0
.UIDR1 = 0FE7F_7D94h ; Unique ID Register 1
.UIDR2 = 0FE7F_7D98h ; Unique ID Register 2
.UIDR3 = 0FE7F_7D9Ch ; Unique ID Register 3
