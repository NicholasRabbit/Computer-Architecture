#include <stdio.h>

/*
 * As the range of a byte is significanlty lower than four bytes
 * and is easy to verify, I decided to write test code with it.
 *
 * Unfoutunately, I haven't figured out the solution or understood it yet.
 * */
char howManyBitsChar(char x);


int main(void) 
{
	printf("Please input a number: \n");
	int num;
	scanf("%x", &num);
	num = howManyBitsChar(num);
	printf("How many bits? ==> 0x%.2x\n", num);
	return 0;
}


char howManyBitsChar(char x) 
{
	char sign = x >> 7;
	char abs_x = (sign & ~x) | (~sign & x);
	int b4, b2, b1;
	b4 = !!(abs_x >> 4) << 2;
	abs_x = abs_x >> b4;
	b2 = !!(abs_x >> 2) << 1;
	abs_x = abs_x >> b2;
	b1 = !!(abs_x >> 1);

	return b4 + b2 + b1 + abs_x + 1;
}


