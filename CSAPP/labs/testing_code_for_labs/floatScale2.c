#include <stdio.h>

unsigned floatScale2(unsigned uf)
{
	
	unsigned s = uf >> 31;
	unsigned exp = (uf >> 23) & 0xff;
	exp += 1; 
	unsigned frac = (uf << 9) >> 23;

	unsigned result = (s << 31) | exp <<23 | frac;

	return result;
}



int main(void) 
{
	unsigned uf;
	printf("Please input a hexadecimal numbber:\n");
	scanf("%x", &uf);

	unsigned result = floatScale2(uf);
	printf("%.2x\n", result);

	return 0;
}

