#include <stdio.h>

char *gets(char *s)
{
	int c;
	char *dest = s;
	int gotchar = 0;
	// The aim of the following while loop is to generate a char array
	// from input data on CLI.
	while ((c = getchar()) != '\n' && c != EOF) {
		*dest++ = c;
		gotchar = 1;
	}

	*dest++ = '\0';

	if (c == EOF && !gotchar)
		return NULL;

	return s;

}

int echo()
{

	char buf[8];

	gets(buf);
	int i;
	//for (i = 0; i < 8; i++)
	//	printf("%c\n", buf[i]);

	puts(buf);

	printf("buf[8] = %c\n", buf[8]);

	return 0;
}


int main(void) 
{

	echo();
	return 0;
}
