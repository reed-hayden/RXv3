CAN0:

;0009_0200h to 0009_03FFh
;Mailbox Register 0 to 31
;MB0 to MB31

repeat 32, i:0
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