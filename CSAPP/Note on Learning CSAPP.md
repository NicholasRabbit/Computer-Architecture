### Website

[CS 15-213](https://www.cs.cmu.edu/~213/index.html)

**Textbook** :  Computer Systems: A Programmer's Perspective, 3/E 

### Tips

[Tips on learning CS 15-213](https://csdiy.wiki/en/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%B3%BB%E7%BB%9F%E5%9F%BA%E7%A1%80/CSAPP/#descriptions)

```txt
If you have trouble with Chapter 7 Linking, I recommend reading the book Programmer's Self-Cultivation, subtitled link. load and library. This book can complete our understanding of program linking, and I believe after reading this book you will have a deeper comprehension of program linking, ELF files, and dynamic libraries. It is highly recommended to be read as a supplementary material after reading CSAPP and having a certain understanding of computer systems.
```

### Chapter 1. Tour of Computer Systems

#### 0, Programs are translated by other programs into different forms

![1715072855978](note-images/1715072855978.png)

gcc commands

```shell
# commands
# 1, hello.i
gcc -E hello.c -o hello.i / cpp hello.c -o hello.i # preprocessing 

# 2, hello.s
gcc -S hello.i  # translated into hello.s which is a assembly programme
# Or
gcc -S hello.c # skip the preprocess

# 3, hello.o
gcc -c hello.s -o hello.o  # relocatable object programs
# Or
as hello.s -o hello.o
# Or
gcc -c hello.c -o hello.o  # skip some steps

# 4, hello  
gcc hello.o -o hello # executable object program
```

#### 1, Shifting bits

In the low level of the computer system shifting bits is quite faster than multiplication. If the former costs one clock cycle, the latter will normally cost 13 to 17 clock cycles.  Nowadays the speed of multiplication has  increased dramatically but it still costs 4 clock cycles. While 4 is bigger than one anyway.

- What will happen if shifting 8 bits for a byte ?

#### 2, Signed and Unsigned

1. What will happened when a signed number is calculated with an unsigned number?
   The signed number will cast to a unsigned number. 

#### 3, Truncate a number

Truncating a number is like a module operation.

```txt
# 4 bits overflow so the most significant number is truncated.
1 1101 : 27
  1101 : 11   #27 % 16 = 11
```



#### 4, Important Themes

Chapter 1.9

1.9.1 Amdahl's Law
$$
S = \frac{1}{(1-a)+a/k}
$$
The processing speed of a system or an application won't be increased significantly if  only to improve the performance of a small part of the system. If we assumed that k is infinite the result would be $S=\frac{1}{1-a}$. In other words, if a is small the S won't be too large.

#### 5, Process and thread

##### 1, Concurrency

In the abstract level of thread, for **traditional thread** concurrent execution is simulated.  Whereas, **hyperthreading**, sometime called "simultaneous multi-threading", is a technique that allows a singly core of the CPU to execute multiple flows of control.

#### 6, Summary

Chapter 1.10  Summary

1) A file is a sequence of bytes.

2) Storage devices that are in higher levels serves as caches for the devices in the lower levels. Programmers can optimize their C programmes by understanding and exploiting the memory hierarchy.

3) The operating system kernel serves as an intermediary between the application and the hardware. 

### Part I 

Programme Structure and Execution

#### Binary bits and overflow

Computer representations use a limited number of bits to encode a number. For example, if we use 4 bits to represent number the maximum number is  $2^4 - 1 = 31$, and the operation to represent 32 can lead to overflow. 

```shell
# The default length of the number in gdb is 4 bytes which is 32 bits.
>gdb
>print 200*300*400*500  # output -884,901,888
```

#### 2.1.1 Hexadecimal Notation

When we say x is a power of 2, that is, $x=2^n$. We can also say that its binary representation is that 1 followed by $n$ zeros. For example, $8=2^3$ is  1000(binary). While a hexadecimal digit represents 4 digits in binary, namely 0 in hex mean 0000 in binary. So we can represent $2^{11} $ by a hexadecimal number which is `0X800`.  Because `0x8`=`0b1000` and `0x00`=`0b0000,0000`.

Tips:

Remembering binary representations of  three keys hexadecimal numbers could help you calculate representations of rest hexadecimals effectively.

A: 1010,   C: 1100,  F:1111

#### 2.1.2 Data Sizes

Every computer has a *word size* which indicates the nominal size of a pointer data. The size of any data type in computer is not limitless such as the sizes of an integer and long number are 4 and 8 bytes, respectively. 

As a programmer, we must be extremely cautious when are calculating numbers to prevent catastrophe which is caused by overflow. For example, in the 2's complement system the range of a char(1 byte)is from `-128~127`, if we add 100 to 50 the result is 150 which actually represents -106. 

#### 2.1.3 Addressing and Byte Ordering

Each byte has its own address in computer system. As programme files such as source file(\*.c), assembly file(\*.s), relocatable object file(\*.o) and executable file(\*.out) which all span multiple bytes, it is necessary for every byte having its address or it could be chaotic and the monolithic pillars may collapse.

Little endian and big endian.

