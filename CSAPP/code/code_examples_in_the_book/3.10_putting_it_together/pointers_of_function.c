#include <stdio.h>

int fun(int x, int *p);


int main(void) 
{
	// Declare a pointer of a function.
	int (*fp) (int, int *);
	fp = fun;
	int y = 1;
	int *py = &y;
	int result = fp(3, py);
	
	printf("result: %d\n", result);
	printf("py: %d\n", *py);

	return 0;
}

int fun(int x, int *p)
{
	*p = x;
	return *p;
}

