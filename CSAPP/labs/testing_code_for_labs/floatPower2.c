#include<stdio.h>

#define INF 0x7f800000


unsigned floatPower2(int x)
{
	// The bit-level representation of 2.0.
	unsigned  t = 0x40000000;
	
	if (x < -126)
		return 0;
	if (x > 127)
		return INF;  // return infinity.

	// Decompose the single-precision floating-point value into 
	// three fields, which is represented by an unsigned value.
	unsigned s, exp, frac;
	s = (t >> 31) << 31;
	exp = (t >> 23) & 0xff;
	frac = (t << 9) >> 9;

	exp = x + 127;
	exp = exp << 23;

	return s | exp | frac;

}



/*
 * 2.0 equals 1.0x2^2.
 * 
 * */
int union_f(unsigned uf)
{
	union {
		float f;
		unsigned u;
	} temp;

	//temp.f = 2.0;
	temp.u = uf;

	printf("temp.f = %.1f\n", temp.f);
	printf("temp.u = 0x%.2x\n", temp.u);

	return 0;
}


int main(void) 
{
	union_f(INF);

	unsigned result = floatPower2(4);
	union_f(result);

	return 0;

}

