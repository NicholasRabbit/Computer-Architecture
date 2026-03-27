#include <stdio.h>

int main(int argc, char *argv[])
{
	char *s = "x";
	int cookie = 0x59b997fa;
	sprintf(s, "%.8x", cookie);
	printf("%s\n", s);
	return 0;
}
