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