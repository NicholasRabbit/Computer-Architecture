#include <stdio.h>

/*
 * This reversing code of the assembly code of "func4(...)"
 * hasn't been finished yet. 
 *
 * */
int func4(int x, int y, int z)
{
	int t = 0;

	int m = x - y;
	int n = m >> 31;

	int k = m + n;
	int j = k >> 1;

	int l = j + y;

	if (l > z) {
		t = t + func4(x - 1, l, z);
	} else {
		func4(x, l + 1, z);
		t = j*2 + 1;
	}

	return t;



}
