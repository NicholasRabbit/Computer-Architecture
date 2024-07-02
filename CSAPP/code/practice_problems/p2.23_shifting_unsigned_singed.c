# include<stdio.h>

// Right right shifts of signed values are performed arithmetically while
// the right shifts of unsigned values are performed logically.
//
// The question is at page 74 and the answer is at page 141 of the 2nd edition of CSAPP.
/*
 * For example: 
 * 0x0000,00C9 >> 24 = 0xC9, its most sigficant bit is '1', so result of arithmetical shifting 
 * of '0xC9 >> 24' is 0xFFFF,FFC9.
 * */
int func1(unsigned word)
{
	return (int) ((word << 24) >> 24);
}

int func2(unsigned word)
{
	// (int) will convert the unsigned number to a signed one.
	return ((int)word << 24) >> 24;
}

int main (void) 
{

	unsigned int word;
	printf("Please input a hexdecimal number without '0x':");
	scanf("%x", &word);

	printf("The input value is 0x%x\n", word);

	int ret1 = func1(word);
	printf("func1 = %.2x\n", ret1);

	int ret2 = func2(word);
	printf("func2 = %.2x\n", ret2);


	return 0;
}
