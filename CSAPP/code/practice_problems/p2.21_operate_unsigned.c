# include<stdio.h>


int main (void) 
{

	// The result is 1.
	int result  = (-2147483647 - 1U) < -2147483647;

	printf("-2147483647=%uU\n", -2147483647);

	printf("result=%d\n", result);

	return 0;
}
