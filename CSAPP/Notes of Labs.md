### 1, Preparation for the labs 

[Preparation for the laboratories](https://blog.csdn.net/qq_45677541/article/details/123955438)

**Solution of errors**

(1) "fatal error gnu/stubs-32.h no such file or directory "

Running `make btest` on a machine of 64-bit representation of integers may cause an error(`fatal error gnu/stubs-32.h no such file or directory `).  The solution is given as follows.

Solution:

```shell
# You need install the glibc-devel.i386 package because the labs need machine of 32-bit 
# representations of integers.
yum -y install glibc-devel.i386   # Centos 6/7
```

### 2, How to test?

In the root directory of `datalab-handout` , run the following commands if you complete the code.

Step 1:  Read `bits.c` and modify it.

Step 2:  Run  ` ./dlc -e bits.c ` to check the legality of your solutions.

```shell
 # or
 ./dlc bits.c  # if your solution is legal, there is nothing output.
```

Step 3: Run `make clean`  and `make btest`  to compile the source code.

Step 4: Run `./btest`  test harness to check your functions for correctness.

Step 5: Run `./driver.pl` to grade your work automatically.

[datalab: Page 4 and 5.](./labs/L1_Data_Lab/datalab.pdf)

### 3, Laboratory

#### Data Labs

##### 1, tMin

```shell
/* 
 * tmin - return minimum two's complement integer  
 * In two's complement the bits representation of a negative number begins with 1, 
 * return it.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
```

##### 7, conditional

1, `x ? y : z`  equals $F =xy + \overline xz$. 

In the equation $xy$ is  Boolean  operation yields the same result as of $x\&y$ and the plus $+$ means $OR(|)$. 

 ```c
int conditional(int x, int y, int z) {
	// x has been converted to ~x here. so the '~x&y' represents 'xy' in the equation 
    // "F=xy+.."
    x = ~(!x) + 1;  
	return (~x & y) + (x & z);
}
 ```

Elaboration of the solution:

N.B. All the operations are dealt with bits. 

To explain the logic process of the solution needs to start with the equation $F =xy + \overline xz$. If we would like to return $y$ when the original $x$ is not 0, we should convert it to a mask-$0XFFFFFFFF$- because the $AND$ result of a mask and a bit is the bit itself. For example,  `0xff & 0x11` is `0x11`. 

Apparently, `x = ~(!x) + 1` is an approach aiming to produce the mask. When `x` is non-zero, `!x` is 0 and the operation on the right side of `=` yields `0`  which is then flipped to produce `0xFFFFFFFF` in the operation: `(~x + y)`.  By now, the first part, $xy$,  in  $F =xy + \overline xz$ is made. Note that `~x` in the code `(~x & y)` represents $x$ in the equation. If `x` is zero, it is the same process.

##### 8, isLessOrEqual

See ` CSAPP/labs/testing_code_for_labs`

```java
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	return 2;
}
```

**Analyses**(plural)

Equation:  $x \le y$ equals $y-x \le 0$

There are two possibilities of these two operands. One is that they have the same sign. The other is that they have distinct signs.

**(1) Same sign.**

In this circumstance, two requirements have to be met. First is they have the same sign and second is $y-x\le0$.

1. One of the facts we should know is that if $x$ and $y$ have the same sign, $x-y$ will not cause any overflow. 
   For instance, if $w=4$,  any 4-bit number is in the range of $-8\le{x}\le7$ . 
   Calculations of operands with same operands such as $7-1=6$,  $-8-(-1)=-7$ and so forth don't cause overflow. 
   Another fact is that the operation of two numbers with different sign will lead to overflow in . For example, int $1-(-8) = 9$ the 9 is bigger than the maximum value(7). 
   **N.B.** `0` is considered as a positive number since $0-7=-7\le8$ while $0-(-8)=8$(overflow).

2. For $y-x\le0$ we expect that the result is $0$, but it should be converted to $1$ which represents `true` in C. 

   ```c
    11 int has_same_sign(int x, int y)
    12 {
    13     int sign_a = x >> 31 & 1;
    14     int sign_b = y >> 31 & 1;
    15
    16     /*
    17      * 1, Whether the two operands have the same sign.
    18      * If these two operands, x and y, have the same sign, 'same_sign' is 0.
    19      * Whereas,by convention in C '1' and '0' represent 'true' and 'false', respectively.
    20      * So we should get the NOT of 'same_sign'.
    21      * */
    22     int same_sign = !(sign_a ^ sign_b);
    23
    24     return same_sign;
    25
    26 }
    27
    28 // The subtraction of two operands with same sign
    29 int subtract_result_of_same_sign(int x, int y)
    30 {
    31     /*
    32      * We expect that y - x <= 0.
    33      * */
    34     int res = (~x + 1) + y;
    35     // As aforemented, 0 should be converted to 1 to represent 'true'.
    36     res = !(res >> 31);
    37
    38     return res;
    39
    40 }
   
   ```

**(2) Distinct signs**

```c
 55 /*
 56  * II, The two operands have distinct signs.
 57  * It is simpler in this circumstance and what we need to do is to find whether 'x'
 58  * is positive or not. If x is a positive number or 0, y must be a negative one.
 59  * */
 60 int operation_of_distinct_sign(int x, int y)
 61 {
 62     int sign_x = x >> 31 & 1;
 63     int sign_y = y >> 31 & 1;
 64     // 'distinct' will be '1' if the two signs are different.
 65     int distinct = sign_x ^ sign_y;
 66
 67     // If x is negative then 'sign_x' is 1 and y must be positive or zero,
 68     // so flag is 1, which indicates that x <= y. On the other hand, it is the same.
 69     int flag = sign_x & distinct;
 70
 71     return flag;
 72 }
```

##### 9, logicalNeg

See `../ CSAPP/labs/testing_code_for_labs/logicalNeg.c`

##### 10, howManyBits

```c
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  return 0;
}
```

In two's complement, for instance, a positive number with the most significant 1 at x must be represented by at least "x + 1" bits. Such as `5(101)` should be used at least 4 bits-`0101` because there should be negative numbers which has 1 in the most significant bit by the convention of two's complement. Thus we can take advantage of this property to solve the problem. 

1) The first step is how to find the most significant "1".

