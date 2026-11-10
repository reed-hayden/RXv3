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