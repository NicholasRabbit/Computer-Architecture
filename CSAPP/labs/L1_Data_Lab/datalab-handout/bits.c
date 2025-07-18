/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~x & ~y) & ~(x & y);  // my answer
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int map = x + 0x01;
  int res = ~(map + x);
  return !res & (!!map);  
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int y = 0xAA + (0xAA << 8);
  y = y + (y << 16);
  x = x & y;
  x = x ^ y;
  return !x;

}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	/*
	 * If x - 0x30 >= 0 and 0x39 - x >= 0, x is a ASCII digit.
	 * Step 1:
	 * Transfomr  x - 0x30 >= 0 to x + (-0x30), we should negate 0x30 at first.
	 * */
	int lowerBound = x + (~0x30 + 1);
	/*
	 * Step 2:
	 * As the trick in the step one used to negate a number, we do the same to x.
	 * 0x39 -x >= 0
	 * 0x39 - x => 0x30 + (~x + 1)
	 * */
	int higherBound = 0x39 + (~x + 1);

	/*
	 * If 'x' is ASCII digit it should be bigger than '0x30' therefore 'lowerBound' is 
	 * a positive number or 0. Then the most significant bit of it is '0'. Thus the 
	 * result after shifting 31 bits to the right is 0, otherwise it is '1';
	 * */
	int r1 = lowerBound >> 31;
	int r2 = higherBound >> 31;
	/*
	 * "return !(r1 & r2)" is wrong when the result is '0&1' which also yields '0'. 
	 * But '1' indicates that 'x' is not ASCII digit.
	 * */ 
	return !r1 & !r2; 
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
/*
 * Elaboration of the question.
 * In C any non-zero numbers equal 'true' or 1 so for binary expression 'x ? y : z' when x is not 
 * zero the result is y, otherwise it is z.
 *
 * N.B. The answer is not from me but copy from others, I don't understand the boolean deeply. 
 * Thus a further investigation is expected.
 * See the solutions in the tutorials. 
 *
 * */
int conditional(int x, int y, int z) {
	x = ~(!x) + 1;
	return (~x & y) + (x & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	
	int sign_x = x >> 31 & 1;
	int sign_y = y >> 31 & 1;
	int same_sign = !(sign_x ^ sign_y);
	
	int res = (~x + 1) + y;
	res = !(res >> 31);

	res = same_sign & res;

	return res | ((sign_x ^ sign_y) & sign_x);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
	int a = (x | (~x + 1));
	a = a >> 31;
	return a + 1;
}
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

	/*
	 * 1. Check if it is a normalised float-point value.
	 * */
	int sign, exp, E, frac, bias, f, normal;
	normal = 0;
	bias = 127;
	
	// 1.1 Get the exponent of the single-precision floating point value.
	exp = (uf << 1) >> 24;
	if (exp > 0 && exp < 255) {
		normal = 1;
	} 
	// Denormalisd vlaues.
	if (exp == 0)
		return 0;
	// 1.2 Compute the E.
	E = exp - bias;

	/*
	 * 2. Retrieve the fractional part.
	 * The fractional part is the 23 least significant bits of the value.
	 * Note that if it is a normalised value we should add the implicit one 
	 * back to it. If it is a denormalised value, it is not necessary to do
	 * that.
	 * */
	frac = (uf << 9) >> 9;
	if (normal) {
		// Attention. 0x2 should be shifted by 23 bits not 24 bits
		// since "1" is already the least sigficant bit.
		int one = 0x1 << 23; 
		frac = one | frac;
	}

	/*
	 * 3. Shift the fraction to the right to restore the integer value.
	 * */
	frac = frac >> (23 - E);

	// 4. Get the sign of the single-precision floating-point value.
	sign = (uf >> 31) << 31;

	// 5. Compute the final integer value.
	return sign | frac;

}
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
