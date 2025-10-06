#include <stdio.h>

int tmult_ok_asm(long x, long y, long *dest)
{
	long p = x * y;
	*dest = p;

	return p > 0;
}
