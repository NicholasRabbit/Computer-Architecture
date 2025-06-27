#include <stdio.h>

#define N 0x4640e400

/*
 * See page 143 where an integer was converted to a float by IEEE convention.
 * Here we reverse the conversion to finish the lab.
 *
 * */

int floatFloat2Int(unsigned uf) {
	/*
	 * 1. Check if it is a normalised float-point value.
	 * */
	int sign, exp, E, frac, bias, temp, f, normal;
	normal = 0;
	bias = 127;
	
	// 1.1 Get the exponent of the single-precision floating point value.
	exp = (uf << 1) >> 24;
	if (exp > 0 && exp < 255) {
		printf("exp = %.2x\n", exp);
		normal = 1;
	}

	// 1.2 Compute the E.
	E = exp - bias;
	printf("E = %d\n", E);

	/*
	 * 2. Retrieve the fractional part.
	 * The fractional part is the 23 least significant bits of the value.
	 * Note that if it is a normalised value we should add the implicit one 
	 * back to it. If it is a denormalised value, it is not necessary to do
	 * that.
	 * */
	frac = (uf << 9) >> 9;
	if (normal) {
		// Attention. 0x2 should be shifted by 23 bits not 24 bits
		// since "1" is already the least sigficant bit.
		int one = 0x1 << 23; 
		frac = one | frac;
	}
	printf("fraction = 0x%.2x\n", frac);

	/*
	 * 3. Shift the fraction to the right to restore the integer value.
	 * */
	int shift_bits = 23 - E;
	frac = frac >> shift_bits;

	// 4. Get the sign of the single-precision floating-point value.
	sign = (uf >> 31) << 31;

	// 5. Compute the final integer value.
	int int_value = sign | frac;

	printf("int_value = %d\n", int_value);
	

	
	f = exp;
	
	return f;
}



int main(void) 
{
	unsigned uf = N;

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
