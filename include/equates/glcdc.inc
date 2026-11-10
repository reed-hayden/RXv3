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