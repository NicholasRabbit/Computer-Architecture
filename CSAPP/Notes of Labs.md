### 1, Errors 

Running `make btest` on a machine of 64-bit representation of integers may cause an error(`fatal error gnu/stubs-32.h no such file or directory `).  The solution is given as follows.

Solution:

```shell
# You need install the glibc-devle.i386 package because the labs need machine of 32-bit 
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



