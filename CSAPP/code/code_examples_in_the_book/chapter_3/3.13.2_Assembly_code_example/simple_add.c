#include <stdio.h>


int simple_add(int *xp, int y)
{
	int t = *xp + y;
	*xp = t;
	return t;

}


int main(void) 
{
	int *xp, z;
	z = 10;
	xp = &z;

	simple_add(xp, 5);

	return 0;

}
