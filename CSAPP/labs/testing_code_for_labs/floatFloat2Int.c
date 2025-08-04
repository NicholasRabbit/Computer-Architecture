#include <stdio.h>

#define N 0x4640e400

// To illustrate, 0x7f80 0000 has the exponent of all 1s,
// which indicates the number is NaN.
#define M 0x7f800000


/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */


/*
 * See page 143 of CSAPP 2nd where an integer was converted to a float by IEEE convention.
 * Here we reverse the conversion to finish the lab.
 *
 * */

int floatFloat2Int(unsigned uf) {
	/*
	 * 1. First of all, we should get the three fields of a single-pression number,
	 * which are a sign, an exponent and a fraction.
	 * */
	unsigned sign, exp;
	int E, frac, bias, normal;
	normal = 0;
	bias = 127; // 2^k - 1. k bits of the exponent.
	
	// 1.1 Get the sign of the single-precision floating-point value.
	sign = (uf >> 31) << 31;
	
	// 1.2 Get the exponent of the single-precision floating point value.
	exp = (uf << 1) >> 24;
	// 1.2.1 Compute the E.
	E = exp - bias;
	printf("E = %d\n", E);

	/*
	 * 1.3. Retrieve the fractional part.
	 * The fractional part is the 23 least significant bits of the value.
	 * Note that, by the convention of IEEE, if it is a normalised value we should add the implicit 1 
	 * back to it. If it is a denormalised value, it is not necessary to do
	 * that.
	 * */
	frac = (uf << 9) >> 9;

	// 2. If exponent equals 0xff, it is either NaN or infinity whatever the fraction is.
	if (exp == 0xff)
		return 0x80000000u;

	// To check if it is a normalised value.
	if (exp > 0 && exp < 255) {
		printf("exp = %.2x\n", exp);
		normal = 1;
	}


	if (normal) {
		// To Add the impplicit one back to a normalised value.
		// Attention! 0x1 should be shifted by 23 bits not 24 bits to the 24th bit from left
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


	// 5. Generate the final integer value.
	int int_value = sign | frac;

	printf("int_value = %d\n", int_value);
	
	return int_value;

}


// Printing representation of bits of various data types.
int union_f(unsigned uf)
{
	union {
		float f;
		unsigned u;
	} temp;
	temp.u = uf;

	printf("temp.f = %.1f\n", temp.f);
	printf("temp.u = 0x%.2x\n", temp.u);

	return 0;
}


int main(void) 
{
	unsigned uf = M;

	union_f(uf);

	int ret = floatFloat2Int(uf);
	printf("integer = 0x%.2x\n", ret);

	return 0;
}
