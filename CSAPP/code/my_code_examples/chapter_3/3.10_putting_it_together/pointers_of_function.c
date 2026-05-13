#include <stdio.h>

int fun(int x, int *p);


int main(void) 
{
	// Declare a pointer of a function.
	// Declare a function pointer and assign a addres of a function to it.
	// The last parentheses indicate the two arguments of this function/
	// The first "int" is the return type while the parentheses of it is not necessary.
	// But (*fp) must be bracketed, otherwise it will be 'int * fp(int, int *)' which is a
	// prototype of another function with "int *" pointer as its return value and "fp" as its
	// name.
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

