#include <stdio.h>

typedef struct ELE {
	int val;
	struct ELE *next;
} *list_ptr;

int rsum_list(list_ptr ls)
{
	if (!ls)
		return 0;
	else {
		int val = ls->val;
		int rest = rsum_list(ls->next);
		return val + rest;
	}
}


int main(int argc, char *argv[])
{
	struct ELE ele1, ele2, ele3;
	ele1.val = 0x00a;
	ele1.next = &ele2;
	ele2.val = 0x0b0;
	ele2.next = &ele3;
	ele3.val = 0xc00;
	ele3.next = 0;
	rsum_list(&ele1);
	return 0;
}
