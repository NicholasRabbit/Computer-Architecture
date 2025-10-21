#include <stdio.h>


int tmult_ok_1(long x, long y, long *dest)
{
	long result = 0;
	*dest = x * y;
	asm("setae %al");  // %al is the least 8 bits of %eax:bp

	return result;

}
