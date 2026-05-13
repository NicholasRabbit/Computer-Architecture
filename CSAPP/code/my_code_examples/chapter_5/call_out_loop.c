#include <stdio.h>

/*
 * A simplified verion to move a call to a function out of a loop.
 * */

int in_loop(int n)
{
	return n + 1;
}



int main(int argc, char *argv[])
{

	int i = 5;
	for (i = 0; in_loop(i) < 5; i++) {
			
	}
	return 0;
}
