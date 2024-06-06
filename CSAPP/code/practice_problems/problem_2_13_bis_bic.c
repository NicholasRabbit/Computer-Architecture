# include<stdio.h>


/*
 * Here is my elaboration of the opeation of bis.
 *
 * 1, bis
 * If x is 1010 and m is 0110, then z is 1110.
 * Because the second and third bit of m is "1", so x is set 
 * to 1110 and the rest bits of "x" don't change.
 * 
 * 2, bic
 * It is diffcult to elaborate "bic" with expressions in C.
 * I am trying to do it.
 * If a bit in x is set to 0 when it is modified by a bit of 1 in m, 
 * because 0 & any bits is zero and ~1 is 0. Presumably, the expression
 * is x & ~m.
 *
 *
 * */

// Using C expressins is allowed.
char bis(char x, char m)
{
	return x | m;
}

char bic(char x, char m)
{
	return x & ~m;
}

// or "|"
char bool_or(char x, char y)
{
	char result = bis(x, y);
	return result;

}

// XOR "^"
// Because x^y = (x & ~y) | (~x | y), we get the following answer.
char bool_xor(char x, char y)
{
	char result = bis(bic(x, y), bic(y ,x));
	return result;
	
}
int main(void)
{
	/*
	 * char's footprint is one byte.
	 * 0000,1100(0xc) 
	 * 0000,0100(0x4)
	 * */
	char ret = bool_or(0xc, 0x4);
	printf("0x%.2x\n", ret);

	ret = bool_xor(0xc, 0x4);
	printf("0x%.2x\n", ret);

	return 0;

}