**Little endian**: The least significant byte is stored in the place with the  smallest address and the most significant byte is stored in the place with the biggest address. The rest bytes are stored sequentially.

One important thing about little endian is when we are reading the machine-level program representations the least significant byte is on the left and the most significant is on the right and that is contrary to the normal way that we read numbers in real world. We should used to write the machine-level program from the right side to the left so that it is easy to read.

For example: 

```shell
40054b:	bf 04 06 40 00       	mov    $0x400604,%edi
```

Suppose that `40054b` is the address of an integer number(4 bytes), we should write the bytes conversely 
like `40 06 04 bf ` so that we can read it like what we do in math class.

**Big endian**: It is the opposite of little endian.

Note: See "[Analysis of Storage]("..\C-Code\26_AssemblyLanguage_And_Storage\Analysis of Storage.md")" for more about address, little endian and big endian.



#### Practice Problem 2.6

Why the hexadecimal presentation of  `3510593.0` is `0x4A1F23E0` in the 3rd edition of the book and is `0x4A564504` in 2nd edition? 

I also got the later result.  Why is that?

#### 2.1.6  Introduction to Boolean Algebra

There is a bit vector with indexes like $[a_{w-1}, a_{w-2}, ..., a_1, a_0]$.  For example,  a = [01101001]  encodes the set A = {0,3,5,6}. We should match the indexes from left to right such as 0 in $a_0$, 3 in $a_1$, 5 in $a_5$ and 6 in $a_6$, respectively.  \(P88\)

#### 2.1.7 Bit-Level Operations in C

#### 2.1.9 Shifting Operations in C

1) What the differences between logical and arithmetic shift?

We assumed that shifting *k* bits to the right like *a* >> *k*.

A logical shift fills the left end with k zeros. For example, `1100,0101 >> 2`  = `0011,0001`.

A arithmetic shift fills the left end with **k repetitions of the most significant bit**.  For example, 
 `1100,0101 >> 2`  = `1111,0001`  and `0101,1101 >> 2` = `0001,0111`. Note: not always filled with `1`.

2) What will happen if the shifting value is larger the the total bits of the number?

In C standards the statement was carefully avoid. Normally, shifting such a large value is meaningless while for some other languages like Java the result equals k%w(k: shifting bits, w: the word's bits). 

For example, `1100 >> 6` means `1100 >> (6%4)`.

#### 2.2 Integer representations

**1) The "-2147483648" can't be printed directly in C.**

```c
// 22_Data_Type.c (C code)
/*
	 * Chapter 15.1 《Linux C 一站式编程》
	 * Althought the range of int is from -2147483648 to +2147483647，
	 * in x86 platform it is a combination of "-" and "2147483648" in the aspect of the compiler.
	 * Apparently, the 2147483648 is beyond the range of integer and it  the type of "long int".
	 * */
	// warning: format ‘%d’ expects argument of type ‘int’, 
	// but argument 2 has type ‘long int’ [-Wformat=]: 
	printf("%d\n", -2147483648);  
	
	// However, the following code is correct without any warnings.
	printf("%d\n", -2147483647 - 1);  
```

Note: The two's-complement is asymmetric- $|T_{min}|=|T_{max} + 1|$. That could lead to subtle program bugs.

**2) Conversions between signed and unsigned.  (Chapter 2.2.4)**

Casting a signed value to an unsigned value in C doesn't changed the bit representation. The effect of casting is to keep the bit values identical but change how these bits are interpreted, for instance, `1111, 1111` represents 255 as an unsigned number while it represents as -1 as a signed number.

**3) In C the signed value will be cast to unsigned when it is compared to an unsigned number**

```c
-1 < 0U // -1 = 2^8, the result is 0(false).
```

See my C code about unsigned and signed value. (29_Unsigned_and_Signed)

#### 4) 2.2.6 Expanding the Bit Representation of a Number

(1) To convert an unsinged number to a larger data type we simply add leading zeros  to the representation.

```c
unsigned short us = 0x3c9f;
unsigned int ui = us;   // ui = 0x00003c9f
```

(2) Whereas, to convert an signed number to a larger data type we should add copies of the most significant bit to the leading representation.

```c
/*
* Signed
* =9, the length of short data type is 2 bytes. 
* The most significant bit of "sx" is 0, not 1 because we get the bit at 
* the head of 2 bytes. sx is a positive number.
*/
short sx = 0b0000,0000,0000,1010; 
int x = 0b0000...1010;
// If sx
short sx = 0b1000,0000,0000,1010;  // -10   
int x = 0b1111...1010;
```

See  my code:`CSAPP/code/code_examples/2.2.6_expanding_bits`

**(3) Pay attention the order of conversion from a short data to a larger one.**

When converting short to unsigned, we first change the size form 2 bytes to 4 bytes so that the result is 0xff on the leading bits and then from signed to unsigned.

 **NOT:** if we first change the signed number to unsigned and then changed the size
the result would be 0x00c7cf. But it is not the way in which C works.

See: ` CSAPP/code/code_examples/2.2.6_expanding_bits/order_of_expanding_bits .c`



