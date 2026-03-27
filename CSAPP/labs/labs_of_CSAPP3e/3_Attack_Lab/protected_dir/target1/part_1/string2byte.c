#include <stdio.h>

// Covert an argument to its byte representation. 
int main(int argc, char *argv[])
{
	
	if (argc < 2) {
		printf("Please input a string\n");
		return 1;
	}


    char *cp = argv[1];
	int i = 0;
	while (*(cp + i) != '\0') {
		printf("%x ", *(cp + i));
		i++;
	}
	
	return 0;

}
