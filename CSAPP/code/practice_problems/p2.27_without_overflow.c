#include <stdio.h>


/*
 * Write a function to determine whether arguments can 
 * be added without overflow.
 * The return value should be 1 if arguments were added without overflow.
 * */

// A data type with 4 bits.
//typedef struct {
//	unsigned int value:4;
//} four_bits_data;


int uadd_ok(unsigned x, unsigned y) 
{
	return x + y >= x;
}



int main(void) 
{
	
	unsigned x, y;
	//x = 0xffffffff;
	x = 0x1;
	y = 0xab;
	int result = uadd_ok(x, y);
	printf("Is it overflow? 1:no, 0:yes.==> %d\n", result);


	return 0;

}
