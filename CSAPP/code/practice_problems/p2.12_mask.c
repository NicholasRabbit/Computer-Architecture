# include<stdio.h>



int main (void) 
{
	// The answer of question A.
	int i = 0x87654321;
	int result = i & 0xFF ;
	printf("Answer of A: 0x%x\n", result);

	// The answer of question B.
	result = i & ~0xFF;
	printf("Answer of B: 0x%x\n", result);

	// The answer of C.
	result = i | 0xFF;
	printf("Answer of C: 0x%x\n", result);


	return 0;
}
