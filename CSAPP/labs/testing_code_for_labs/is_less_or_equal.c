#include <stdio.h>

/*
 * if x <= y, then return 1, else return 0
 *
 * */

/*
 * I, The two operands have the same sign.
 * */
int has_same_sign(int x, int y) 
{
	int sign_x = x >> 31 & 1;
	int sign_y = y >> 31 & 1;

	/*
	 * 1, Whether the two operands have the same sign.
	 * If these two operands, x and y, have the same sign, 'same_sign' is 0.
	 * Whereas,by convention in C '1' and '0' represent 'true' and 'false', respectively.
	 * So we should get the NOT of 'same_sign'.
	 * */ 
	int same_sign = !(sign_x ^ sign_y);

	return same_sign;

}

// To calculate operands with same sign
int subtract_result_of_same_sign(int x, int y) 
{
	/*
	 * We expect that y - x <= 0.
	 * */ 
	int res = (~x + 1) + y;
	// As aforemented, 0 should be converted to 1 to represent 'true'.
	res = !(res >> 31);

	return res;

}

int operation_of_same_sign(int x, int y)
{

	int same = has_same_sign(x, y);
	printf("Do %d and %d have the same sign ? ==> %d\n", x, y, same);

	int result = subtract_result_of_same_sign(x, y);
	printf("Is %d less than or equal to %d? %d\n", x, y, result);
	
	return same & result;

}

/*
 * II, The two operands have distinct signs.
 * It is simpler in this circumstance and what we need to do is to find whether 'x'
 * is positive or not. If x is a positive number or 0, y must be a negative one.
 * */
int operation_of_distinct_sign(int x, int y)
{
	int sign_x = x >> 31 & 1;
	int sign_y = y >> 31 & 1;
	// 'distinct' will be '1' if the two signs are different.
	int distinct = sign_x ^ sign_y;
	
	// If x is negative then 'sign_x' is 1 and y must be positive or zero, 
	// so flag is 1, which indicates that x <= y. On the other hand, it is the same.
	int flag = sign_x & distinct;

	return flag;
}





int main(void) 
{
	
	int x, y;

	printf("%s\n", "Please input two integers(x y):");
	scanf("%d %d", &x, &y);

	int r1 = operation_of_same_sign(x, y);

	int r2 = operation_of_distinct_sign(x, y);
	printf("r2 = %d\n", r2);

	return 0;
}



