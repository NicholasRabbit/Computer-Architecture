
/*
 * The following function from the boodk is a wrong answer to verify whether there is overflow when
 * two numbers are added. 
 * */

# include<stdio.h>

/**
 * The following code is buggy.
 * */
int tadd_ok(int x, int y)
{
	int sum = x + y;
	return (sum - x == y) && (sum - y == x);
}

/*
 * What is wrong with the code?
 * The result of "(x + y) - y" is always x regardless of whether or not the addition overflows.
 * */


int main (void) 
{
	int result = tadd_ok(0x8fffffff, 0x8fffffff);
	printf("result ==> %d\n",result);
	return 0;
}
