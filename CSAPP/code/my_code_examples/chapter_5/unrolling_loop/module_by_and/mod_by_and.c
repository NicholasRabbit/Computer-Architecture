#include <stdio.h>

int mod_by_and(int m, int n)
{
	return n & m;
}

int main(int argc, char *argv[])
{

	int m, n;
	m = 3;
	n = 30;
	int i;
	for (i = 1; i < n; i++) {
		int r = mod_by_and(m, i);
		int mod = i % (m + 1);
		printf("%d %% %d = %d ?= %d\n", i, m, r, mod);
	}
	return 0;
}