For negative numbers, the leading bit is `1`. 

Elaboration of the following solution.

> Assuming that `x` is one-byte, we can conclude as follows.
>
> If `x` is negative, `sign` is`0b1111_1111`  and `abs_x = (sign & ~x) | (~sign & x) ` computes a value which is just 1 less than its absolute value. For instance, for `-128` the result of the computation is `127`. 
>
> If `x` is positive, `sign` is `0b0000_0000` and `abs_x` in the equation has not been changed. For example, the result is still `120` if an argument is `120`.
>
> In conclusion, as in two's complement numbers are asymmetric, the so-called absolute value of a negative is 1 less than its real arithmetic absolute value(`abs_x=127` when `x` is `-128`), but the absolute value of a positive number is the same as its arithmetic absolute value.

```c
int howManyBits(int x) {
  int sign = x >> 31;
  int abs_x = (sign & ~x) | (~sign & x);
  int b16, b8, b4, b2, b1, b0;
  b16 = !!(abs_x >> 16) << 4;
  abs_x = abs_x >> b16;
  b8 = !!(abs_x >> 8) << 3;
  abs_x = abs_x >> b8;
  b4 = !!(abs_x >> 4) << 2;
  abs_x = abs_x >> b4;
  b2 = !!(abs_x >> 2) << 1;
  abs_x = abs_x >> b2;
  b1 = !!(abs_x >> 1);
  abs_x = abs_x >> b1;
  b0 = abs_x;
  return b16 + b8 + b4 + b2 + b1 + b0 + 1;
}
```

> The following computation aims to find out whether there is any `1` in the leftmost 16 bits. If so, it needs 16 + 1 bits at least.
>
> `abs_x >> 16` truncates the rightmost 16 bits. If there is any bit in the leftmost 16 bits, `!!(abs_x >> 16)`  is 1 so the result of `1<<4` is 16 which indicates that it needs $16+1$ bits. 
>
> Then we keep on squeezing the leftmost 16 bits by shifting `b16`(its value is either 0 or 16).
>
> And then repeat until the last bits.

```c
b16 = !!(abs_x >> 16) << 4;
abs_x = abs_x >> b16;
```

##### 11, floatScale2

```c
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  return 2;
}
```

According to IEEE floating-point standard, a floating-point number is represented by 4 bytes(32 bits). The most significant bit indicates the sign; the following 8 bits, which in the range between 32 to 23, represents the exponent while the rest 23 bits is the value of fraction. 

There are three cases of the argument `f`. Whereas, the sign is either $-1$ or $1$ in any circumstances.

**Preparation: Extract three parts of a floating-point number**

The exponent is in the range between 1 and 254 and the fraction is represented by the least 23 bits with an implicit leading bit - 1.

1) Extract the bit representing the sign

