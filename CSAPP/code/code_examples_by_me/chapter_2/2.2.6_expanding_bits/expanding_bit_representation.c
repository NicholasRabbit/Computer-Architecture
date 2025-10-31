# include<stdio.h>

/*
 * 2.2.6 (2rd Edition of CSAPP)
 * Papge 72
 *
 * Note: 
 * The operating system is little endian which is different from the OS used 
 * in the book. 
 *
 * */

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
	int i;
	for (i = 0; i < len; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}



int main (void) 
{
	// 1. Convert a signed short number to an unsigned short.
	short sx = -12345;
	unsigned short usx = sx;

	printf("sx = %d: \t", sx);
	show_bytes((byte_pointer)&sx, sizeof(short));

	printf("usx = %u: \t", usx);
	show_bytes((byte_pointer)&usx, sizeof(short));
	
	// 2. Convet short(signed and unsigned) to int.
	int x = sx;
	unsigned ux = usx;

	printf("x = %d: \t", x);
	show_bytes((byte_pointer)&x, sizeof(int));

	printf("ux = %u: \t", ux);
	show_bytes((byte_pointer)&ux, sizeof(int));



	return 0;
}
