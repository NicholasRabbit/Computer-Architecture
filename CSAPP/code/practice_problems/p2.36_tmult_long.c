# include<stdio.h>


int tmult_ok(int x, int y) 
{
	/*
	 * Note that the casting on right side is critical and necessary. If we wrote the code 
	 * like 'line 10', the product would be computed as an int(32-bit) value, which could 
	 * lead to overflow, and then sign extended to 64 bits
	 * */
	//long long pll = x * y;  // line 10, buggy code.
	long long pll = (long long) x * y;

	printf("size of long long is ==> %lu bytes \n", sizeof(pll));
	printf("size of int is ==> %lu bytes \n ", sizeof(x));

	// To see if it preserves value after casting to int.
	return pll == (int)pll;
}


int main (void) 
{
	
	int result = tmult_ok(0xffffffff, 0x8fffffff);
	printf("%d\n", result);

	return 0;
}