```c
unsigned s = uf >> 31;
```

2) Slice the bits and get the exponent.

```c
// The aim of using AND(&) is to eliminate the sign bit.
unsigned exp = (uf >> 23) & 0xff;
```

3) Whereas, the original exponent should be replaced by the new one. So we change the most significant 9 bits to 0s then we join `exp` into the result later. 

```c
// To eliminate the sign and the exponent by having the leading 9 bits become 0s.
//unsigned frac = (uf << 9) >> 23;  // This line of code is buggy.
unsigned frac = (uf << 9) >> 9; // It should be shifted right by 9 bits, too.
```

1. **Normalised Values**

   1.1 Since it is a normalised value, we can only just add 1 to the exponent to implement the multiplication of `2*f`. 

   ```c
   exp += 1;
   ```

   1.2 Combine all of the three parts.

   ```c
   unsigned result = s << 31 | exp << 23 | frac;
   ```

2. **Denormalised Values**

   Attention should be paid is when the fraction is all 0s in the normalised case.

   The exponent of all denormalised values are all 0's and by the IEEE floating=point standard there is NOT  an implicit 1 to be added to the fraction. So the denormalised values are always smaller than 0.

   ```c
   // Condition
   exp == 0;
   // Multiply the fraction and 2 directly.
   frac = frac << 1;
   ```

   Combine all of the three parts, too.

   ```c
   unsigned result = s << 31 | exp << 23 | frac;
   ```

3. **NaN**

   When all of the bits of the exponent are 1s, it is a NaN.

   There are a total of 8 bits in single precision so the condition is as follows.

   `exp == 0xff;` 

```c
unsigned floatScale2(unsigned uf) {
	// 1. To extract the sign.
	unsigned s = uf >> 31;
	// 2. To slice the exponent.
	unsigned exp = (uf >> 23) & 0xff;
	// 3. To retrive the fractional part. 
	unsigned frac = (uf << 9) >> 9; 

	// NaN
	if (exp == 0xff)
		return uf;
	// Denormalised Values. It is not necessary to add the implicit leading "1"
	// to the significand.Thus, we only need to multiply the fraction and 2.
	else if (exp == 0x0) {
		/*
		 * Note that if the leading bit of the fraction is 1, the least significant
		 * bit of the exponent will become 1 after carrying the 1 from "frac << 1".
		 * Whereas, there is no need to handle this "1" because it will become a normalised
		 * value and the reslut is correct. Presumably, IEEE has already designed deliberately.
		 * */
		frac = frac << 1;
		return (s << 31) | (exp <<23) | frac;
	}
	// Normalised Values
	else
		// Implementing 2*f by adding 1 to the exponent.
		exp += 1; 

	return (s << 31) | (exp <<23) | frac;

}
```

##### 12, floatFloat2Int

```c
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  return 2;
}
```

What does it ask us to do?

It asks us to convert a float value, which is represented by an unsigned integer, to its equivalent integer form. See page 143 in CSAPP; in that page an integer value is converted to its float-point form. Here we reverse that process.

A Solution:

1. Decompose the float value into 3 fields, which are a sign, an exponent and a fraction. 

   ```c
   unsigned sign = uf >> 31;
   unsigned exp = (uf >> 23) & 0xff;
   unsigned frac = (uf << 9) >> 9;
   int E = exp - 127;
   ```

   

2. If it is a denormalised value, the `E = 1 - bias` is a negative number. Therefore, it is less than 0. When a float value is converted to an integer, a float value round to 0. 

   ```c
   if (exp == 0)
       return 0;
   ```

3. In the third case, if `exp == 255(0xff)`, it is either an Infinity or a NaN. The function should therefore return `0x80000000u`.

   ```c
   if (exp == 255)
       return 0x80000000u;
   ```

   

4. If it is a normalised value, we should add the implicit 1 back; there are 24 bits in total therefore 8 bits on the left, including a sign bit. Subsequently, there are 4 cases.

   (1) If $E < 0$, any number of $1.x$ to the power of a negative value is always less than 0, so the integer is 0.

   (2) If $E \le 23$, we shift the $M$ $23-E$ bits to the right. 

   (3) On the contrary, if $31 > E > 23$, we should shift $M$ to the left by $E-23$ bits. 

   (4) In the fourth case, if $E\ge 31$ which means $E-23\ge 8$; the fraction will shift to the left by 8 bits or more. Note that the fraction can only shift at most 8 bits to the left and it can overwrite the sign bit in the 32nd place. 

   ```c
   int M = frac | (1 << 23);
   if (E < 0)
       return 0;
   if (E <= 23)
       M = M >> (23 - E);
   else if (E > 23 && E < 31)
       M = M << (E - 23);
   else 
       return 0x80000000u;   
   ```

   

