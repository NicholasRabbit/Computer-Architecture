#include <stdio.h>


#define TYPE short *
#define EXPR (&up->t1.d)



typedef union {
	struct {
		short v;
		short d;
		int	  s;
	} t1;
	struct {
		int a[2];
		char *p;
	} t2;

} u_type;

void get (u_type *up, TYPE *dest) 
{
	*dest = EXPR;
} 


int main(void) 
{
	
	u_type *up, my_u;
	up = &my_u;
	printf("%p\n", EXPR);
	return 0;
}


