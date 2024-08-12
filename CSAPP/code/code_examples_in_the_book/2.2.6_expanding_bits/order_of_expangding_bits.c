# include<stdio.h>



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

	/*
	 * When converting short to unsigned, we first change the size form 2 bytes to 4 bytes
	 * so that the result is 0xff on the leading bits and then from signed to unsigned.
	 *
	 * NOT: if we first change the signed number to unsigned and then changed the size 
	 * the resut would be 0x00c7cf. But it is not the way in which C works.
	 * */
	short sx = -12345;
	unsigned uy = sx;

	printf("uy = %u: \t", uy);
	show_bytes((byte_pointer)&uy, sizeof(unsigned));

	return 0;
}
