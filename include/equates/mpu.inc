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