# include<stdio.h>

/*
 * To negate a number in a tricky way.
 * Flip it and add 1 to it and then get the negate number of 
 * original value.
 * */

int main (void) 
{

	short s1 = 6;
	short s1n = ~s1 + 1;
	printf("s1 = %d: \t s1n = %d\n", s1, s1n);

	return 0;
}
