#include <stdio.h>


struct P1 {
	int i;
	char c;
	int j;
	char d;

};

struct P2 {
	int i;
	char c;
	char d;
	int j;
};

struct P3 {
	short w[3];
	char c[3];
};

/*
 * In a Linux/IA32 machine, the size of p4 is 20,
 * but here is 32 in a 64-bit machine.
 * */
struct P4 {
	short w[3];
	char *c[3];
};

/*
 * The size of p5 is also distinct in a Linux/IA32 and 
 * a 64-bit machine. 
 * */
struct P5 {
	struct P1 a[2];
	struct P2 *p;
};


int main(void) 
{

	struct P1 p1;
	struct P2 p2;
	struct P3 p3;
	struct P4 p4;
	struct P5 p5;

	printf("P1: %lu\n", sizeof p1);
	printf("P2: %lu\n", sizeof p2);
	printf("P3: %lu\n", sizeof p3);
	printf("P4: %lu\n", sizeof p4);
	printf("P5: %lu\n", sizeof p5);

	return 0;

}
