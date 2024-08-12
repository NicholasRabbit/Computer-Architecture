# include<stdio.h>

// A practice Problem 2.26 at page 77.

float sum_elements(float a[], unsigned length) 
{
	int i;
	float result = 0;

	for (i = 0; i < length - 1; i++)
		result += a[i];

	return result;

}


int main (void) 
{

	float a[] = {1.3, 3.5, 5.6, 7.7};

	/*
	 * When the length is 0, the functioin encounters a memory error.
	 * The reason is that when the unsigned 'length' is '0-1' it is the maximun number.
	 * When a signed integer 'i <= length - 1' the 'i' is cast to an unsigned number and 
	 * it is always less than or equals to "length - 1".
	 * That yields an endless loop.
	 *
	 * How to fix the bug?
	 * We can declare the "length" to an int or change "i <= length - 1" to "<".
	 *
	 * While there is still a problem which is that error is not disappeared when using "<",
	 * perhaps the long number is too large for my VM. I will figure it out later.
	 * */
	float ret_value = sum_elements(a, 0);
	printf("ret_value = %f\n", ret_value);

	return 0;
}