##### 13, floatPower2

```c
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
```

1. $2.0$ is equivalent to $1.0 \times2^1$ of which the bit-level representation is `0x4000_0000`. It is a normalised value. Consequently, $2.0^x = 1.0 \times 2^x$

2. If it is a normalised value, the exponent is between 1 and 254. Consequently, we can deduce that the range of $x$ in $x = exponent - 127(bias)$ is from $-126$ to $127$.

   ```c
   if (x < -126)
       return 0;
   if (x > 127)
       return 0x07800000;  // The single-precission float-point value of infinity.
   ```

   

#### Bomb Lab

##### **How to do the bomb lab?**

(1) It is suggested that we should disassemble the binary file, `bomb`, and analyse the machine code step by step to defuse bombs. There are many phases and one bomb is in each of them. 

(2) Since the bomb ignores blank lines of input, we can save our solutions of first bombs in a file named, for example, `psol.txt` so that we don't have to input when we are trying to defuse the next bomb.

```shell
>./bomb psol.txt
# Or in gdb
(gdb)start < psol.txt 
# or 
(gdb)run < psol.txt
```

(3) We should learn examine the assembly code of `bomb` step by step  and know how to set breakpoints. 

(4) To know how to inspect registers and memory states can also help us to defuse the bomb. 

##### **Phase 1**

**How to defuse "phase 1"?**

```c
    //...
	/* Hmm...  Six phases must be more secure than one phase! */
    input = read_line();             /* Get input                   */
    phase_1(input);                  /* Run the phase               */
    phase_defused();                 /* Drat!  They figured it out!
    ...
```

Since only the source code of `main` is provided and it is implausible to step into the function `phase_1(input)`, we should disassemble it. 

Note that in x86_64, `%rdi` and `%rsi` are the first and the second argument, respectively. See Figure 3.35.

(1) First of all, run `gdb bomb` and set a break point at the function `phase_1(input)`. We input "abc" to test.

(2) After disassembling the current function to find where `phase_1(...)`  is called, we can see at the address of `0x400e37` that it moves the value in `%rax` to `%rdi` after calling `read_line`.

```assembly
  400e32:	e8 67 06 00 00       	callq  40149e <read_line>
  400e37:	48 89 c7             	mov    %rax,%rdi
  400e3a:	e8 a1 00 00 00       	callq  400ee0 <phase_1>
```

Apparently, "abc" is stored in `%rax` and then is moved to `%rdi`. To verify that, enter `x/s $rax`  to examine the string stored at `$rax`. It is "abc" and we find it. 

```shell
(gdb)x/s $rax
0x603780 <input_strings>:       "abc"
```

(3) There isn't any source code of `phase_1(...)`, of course, therefore, we can't use `step` to enter into it. Otherwise, we can't see anything and the bomb is detonated. We can use `stepi` to execute an instruction in assembly code. 

```shell
(gdb)stepi
```

The assembly code of `phase_1(...)` is as follows. 

```assembly
0000000000400ee0 <phase_1>:
  400ee0:	48 83 ec 08          	sub    $0x8,%rsp
  400ee4:	be 00 24 40 00       	mov    $0x402400,%esi
  400ee9:	e8 4a 04 00 00       	callq  401338 <strings_not_equal>
  400eee:	85 c0                	test   %eax,%eax
  400ef0:	74 05                	je     400ef7 <phase_1+0x17>
  400ef2:	e8 43 05 00 00       	callq  40143a <explode_bomb>
  400ef7:	48 83 c4 08          	add    $0x8,%rsp
  400efb:	c3                   	retq   
```

Now we read its assembly code thoroughly and find that `$0x402400` is moved to `%esi`. `$0x402400` might be an address of some strings. We should check it. 

```shell
(gdb)x/s 0x402400
0x402400:       "Border relations with Canada have never been better."
```

Great! We have found it. Whereas, we had better not stop but to verify it by analysing the rest of assembly code. 

##### Phase 2 

I conclude that the number of arguments should be 6 after analysing the assemble code in `read_six_numbers(...)` as follows. 

