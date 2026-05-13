#include <stdio.h>
#include <string.h>

#define N 1000000

void create_str(int n, char *s) 
{
	int i;
	for (i = 0; i < n; i++) {
		s[i] = i % 26 + 'A';
	}
	s[i] = '\0';

}

void lower1(char *s)
{
	int i;
	for (i = 0; i < strlen(s); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + ('a' - 'A');
	}
}

void lower2(char *s)
{
	int i;
	int len = strlen(s);
	for (i = 0; i < len; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + ('a' - 'A');
	}
}


int main(int argc, char *argv[])
{
	char s[N];
	create_str(N, s);
	/*
	 * When N is 1,000,000, this lower1() needs quite a few seconds to complete.
	 * Whereas, lower2 executes immediately.
	 * */ 
	//lower1(s);	
	lower2(s);
	printf("%s\n", s); 
	return 0;
}
