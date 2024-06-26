# include <stdio.h>

/**
 * Though I don't completely understand the following code because of c syntax,
 * the intention of the author is clearly for me. More elaboration will be added 
 * in the near future.
 *
 * Elaboration in P77(CSAPP,3rd). Here are the extracts.
 * (byte_pointer) start means cast the start to the type of byte_pointer.
 * %.2x indicates that the integer should be printed at least two digits.
 * &x: to the pointer of x.
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

void show_int(int x)
{
	show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
	show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer)&x, sizeof(void *));
}

void test_show_bytes(int val)
{
	int ival = val;
	float fval = (float)ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}


int main(int argc, char const *argv[])
{
	test_show_bytes(12345);
	return 0;
}

