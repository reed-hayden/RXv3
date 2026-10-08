The following file 'rx.inc' contains calminstructions to assemble the RX v3 instruction set.
The optional double precision floating point coprocessor instructions are included.

This assembler was for personal use but I thought I should share it.

The syntax is not the same as in the official ISA. I have altered it to be similar to the usual fasm x86 syntax.
Mostly chaging from src,dst --> dst,src
e.g.


Official: mov.B    R2, 123[R1]
Altered : mov      byte [R1+123], R2

Official: mov      [R1+], R2
Altered : mov      R2, [R1]+

Official: mov      R1, [R3,R2]      ;index,base 
Altered : mov      [R2+R3], R1      ;base+index

Official: dpopm.D  DR1-DR5
Altered : dpopm    DR1, DR5

Official: bfmov    #5, #10, #3, R1, R2
Altered : bfmov    R2, R1, 3, 10, 5

Official: add      R1, R2, R3        ;src,src2,dst
Altered : add      R3, R1, R2        ;dst,src,src2
    

The syntax is different due to personal preference and ease of implementation.
The macros themselves owe a great deal to the lovely 'x86-2.inc' from fasm2, of which I have pilfered the main operand parsing.

This was the first experience I've had with macros so expect a good amount of kludge.
The assembler has been lightly tested for accuracy against the GNU rx-elf-as assembler. Do not assume it is 100% correct.

The reference document for the ISA is "RX Family RXv3 Instruction Set Architecture User’s Manual: Software".
Do note that the document has several errors which have been corrected in this assembler via crossreference with rx-elf-as.
e.g. STNZ and STZ encoding, note.1 pg 237 vs pg 368.


-Reed-
