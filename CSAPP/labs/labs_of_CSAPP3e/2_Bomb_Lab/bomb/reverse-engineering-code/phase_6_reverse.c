#include <stdio.h>

//
int phaes_6(unsigned int arr[]) 
{
	int i, j;
	for (i = 0; i < 6; i++) 
		if (arr[i] - 1 <= 5) {
		
			for (j = 1; j <=5; j++) {
				if (arr[i] != arr[j])
					continue;
				else {
					// call explode_bomb().
				}
			}

		} else {
			// call explode_bomb().
		}

	return 0;
}

int main(int argc, char *argv[])
{

	if (argc < 2)
		printf("Please input numbers: phase_6 numbers");

	// There are "argc - 1" elements, but '\0' should be at the end of the array.
	// Hence, the array is intialised with the number of "argc".
	unsigned int arr[argc]; 

	int i;
	for (i = 0; i < argc; i++) {
		//arr[argv[i] - '0'] = i;
		printf("%c\n", argv[i]);
	}

	for (i = 0; i < argc; i++) 
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
