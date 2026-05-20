#include <stdio.h>
#include <stdlib.h>

#define IDENT 1
#define OP *
#define INT

#include "combine.h"

/*
 * I write this program to verify whether the machine-level code eliminates
 * unneeded memory references as shown in "5.6 Elinimating Unneeded Memory References".
 * The C code is not necessarily as same as the the textbook, but it has the same feature
 * of that.
 *
 * Presumably, the assembly code is distinct from that in the textbook. To be analysed later. 
 * */
typedef struct {
	long int len;
	data_t *data;
} vec_rec, *vec_ptr;


vec_ptr new_vec(long int len) 
{
	/* Allocate header structure */
	vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));

	if (!result)
		return NULL;
	result->len = len;

	/* Allocate array */
	if (len > 0) {
		/*
		 * "calloc(len, n) allocates memory for an array with the length of "len" and each element
		 * with the size of n.
		 * */
		data_t *data = (data_t *)calloc(len, sizeof(data_t));
		if (!data) {
			free((void *) result);
			return NULL;
		}
		result->data = data;
	}
	else
		result = NULL;

	return result;

}

long int vec_length(vec_ptr v)
{
	return v->len;
}


data_t *get_vec_start(vec_ptr v)
{
	return v->data;
}



void combine3(vec_ptr v, data_t *dest)
{
	long int i;
	long int len = vec_length(v);
	data_t *data = get_vec_start(v);

	*dest = IDENT;
	for (i = 0; i < len; i++) {
		*dest = *dest OP data[i];
	}
	

}


int main(int argc, char *argv[])
{
	data_t arr[3] = {2, 3, 5};
	data_t dest[3];
	
	vec_rec v;
	v.len = 3;
	v.data = arr;

	combine3(&v, dest);

	return 0;
}