```assembly
000000000040145c <read_six_numbers>:
  40145c:	48 83 ec 18          	sub    $0x18,%rsp
  401460:	48 89 f2             	mov    %rsi,%rdx
  401463:	48 8d 4e 04          	lea    0x4(%rsi),%rcx
  401467:	48 8d 46 14          	lea    0x14(%rsi),%rax
  40146b:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  401470:	48 8d 46 10          	lea    0x10(%rsi),%rax
  401474:	48 89 04 24          	mov    %rax,(%rsp)
  401478:	4c 8d 4e 0c          	lea    0xc(%rsi),%r9
  40147c:	4c 8d 46 08          	lea    0x8(%rsi),%r8
  401480:	be c3 25 40 00       	mov    $0x4025c3,%esi
  401485:	b8 00 00 00 00       	mov    $0x0,%eax
  40148a:	e8 61 f7 ff ff       	callq  400bf0 <__isoc99_sscanf@plt>
   # %eax holds the return value of 'sscanf', which indicates how many arguments input
   # by a user. If it is greater than 5, the program will jump to 0x401499, therefore, it 
   # skips the following "exlode_bomb".
  40148f:	83 f8 05             	cmp    $0x5,%eax 
  401492:	7f 05                	jg     401499 <read_six_numbers+0x3d>
  401494:	e8 a1 ff ff ff       	callq  40143a <explode_bomb>
  401499:	48 83 c4 18          	add    $0x18,%rsp
  40149d:	c3                   	retq   
```

These six arguments are moved to new registers.

```assembly
# Since in 'phase_2', there is an instruction:
# 400f02:	48 89 e6     mov %rsp,%rsi
# ,therefore, %rsi holds the value of the stack pointer %rsp.
mov %rsi %rdx   # The first argument.
lea 0x4(%rsi), %rcx
lea 0x8(%rsi), %r8
lea 0xc(%rsi), %r9   	# 0xc = 12
# 0x10 = 16
lea 0x10(%rsi), %rax 	
lea %rax, (%rsp)
# 0x14
lea 0x14(%rsi), %rax
lea %rax, 0x8(%rsp)
```

Now let use go back the assembly code of `phase_2(...)`.

```assembly
0000000000400efc <phase_2>:
  400efc:	55                   	push   %rbp
  400efd:	53                   	push   %rbx
  400efe:	48 83 ec 28          	sub    $0x28,%rsp
  400f02:	48 89 e6             	mov    %rsp,%rsi
  400f05:	e8 52 05 00 00       	callq  40145c <read_six_numbers>
  # (1)After testing with '(gdb)x/d $rsp', I find that '(%rsp)' holds the first value of 
  # the numbers input by a user. Apparently, it is '1'. 
  # Then the processor jumps to 0x400f30 if the first number is '1'.
  400f0a:	83 3c 24 01          	cmpl   $0x1,(%rsp)
  400f0e:	74 20                	je     400f30 <phase_2+0x34>
  400f10:	e8 25 05 00 00       	callq  40143a <explode_bomb>
  400f15:	eb 19                	jmp    400f30 <phase_2+0x34>
  # (3) The first value which '0x4(%rbx)=(%rsp)' deferences is moved to '%eax'.
  400f17:	8b 43 fc             	mov    -0x4(%rbx),%eax
  # (4) '%eax' is doubled and compared with '%rbx' which deferences to the second number.
  # (5) Now it is easy to find out the rest numbers by executing instructions one by one. 
  400f1a:	01 c0                	add    %eax,%eax  
  400f1c:	39 03                	cmp    %eax,(%rbx)
  400f1e:	74 05                	je     400f25 <phase_2+0x29>
  400f20:	e8 15 05 00 00       	callq  40143a <explode_bomb>
  400f25:	48 83 c3 04          	add    $0x4,%rbx
  400f29:	48 39 eb             	cmp    %rbp,%rbx
  400f2c:	75 e9                	jne    400f17 <phase_2+0x1b>
  400f2e:	eb 0c                	jmp    400f3c <phase_2+0x40>
  # (2) Then the address of the second argument is moved to '%rbx'.
  400f30:	48 8d 5c 24 04       	lea    0x4(%rsp),%rbx
  400f35:	48 8d 6c 24 18       	lea    0x18(%rsp),%rbp
  400f3a:	eb db                	jmp    400f17 <phase_2+0x1b>
  400f3c:	48 83 c4 28          	add    $0x28,%rsp
  400f40:	5b                   	pop    %rbx
  400f41:	5d                   	pop    %rbp
  400f42:	c3                   	retq   
```

**The solution is "1 2 4 8 16 32".**

##### Phase 3

*Tips:* 

