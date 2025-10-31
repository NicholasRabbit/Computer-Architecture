#include <stdio.h>


/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */


/*
 *
 * Since there are two categories of numbers which are 0 and non-zeros, 
 * namely !0 = 1 and !(non-zero) = 1, what we need to do is to deal with
 * these two with allowed operators.
 * 
 * There are two solutions. One is incorrect and the other is ?
 * */
/*
 * 1. Solution one: (Though it is not correct but worth trying and writing the process)
 *
 * 1.1) For any non-negative x its negation is (~x + 1), definitely one is positive 
 * and the other is negative. Therefore, the most significant bit of them are 0 
 * and 1, respectively. We can take advantage of this property.
 * First of all, we should get each of the most significant bits of x and -x by 
 * shifting 31 bits to the right.
 * a = x >> 31; 
 * b = (~x + 1) >> 31;
 * N.B. For arithmatic shifting, the rule is to add copies of the most significant bit 
 * to the lef side. For instance, the result of shifting a negative number is 
 * like 0x1100,....>> 31 = 0x1111,...(32 "1"s).
 *
 * Then the a is '0xffffffff' and b is '0x0' or vice versa.
 *
 * a ^ b = -1 (Actually it is 0xffffffff), so we should add 1 to the result to get 0.
 *
 * 1.2) For 0, the result of (a^b) + 1 is 1.
 *
 * There is a bug in solution 1. When x is the minimum negative value which is 0x8000 0000, 
 * (~x + 1) is also 0x8000 0000, thus (~x + 1) >> 31 is 1 and "a^b + 1" is 1 while what we 
 * expect is 0.
 *
 *
 *
 *
 * 
 * */
int logicalNeg(int x) 
{
	int a = x >> 31;
	int b = (~x + 1) >> 31;
	int r = (a ^ b) + 1;
	return r;
}

/*
 * Solution 2 
 *
 * 2.1) If x is non-zero, the leading digit of "x | ~x + 1" is "1".
 * Because "~x + 1" is the negation of "x", either of them has a "1" as 
 * its most significant bit. Consequently, "1 | 0" is "1".
 *
 * When we make arithemetic shift the result of shifting right for 31 bits is 0xffffffff.
 * That also yields the same value for the minimum negative value-0x8000 0000. 
 * In order to get 0, we just add 1 to it to get the expected 0.
 * */
int logicalNegB(int x) 
{
	int a = (x | (~x + 1));
	a = a >> 31;

	return a + 1;
}



int main(void) 
{
	int x;

	printf("Input a number: ");
	scanf("%d", &x);

	//int result = logicalNeg(x);
	int result = logicalNegB(x);

	printf("0x%x\n", result);

	return 0;
}
