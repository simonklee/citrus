
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
	/*char *a[] = {1, 2};
	char *b[] = {1, 2};
	equals_a(&a, &b);*/
	int *m;
	int n = 2;
	int a[2] = {5, 4};
	int b[2] = {5, 4};
	
	if((m = match(&b, &a, n, sizeof(int))) != NULL){
		printf("m equals: %d\n", *m);
	}
}

void swap (int *ap, int *bp) {
	int tmp = *ap;
	*ap = *bp;
	*bp = tmp;
}

void swap2 (void *vp1, void *vp2, int size) {
	char buffer[size];
	memcpy(buffer, vp1, size);
	memcpy(vp1, vp2, size);
	memcpy(vp2, buffer, size);
}