1. We assume that the `%eax` holds x; the following instruction is an indirect jump to a target which is at the address of `8*x + 0x402470`.  If x is 7, the result is `0x402470 + 7*8 = 0x400fa6`.

   ```assembly
   400f75:	ff 24 c5 70 24 40 00 	jmpq   *0x402470(,%rax,8)
   ```

2. Note that don't input hexadecimal number because the format in `sscanf(...)` is `"%d %d"` which requires decimal number. 

   ```assembly
   400f51:	be cf 25 40 00       	mov    $0x4025cf,%esi
   400f56:	b8 00 00 00 00       	mov    $0x0,%eax
   400f5b:	e8 90 fc ff ff       	callq  400bf0 <__isoc99_sscanf@plt>
   ```

   ```shell
   (gdb)x/s 0x4025cf
   0x4025cf:  "%d %d"
   ```

(1) The segment of code below is abstracted from `phase_3()`.

```assembly
  400f56:	b8 00 00 00 00       	mov    $0x0,%eax
  400f5b:	e8 90 fc ff ff       	callq  400bf0 <__isoc99_sscanf@plt>
  400f60:	83 f8 01             	cmp    $0x1,%eax
  400f63:	7f 05                	jg     400f6a <phase_3+0x27>
  400f65:	e8 d0 04 00 00       	callq  40143a <explode_bomb>
```

We can see that in `0x400f60`, `%eax` is compared with 1. Since `%eax` holds the return value of `sscanf()` indicating the number of input, we can deduce that it must be greater than 1. Otherwise, the program will proceed to the next line to call `explode_bomb`. I input "test" in this phase. Apparently, it is not correct. So I stop it to avoid exploding a bomb. 

(2) Subsequently, I write `1 2` in the third line of `psol.txt` instead. 

```assembly
  400f47:	48 8d 4c 24 0c       	lea    0xc(%rsp),%rcx
  400f4c:	48 8d 54 24 08       	lea    0x8(%rsp),%rdx
# ...
  400f6a:	83 7c 24 08 07       	cmpl   $0x7,0x8(%rsp)
  400f6f:	77 3c                	ja     400fad <phase_3+0x6a>
  400f71:	8b 44 24 08          	mov    0x8(%rsp),%eax
  400f75:	ff 24 c5 70 24 40 00 	jmpq   *0x402470(,%rax,8)
  # ...
  400fad:	e8 88 04 00 00       	callq  40143a <explode_bomb>
```

Let's keep on defusing, we can see at the beginning of the assembly code of `phase_3()`. The processor loads effective address from `0xc(%rsp)` and `0x8(%rsp)` to `%rcx` and `%rdx`, respectively. They might be the two arguments input by me. To verify that, I enter the following command.

```shell
# Note that the first and the second argument aren't moved to '0x8(%rsp)' and '0xc(%rsp)'
# until 'sscanf' is called. 
(gdb)x/wd ($rsp + 0x8)  # It is 1, which is the first argument.
(gdb)x/wd ($rsp + 0xc)  # It is 2, which is the second argument. 
```

Then `0x8($rsp) ` is compared with a constant 7. If it is larger than 7, the program will jump to `0x400fad` where `explode_bomb()` will be called. Obviously, the first argument must be less than or equal to 7. Replace the first one with 7 in `psol.txt`. Now the arguments are 7 and 2. 

(3) Indirect jump. 

```assembly
  400f71:	8b 44 24 08          	mov    0x8(%rsp),%eax
  400f75:	ff 24 c5 70 24 40 00 	jmpq   *0x402470(,%rax,8)
  # When the first argument(stored in %rax) is 0, it jumps to the next line: 0x400f7c
  400f7c:	b8 cf 00 00 00       	mov    $0xcf,%eax
  400f81:	eb 3b                	jmp    400fbe <phase_3+0x7b>
  400f83:	b8 c3 02 00 00       	mov    $0x2c3,%eax
  400f88:	eb 34                	jmp    400fbe <phase_3+0x7b>
  400f8a:	b8 00 01 00 00       	mov    $0x100,%eax
  400f8f:	eb 2d                	jmp    400fbe <phase_3+0x7b>
  400f91:	b8 85 01 00 00       	mov    $0x185,%eax
  400f96:	eb 26                	jmp    400fbe <phase_3+0x7b>
  400f98:	b8 ce 00 00 00       	mov    $0xce,%eax
  400f9d:	eb 1f                	jmp    400fbe <phase_3+0x7b>
  400f9f:	b8 aa 02 00 00       	mov    $0x2aa,%eax
  400fa4:	eb 18                	jmp    400fbe <phase_3+0x7b>
  # When it is 7, the program jump here. 
  400fa6:	b8 47 01 00 00       	mov    $0x147,%eax
  400fab:	eb 11                	jmp    400fbe <phase_3+0x7b>
  400fad:	e8 88 04 00 00       	callq  40143a <explode_bomb>
  400fb2:	b8 00 00 00 00       	mov    $0x0,%eax
```

