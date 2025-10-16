#include <stdio.h>


int tmult_ok_1(long x, long y, long *dest)
{
	long result = 0;
	*dest = x * y;
	asm("setae %al");
	return result;
}
