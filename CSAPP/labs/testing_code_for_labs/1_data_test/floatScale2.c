#include <stdio.h>

unsigned floatScale2(unsigned uf)
{
	// 1. To extract the sign.
	unsigned s = uf >> 31;
	// 2. To slice the exponent.
	unsigned exp = (uf >> 23) & 0xff;
	// 3. To retrive the fractional part. 
	unsigned frac = (uf << 9) >> 9; 

	// NaN
	if (exp == 0xff)
		return uf;
	// Denormalised Values. It is not necessary to add the implicit leading "1"
	// to the significand.Thus, we only need to multiply fraction by 2.
	else if (exp == 0x0) {
		frac = frac << 1;
		return (s << 31) | exp <<23 | frac;
	}
	// Normalised Values
	else
		// Implementing 2*f by adding 1 to the exponent.
		exp += 1; 

	return (s << 31) | exp <<23 | frac;

}



int main(void) 
{
	unsigned uf;
	printf("Please input a hexadecimal numbber:\n");
	scanf("%x", &uf);

	unsigned result = floatScale2(uf);
	printf("0x%.2x\n", result);

	return 0;
}

