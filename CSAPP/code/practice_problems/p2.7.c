# include <stdio.h>
# include <string.h>

/**
 * Representing strings. Strings in C is just an array of characters.
 * 2.7
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



int main(int argc, char const *argv[])
{
	const char *m = "mnopqr";

	show_bytes((byte_pointer)m, strlen(m));

	return 0;
}

