
#include <stdio.h>
#include <string.h>
#include "citrus.h"

void test_assert();
void test_equals();
void *match(void *key, void *base, int n, int elm_size);

int main(int argc, char *argv[]) {

	test_assert();
	test_equals();
	summary();
	
	return 0;
}

void test_assert() {
	assert(1);
}

void test_equals() {
	equals(false, false);
	equals(true, true);
	equals(100, 100);
	equals_t(false, true, false);

	int *m;
	const int n = 2;
	int a[2] = {5, 4};
	int b[2] = {5, 4};
	
	equals_a(&a, &b, n, sizeof(int));
}
