#include <stdio.h>


int main(void) 
{
	
	char *p;
	char c_array[4]; // 
	p = &c_array[0];

	printf("%p\n", p);

	// Casting for pointers has a higher precedence than arithmetic operations.
	// Subsequently, it will add the scale of the size of a pointer by the size of the type.
	// Namely p + 28(7*4).
	int *ip = (int *) p + 7;
	printf("%p\n", ip);

	// (p + 7) has a higher precedence now because it is bracketed so it only
	// computes "p+7".
	ip = (int *) (p + 7);
	printf("%p\n", ip);





	return 0;
}