See the first tip of this phase above. `jmpq  *0x402470(,%rax,8)` is an indirect jump. 

```shell
(gdb) x/wx 0x402470  # Examine the jump target at the address of 0x402470.
0x402470: 0x00400f7c
```

The target in the address of `0x402470` is ` 0x400f7c` which is exactly the address of next line. Unfortunately, I made a mistake by adding `0x400f7c + %rax * 8`. In fact, the equation should be `0x402470 + (%rax *8)`.  Apparently, it seems like a switch and the condition is less than or equal to 7. 

When the first argument is 7, the second one is 327. The bomb in phase 3 is defused!

Since it is a switch, there are alternative solutions. Let's start with 0. If the first argument is 0, then `0x8(%rsp)` is 0 and `%eax` is 0. Subsequently, `%rax` is 0 so that `jmpq  *0x402470(,%rax,8)` jump to the very next line: `400f7c  mov  $0xcf,%eax `.  0xcf = 207.



##### Phase 4 

Tips: 

1. In `func4(...)`, the first operand  of `sar %eax`  which is omitted is 1 by default after I verify it. 

   "SAL  k, D" : D $\leftarrow$ D << k.  The default value of k is 1. 

   ```assembly
     400fdd:	d1 f8           sar  %eax
   ```




Analyses:

(1) First of all, the number of arguments is 2. 

```assembly
   # phase_4(...).
  40101f:	b8 00 00 00 00       	mov    $0x0,%eax
  401024:	e8 c7 fb ff ff       	callq  400bf0 <__isoc99_sscanf@plt>
  401029:	83 f8 02             	cmp    $0x2,%eax  # Two arguments
  40102c:	75 07                	jne    401035 <phase_4+0x29>
  # ...
  401035:	e8 00 04 00 00       	callq  40143a <explode_bomb>
```

(2) The first argument must be less than or equal to 12. 

```assembly
  # phase_4(...). The first argument is in "0x8(%rsp)"; I have verified that. 
  40102e:	83 7c 24 08 0e       	cmpl   $0xe,0x8(%rsp)
  401033:	76 05                	jbe    40103a <phase_4+0x2e>
  401035:	e8 00 04 00 00       	callq  40143a <explode_bomb>
```

(3) The return value of `func4(...)` must be 0. Otherwise, the program will jump to `0x401058` to explode the bomb. 

```assembly
# func4(...)
  401048:	e8 81 ff ff ff       	callq  400fce <func4>
  40104d:	85 c0                	test   %eax,%eax
  40104f:	75 07                	jne    401058 <phase_4+0x4c>  # Jump to explode_bomb
  401051:	83 7c 24 0c 00       	cmpl   $0x0,0xc(%rsp)
  401056:	74 05                	je     40105d <phase_4+0x51>
  401058:	e8 dd 03 00 00       	callq  40143a <explode_bomb>
```

(3) Although I tried to reverse the assembly code of `func2()` into C, I failed. I input `12 23` at first, the return value of `func4(...)` is not 0. Then I input `0 23` and got 0 as the return value of it. 

I will try to reverse it later. 

(4) The second argument is easy to guess; it is 0, too. 

```assembly
  401051:	83 7c 24 0c 00       	cmpl   $0x0,0xc(%rsp)  
  401056:	74 05                	je     40105d <phase_4+0x51>
  401058:	e8 dd 03 00 00       	callq  40143a <explode_bomb>
  40105d:	48 83 c4 18          	add    $0x18,%rsp
  401061:	c3                   	retq   
```

`1 0` is also correct. 



##### Phase 5 

Here is the assembly code of `phase_5(...)`.

