/*
 * Imperative-style code.
 * GCC generate conditional control transfer for it.
 * */
void minmax1(int a[], int b[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			int t = a[i];
			a[i] = b[i];
			b[i] = t;
		}
	}
}


