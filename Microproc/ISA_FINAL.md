#Instruction Set Arquitechture

## SUM

`SUM R1 R2 RS`
`[R1 + R2] >> RS`


## SUB

`SUB R1 R2 RS`
`[R1-R2] >> RS`


## MULT

`MULT R1 R2 RS`
`[R1*R2] >> RS`


## DIV

`DIV R1 R2 RS`
`[R1/R2] >> RS`


## LOAD

`LOAD @dir R padding`
`[@dir] >> R`



## STORE

`STORE @dir R padding`
`[R] >> @dir`


## JZ

`JZ R @IM_dir padding`
`if([R]==0){jump to @IM_dir}`


## JNZ

`JNZ R @IM_dir padding`
`if([R]!=0){jump to @IM_dir}`

## JEQ

`JEQ R1 R2 @IM_dir`
`if([R1]==[R2]){jump to @IM_dir}`

## JNEQ


`JEQ R1 R2 @IM_dir`
`if([R1]!=[R2]){jump to @IM_dir}`

## AND

`AND R1 R2 RS`
`[R1&R2] >> RS`


## OR 

`OR R1 R2 RS`
`[R1|R2] >> RS`
