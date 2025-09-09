### 1, Errors 

Running `make btest` on a machine of 64-bit representation of integers may cause an error(`fatal error gnu/stubs-32.h no such file or directory `).  The solution is given as follows.

Solution:

```shell
# You need install the glibc-devel.i386 package because the labs need machine of 32-bit 
# representations of integers.
yum -y install glibc-devel.i386   # Centos 6/7
```

### 2, How to do the lab?

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

### 3, Elaboration of questions and answers

[Answers](https://blog.csdn.net/qq_45677541/article/details/123955438)

#### 1, tMin(void)

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

#### 7, conditional

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

#### 8, isLessOrEqual

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

#### 9, logicalNeg

See `../ CSAPP/labs/testing_code_for_labs/logicalNeg.c`

#### 10, howManyBits

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

#### 11, floatScale2

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

#### 12, floatFloat2Int

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

   

#### 13, floatPower2

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

   

