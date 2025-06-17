# include <stdio.h>

/**
 * 2.5
 * 
 * */

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%p  %.2x\t", &start[i], start[i]);
	printf("\n");
}



int main(int argc, char const *argv[])
{
	int a = 0x12345678;
	byte_pointer ap = (byte_pointer) &a;

	show_bytes(ap, 1);
	show_bytes(ap, 2);
	show_bytes(ap, 3);
	show_bytes(ap, 4);

	return 0;
}

