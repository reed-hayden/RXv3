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
.EXNMICLR  = 0008_7586h ; Expanded Non-Maskable Interrupt Status Clear Register
.NMIFLTE   = 0008_7590h ; NMI Pin Digital Filter Enable Register
.NMIFLTC   = 0008_7594h ; NMI Pin Digital Filter Setting Register
.GRPIE0    = 0008_75B0h ; Group IE0 Interrupt Request Register
.GENIE0    = 0008_75B4h ; Group IE0 Interrupt Request Enable Register
.GCRIE0    = 0008_75B8h ; Group IE0 Interrupt Clear Register
.GRPBE0    = 0008_7600h ; Group BE0 Interrupt Request Register
.GRPBL0    = 0008_7630h ; Group BL0 Interrupt Request Register
.GRPBL1    = 0008_7634h ; Group BL1 Interrupt Request Register
.GRPBL2    = 0008_7638h ; Group BL2 Interrupt Request Register
.GENBE0    = 0008_7640h ; Group BE0 Interrupt Request Enable Register
.GENBL0    = 0008_7670h ; Group BL0 Interrupt Request Enable Register
.GENBL1    = 0008_7674h ; Group BL1 Interrupt Request Enable Register
.GENBL2    = 0008_7678h ; Group BL2 Interrupt Request Enable Register
.GCRBE0    = 0008_7680h ; Group BE0 Interrupt Clear Register
.PIBR0     = 0008_7700h ; Software Configurable Interrupt B Request Register 0
.PIBR1     = 0008_7701h ; Software Configurable Interrupt B Request Register 1
.PIBR2     = 0008_7702h ; Software Configurable Interrupt B Request Register 2
.PIBR3     = 0008_7703h ; Software Configurable Interrupt B Request Register 3
.PIBR4     = 0008_7704h ; Software Configurable Interrupt B Request Register 4
.PIBR5     = 0008_7705h ; Software Configurable Interrupt B Request Register 5
.PIBR6     = 0008_7706h ; Software Configurable Interrupt B Request Register 6
.PIBR7     = 0008_7707h ; Software Configurable Interrupt B Request Register 7
.PIBR8     = 0008_7708h ; Software Configurable Interrupt B Request Register 8
.PIBR9     = 0008_7709h ; Software Configurable Interrupt B Request Register 9
.PIBRA     = 0008_770Ah ; Software Configurable Interrupt B Request Register A
.PIBRB     = 0008_770Bh ; Software Configurable Interrupt B Request Register B
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