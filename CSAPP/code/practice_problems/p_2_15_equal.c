# include<stdio.h>

/*
 * To write an C expression that is equivalent to x == y by using
 * bit-level and logical operations.
 * */

int equals(int x, int y)
{
	int i = x ^ y;
	if (i == 0)
		return 1;
	else
		return 0;

	// The following expression is more concise.
	// return !(x ^ y);
			

}


int main (void) 
{
	
	int result = equals(0x5a, 0x5a);
	printf("%x\n", result);
	return 0;
}
