
#include <stdio.h>
#include <string.h>
#include "citrus.h"

void test_assert();
void test_equals();

void *match(void *key, void *base, int n, int elm_size);
void *match2(void *key, void *base, int n, int elm_size, 
	int (*callback)(void *, void*));
int int_cmp(void *a, void *b);
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
	
	if((m = match(&b, a, n, sizeof(int))) != NULL){
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

// do a linear search on an array of which we dont know the type.
// return the element which is a match. 
void *match(void *key, void *base, int n, int elm_size) {
	int i, j;
	for(i = 0; i < n; i++) {
		void *key_addr = (char *)key + i * elm_size;
		void *elm_addr = (char *)base + i * elm_size;
		if(memcmp(key_addr, elm_addr, elm_size) != 0)
			return elm_addr;
	}
	return NULL;
}

void *match2(void *key, void *base, int n, int elm_size, 
	int (*callback)(void *, void*)) {
	int i;
	for(i = 0; i < n; i++) {
		void *elm_addr = (char*)base + i *elm_size;
		if(callback(key, elm_addr) == 0){
			return elm_addr;
		}
	}
	return NULL;
}

