#include <stdio.h>

/*
 * It is a code demo in Lecture 03 of the video course.
 * It is used to find out whether a machine is big or little endian.
 *
 * Note that in little-endian machine the least significant bits are in
 * lower memory address. 
 * */

typedef unsigned char *pointer;

void show_bytes(pointer start, size_t len)
{
	size_t i;
	/*
	 * Since 'start' has been cast to 'char *', "start + i" will increment 1 byte each time.
	 * */
	for (i = 0; i < len; i++) 
		printf("%p\t0x%.2x\n", start + i, start[i]);	
	printf("\n");
}


int main(void) 
{
	int a = 15213;
	printf("int a = 15213; a = 0x%.2x\n", a);
	show_bytes((pointer) &a, sizeof(int));

	return 0;
}
