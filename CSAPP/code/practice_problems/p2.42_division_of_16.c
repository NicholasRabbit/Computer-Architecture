#include <stdio.h>

/*
 * In my opinion, this problem help us to understand how the compiler deal with the calculation
 * of a negative number divided by a divisor.
 *
 * What the function 'div16' does is exactly as same as a comiler does in a low level.
 *
 * N.B. A negative number such as -38 plus a bias(e.g. 15) is -23 which is larger.
 *
 * */

/*
 * Write a function to impement division by 16(2^4, >> 4).
 * */
int div16(int x) 
{
	//16 - 1 is 0xF.
	int bias = x >> 31 & 0xF;
	return (x + bias) >> 4;
}

int main(void) 
{
	int x, result;
	printf("Please input a dividend: ");
	scanf("%d", &x);
	result = div16(x);

	printf("The result is %d\n", result);

	return 0;

}
