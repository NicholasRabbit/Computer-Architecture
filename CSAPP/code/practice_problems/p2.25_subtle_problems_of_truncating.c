# include<stdio.h>

// Practice Problem 2.26 at page 77.

float sum_elements(float a[], unsigned length) 
{
	int i;
	float result = 0;
	
	for (i = 0; i <= length - 1; i++)
		result += a[i];
	return result;
}


int main (void) 
{

	float a[] = {1.3, 3.5, 5.6, 7.7};

	/*
	 * When the length is 0, the functioin encounters a memory error.
	 * The reason is 'length' is unsigned and is the maximun number.
	 * So when 'i <= length - 1' the 'i' also becomes unsigned and 
	 * it is always less than or equals to "length - 1".
	 * That yields an endless loop.
	 *
	 * How to fix the bug?
	 * We can declare the "length" to an int or change "i <= lenth - 1" to "<".
	 * */
	float ret_value = sum_elements(a, 0);
	printf("ret_value = %f\n", ret_value);

	return 0;
}
