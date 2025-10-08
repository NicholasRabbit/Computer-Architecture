#include <stdio.h>

int tmult_ok_3 (long x, long y, long *dest)
{
	unsigned char b_result;
	*dest = x * y;
	
	asm("setae %[b]  # set result"
		: [b] "=r" (b_result)  /* Output */ 
	   );

	return b_result;

}