```assembly
0000000000401062 <phase_5>:
  401062:	53                   	push   %rbx
  401063:	48 83 ec 20          	sub    $0x20,%rsp
  401067:	48 89 fb             	mov    %rdi,%rbx
  40106a:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  401071:	00 00  # nop
  401073:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
  401078:	31 c0                	xor    %eax,%eax
  40107a:	e8 9c 02 00 00       	callq  40131b <string_length>
  40107f:	83 f8 06             	cmp    $0x6,%eax
  401082:	74 4e                	je     4010d2 <phase_5+0x70>
  401084:	e8 b1 03 00 00       	callq  40143a <explode_bomb>
  401089:	eb 47                	jmp    4010d2 <phase_5+0x70>
  40108b:	0f b6 0c 03          	movzbl (%rbx,%rax,1),%ecx
  40108f:	88 0c 24             	mov    %cl,(%rsp)
  401092:	48 8b 14 24          	mov    (%rsp),%rdx
  401096:	83 e2 0f             	and    $0xf,%edx
  401099:	0f b6 92 b0 24 40 00 	movzbl 0x4024b0(%rdx),%edx
  4010a0:	88 54 04 10          	mov    %dl,0x10(%rsp,%rax,1)
  4010a4:	48 83 c0 01          	add    $0x1,%rax
  4010a8:	48 83 f8 06          	cmp    $0x6,%rax
  4010ac:	75 dd                	jne    40108b <phase_5+0x29>
  4010ae:	c6 44 24 16 00       	movb   $0x0,0x16(%rsp)
  4010b3:	be 5e 24 40 00       	mov    $0x40245e,%esi
  4010b8:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  4010bd:	e8 76 02 00 00       	callq  401338 <strings_not_equal>
  4010c2:	85 c0                	test   %eax,%eax
  4010c4:	74 13                	je     4010d9 <phase_5+0x77>
  4010c6:	e8 6f 03 00 00       	callq  40143a <explode_bomb>
  4010cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4010d0:	eb 07                	jmp    4010d9 <phase_5+0x77>
  4010d2:	b8 00 00 00 00       	mov    $0x0,%eax
  4010d7:	eb b2                	jmp    40108b <phase_5+0x29>
  4010d9:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
  4010de:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  4010e5:	00 00 
  4010e7:	74 05                	je     4010ee <phase_5+0x8c>
  4010e9:	e8 42 fa ff ff       	callq  400b30 <__stack_chk_fail@plt>
  4010ee:	48 83 c4 20          	add    $0x20,%rsp
  4010f2:	5b                   	pop    %rbx
  4010f3:	c3                   	retq   
```

**Analyses of phase_5** 

1. `%fs:0x28` is used to detect buffer overflow which is caused by malicious hackers. See [stack canary](.\Tutorials\Others\Stack Canary.md).

   Note that `0x20 - 0x18 = 0x8`, but not 2. The following code move `%fs:0x28` to the place just preceded the return value. If a hacker tried to overwrite the return value(conventionally from lower address to higher), he must overwrite `0x18(%rsp)` first. Since the canary value(`%fs:0x28`) is random and changes every time when the program runs, it is difficult to guess and we can detect the overflow caused by a hacker when comparing it with the original content. 

   ```assembly
     # phase_5()
     401063:	48 83 ec 20          	sub    $0x20,%rsp
     401067:	48 89 fb             	mov    %rdi,%rbx
     40106a:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
     401073:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
     # ...
     4010d9:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
     4010de:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax    # Verify the content.
     4010e7:	74 05                	je     4010ee <phase_5+0x8c>
     4010e9:	e8 42 fa ff ff       	callq  400b30 <__stack_chk_fail@plt>
   ```

   

2. It seems to be an array. 

3. Note that `movzbl (%rbx,%rax,1),%ecx` moves the least significant byte of the value stored at the address of `(%rbx, %rax, 1)`, but not the value of the address. `movzbl` is different from `lea`. The value is as follows.

   ```shell
   (gdb)x/xw ($rbx + $rax*1)
   # I input "abcdef" so the integer is 0x64636261(64 63 62 61).
   0x6038c0 <input_strings+320>:   0x64636261 
   # Examine 6 characters starting from the address of "($rbx + $rax*1)".
   (gdb)x/6c 
   0x6038c0 <input_strings+320>:   97 'a'  98 'b'  99 'c'  100 'd' 101 'e' 102 'f'
   ```

   As a result, the content in `$ecx` is `0x61` after this instruction; `0x61` represents `a`, `0x62` represents `b` and so forth. Presumably, it will change when I input other characters. 

   ```assembly
     # phase_5()
     40108b:	0f b6 0c 03          	movzbl (%rbx,%rax,1),%ecx 
     40108f:	88 0c 24             	mov    %cl,(%rsp)
     401092:	48 8b 14 24          	mov    (%rsp),%rdx
     401096:	83 e2 0f             	and    $0xf,%edx
   ```
   
   Obviously, `movzbl (%rbx, %rax, 1), %ecx` instructs moving elements input by a user in an array with `%rax` as its index. 

