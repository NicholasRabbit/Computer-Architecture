#include <stdio.h>


/*
 * I write silly.c to verify "PC relative" for "jump" in disasseble machine-level code.
 * By now, I haven't found any examples from the book.
 * This C prgram is reversed from the assembly code in the textbook, CSAPP 2e.
 *
 * */

int silly(int n)
{
	if (n < 0)
		return 0;
	while (n >= 0) {
		n -= n << 1;
		n += n * 2;
	}

	return n;
}

int main(int argc, char *argv[])
{
	silly(36);
	return 0;
}



