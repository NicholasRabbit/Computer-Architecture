#include <stdio.h>

int howManyBits(int x);


int main(void) 
{
	printf("Plea input a number: \n");
	int num;
	scanf("%d", &num);
	num = howManyBits(num);
	printf("How many bits? ==> %d\n", num);
	return 0;
}

int howManyBits(int x) 
{
	x = x | x >> 1;
	x = x | x >> 2;
	x = x | x >> 4;
	x = x | x >> 8;
	x = x | x >> 16;
	
	return (x + 1) >> 1;

}
