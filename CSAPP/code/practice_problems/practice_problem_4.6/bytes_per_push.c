#include <stdio.h>

/*
 * This code is nothing to do with the practice. I write the code here so that it is can be searched easily 
 * since this practice is about embedding assembly to C code.
 *
 * To test how many bytes per push in a x86-64 machine, namely to find out how many byte per row in a stack.
 * */

int bytes_per_push()
{
	
	asm("mov $0x3, %rax  # Move m to rax \n\t"
		"push %rax		# Push rax \n\t"
			);

	return 0;
}

int main(int argc, char *argv[])
{
	bytes_per_push();
	return 0;
}
