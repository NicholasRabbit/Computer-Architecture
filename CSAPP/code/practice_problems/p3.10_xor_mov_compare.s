
# Practice Problem 3.10

# A simple assembly program which returns 4 in %ebx.
# 
# CLI commands:
# as assembly_test.s -o assembly_test.o
# ld assembly_test.o -o assembly_test.out 
# objdump -d assembly_test.o  // disassemble the object file to check how many bytes that 

# 
# Then execute the :
# ./assembly_test.out
# echo $? // to get the return value of the last programmme.


.section .data 

.section .text

.globl _start


_start:

xorl %edx, %edx

movl $0, %edx



#A segmentatioin error would occur if the following code were commented out.
int $0x80  # int: interupt

