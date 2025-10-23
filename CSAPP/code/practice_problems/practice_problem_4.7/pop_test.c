#include <stdio.h>

/*
 * gcc command is
 * >gcc -m32 -S pop_test.c   # to generate assembly code
 * >gcc -32 -Wall pop_test.c -o test_pop.out  # to generate an executable file.
 *
 * */


int pop_test(int i)
{
	// Note that the register in which the varialbe "i" is stored is 
	// designated by GCC assembler, but we can move a value into it
	// and set it to the return value. 
	// Set the argument to 0 is to intialise it. 
	asm("pushl $0xabcd  # push 0xabcd to the top of current stack \n\t"
		"popl %%esp  # push to the statck pointer esp manually to test \n\t"
		"movl %%esp, %[val]  # Move the value in esp to a register \n\t"
		: [val] "=r" (i)  /* Outputs */
		:				 /* Inputs */
		: "%eax"
		);
	
	return i;


}


int main(int argc, char *argv[])
{
	int result = pop_test(0);
	printf("result is 0x%.4x\n", result);

	return 0;
}

