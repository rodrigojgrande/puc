#include <stdlib.h>
#include <stdio.h>

int ff(int n);

int main() {
	int r;
	r = ff(7);
	printf("%d", r);
	return 0;
}

int ff(int n) {
	if (n == 1)
		return 1;
	if (n % 2 == 0)
		return ff(n/2);
	return ff((n-1)/2) + ff((n+1)/2);
}
