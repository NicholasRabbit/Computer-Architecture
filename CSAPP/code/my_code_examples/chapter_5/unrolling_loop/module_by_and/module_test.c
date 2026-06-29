#include <stdio.h>


int get_mod_by_and(int m, int n)
{
	int i;
	for (i = 0; i <= n; i++)
		printf("%d & %d = %d\n", i, m, i & m);
	return 0;
}


int main(int argc, char *argv[])
{
	get_mod_by_and(7, 16);
	return 0;
}
