# include<stdio.h>


/*
 * To return 1 if two singed numbers are added without overflow.
 * */
int tadd_ok(int x, int y)
{
	/*
	 * Elaboration: if two numbers are all negative and the result is
	 * positive, there must be overflow.
	 * */
	if (x < 0 && y < 0) {
		int neg_over = (x + y) >= 0;
		return !neg_over;
	}

	/*
	 * If two positive numbers are added, there is overflow when the result
	 * is negative.
	 * */
	if (x >= 0 && y >= 0) {
		int pos_over = (x + y) < 0;
		return !pos_over;
	}

	/*
	 * The addition of a positive and a negative number will never cause overflow.
	 * */
	return 1;
	

}


int main (void) 
{
	int i, j;
	// The following numbers in 4 bytes(32 bits) are like -8 and -7 in a data type with 4 bits.
	// I write them in order to test if there is a negative overflow.
	i = 0x80000001;	
	j = 0x80000000;
	int result = tadd_ok(i, j);
	printf("Is it overflow? yes: 0, no: 1 ==> %d\n", result);

	return 0;

}
