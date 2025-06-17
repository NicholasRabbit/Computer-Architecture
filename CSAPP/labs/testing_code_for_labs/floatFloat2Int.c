#include <stdio.h>


int floatFloat2Int(unsigned uf) {
	/*
	 * 1. Check if it is a normalised float-point value.
	 * */
	int exp, E, frac, temp, f;
	exp = (uf << 1) >> 24;
	
	f = exp;
	
	return f;
}



int main(void) 
{
	unsigned uf = 0x4640e400;

	union {
		float f;
		unsigned u;
	} temp;
	temp.u = uf;


	printf("temp.f = %.1f\n", temp.f);
	printf("temp.u = 0x%.2x\n", temp.u);

	int ret = floatFloat2Int(uf);
	printf("ret = %.2x\n", ret);

	return 0;
}
