#include <stdio.h>
#include <string.h>

/**
 * Practice 2.26 on page 77.
 *
 * The incorrect result of comparing the length of two strings with
 * the "size_t strlen(const char *s)" in the C library.
 * Apparently, the return result is a type of "size_t" which is unsigned.
 *
 *
 * To answer the question on the book.
 * A. The result is incorrect when "s" is smaller than "t".
 * B. Explanatioin as follows.
 * What is wrong with the following code?
 * The problem is that the return value is always 1 because two result of
 * calculation of two unsigned numbers is equal or larger than 0.
 * C. We can modify the code like that: "strlen(s) > strlen(t)".
 *
 * */
int strlonger(char *s, char *t)
{
	//return strlen(s) - strlen(t) > 0;
	printf("strlen(s) = %u\n", strlen(s));
	printf("strlen(t) = %u\n", strlen(t));
	return strlen(s) > strlen(t);
} 


int main(void)
{

	char s[] = {'a', 'b', '\0'};
	char t[] = {'x', 'y', 'z', '\0'};

	int result =  strlonger(s, t);
	printf("result = %d\n", result);

	return 0;

}
