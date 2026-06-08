#include <stdio.h>

#define N 5

void minmax1(int a[], int b[], int n);

int main(int argc, char *argv[])
{
	int a[N] = {1, 2, 3, 4, 5};
	int b[N] = {5, 4, 3, 2, 1};
	minmax1(a, b, N);
	int i;
	for (i = 0; i < N; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;

}
