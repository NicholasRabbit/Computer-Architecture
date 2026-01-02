#include <stdio.h>

//
int phaes_6(int arr[]) 
{
	int i, j;
	for (i = 0; i < 6; i++) 
		for (j = 1; j <=5; j++) {
			if (arr[i] != arr[j])
				continue;
			else
				break;
		}


}
