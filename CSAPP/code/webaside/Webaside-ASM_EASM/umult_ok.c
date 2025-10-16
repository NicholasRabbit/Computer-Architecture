#include <stdio.h>


int umult_ok (unsigned long x, unsigned long y, unsigned long *dest)
{
	unsigned char b_result;

	asm("movq %[x], %%rax  # Get x \n\t"
		"mulq %[y]	# Unsigned long multiply by y \n\t"  
		"movq %%rax, %[p]	# Store lower 8 bytes at 'dest' \n\t"
		"setae %[b]		# Set b_result"
		: [p] "=m" (*dest), [b] "=r" (b_result)  /* Outputs	*/
		: [x] "r" (x), [y] "r" (y)	/* Inputs */
		: "%rax", "%rdx"	/* Overwrites*/
	   );

	return (int) b_result;
}
