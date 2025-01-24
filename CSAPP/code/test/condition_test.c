#include <stdio.h>

int x_gt_y(int x, int y)
{
	int result;
	if (x >= y)
		result = x - y;
	else
		result = y - x;

	return result;
	
}
