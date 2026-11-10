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

.NFCR4    = 000C_1294h ; Noise Filter Control Register 4
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