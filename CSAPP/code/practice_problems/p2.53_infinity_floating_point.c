#include <stdio.h>


#define POS_INFINITY 1e400
#define NEG_INFINITY (-POS_INFINITY)
#define NEG_ZERO (-1.0 / POS_INFINITY)



int main(void) 
{
	// 1e2 is 1x10^2
	float f = 1e2;
	printf("%f\n", f);

	// check whether the results are correct.
	printf("positive infinity: %lf\n", POS_INFINITY);
	printf("negative infinity: %lf\n", NEG_INFINITY);
	printf("negative zero: %lf\n", NEG_ZERO);
	

	return 0;
}
