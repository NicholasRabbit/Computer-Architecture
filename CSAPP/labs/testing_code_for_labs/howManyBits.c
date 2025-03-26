#include <stdio.h>

int howManyBits(int x);
char howManyBitsChar(char x);


int main(void) 
{
	printf("Please input a number: \n");
	int num;
	scanf("%x", &num);
	//num = howManyBits(num);
	num = howManyBitsChar(num);
	printf("How many bits? ==> %d\n", num);
	return 0;
}

int howManyBits(int x) 
{
	int sign = x >> 31;
	int abs_x = (sign & ~x);
	int abs_y = (~sign & x);

	return abs_x;

}

char howManyBitsChar(char x) 
{
	char sign = x >> 7;
	char abs_x = sign & ~x;
	char abs_y = ~sign & x;
	char result = abs_x | abs_y;
	return result;
}


