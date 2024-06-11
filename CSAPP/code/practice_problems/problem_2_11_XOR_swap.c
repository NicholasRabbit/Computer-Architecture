# include<stdio.h>

void inplace_swap(int *x, int *y) 
{

	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;

}


void reverse_array(int a[], int cnt) 
{
	int first, last;
	for (first = 0, last = cnt - 1; 
			first <= last; 
			first++, last--) {
		
		inplace_swap(&a[first], &a[last]);
	
	}

}


int main(void) 
{
	int a[] = {1, 2, 3, 4, 5};
	int cnt = 5;

	reverse_array(a, cnt);

	int i;
	for (i = 0; i < cnt; i++) {
		printf("%d, ", a[i]);
	}
	printf("\n");

	return 0;
}


/**
 * Answers:
 * A. In the above example the 5=2*k + 1 and "k" is 2.
 *    The values of variables "first" and "last" are 2.
 * B. According to the answers we got in A, both pointer x and pointer y point 
 *    the same location in memory. Whereas, 2^2 is 0, then the result is always 
 *    0.
 * C. I think the "<=" in reverse_array should be replaced by "<" so that the 
 *    problem will be eliminated. That's the corrct answer.  
 *
 * */
