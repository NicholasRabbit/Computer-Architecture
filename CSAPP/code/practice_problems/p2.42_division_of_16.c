#include <stdio.h>

int div16(int x) 
{
	return x >> 4;
}

int main(void) 
{
	int x, result;
	printf("Please input a dividend: ");
	scanf("%d", &x);
	result = div16(x);

	printf("The result is %d\n", result);

	return 0;

}
