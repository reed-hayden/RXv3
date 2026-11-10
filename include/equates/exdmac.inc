include 'exdmac/exdmac0.inc'
include 'exdmac/exdmac1.inc'

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