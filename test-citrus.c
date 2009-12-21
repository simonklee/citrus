
#include <stdio.h>
#include <string.h>
#include "citrus.h"

void testassert(suit *s);
void testequals(suit *s);

void *match(void *key, void *base, int n, int elmsize);
void *match2(void *key, void *base, int n, int elmsize, 
	int (*callback)(void*, void*));
int intcmp(void *a, void *b);
int stringcmp(void *a, void *b);

int main(int argc, char *argv[]) {
	suit s, *sp;
	sp = &s;
	init(sp);
	testassert(sp);
	testequals(sp);
	summary(sp);
	
	return 0;
}

void testassert(suit* s) {
	assert(s, 1);
}

void testequals(suit* s) {
	equals(s, false, false);
	equals(s, true, true);
	equals(s, 100, 100);
	equals_t(s, false, true, false);

	int *m;
	const int n = 2;
	int a[2] = {5, 4};
	int b[2] = {5, 4};
	
	equals_a(s, &a, &b, n, sizeof(int));
	
	if((m = match(&b, a, n, sizeof(int))) != NULL){
		printf("m equals: %d\n", *m);
	}
	
	char *txt[] = {"Abc", "Def", "Ghi", "Jkl"};
	char *def = {"Def"};
	//	char **found = 
	//match2(&def, txt, 4, sizeof(char *), strcmp);
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
void *match(void *key, void *base, int n, int elmsize) {
	int i, j;
	for(i = 0; i < n; i++) {
		void *keyaddr = (char *)key + i * elmsize;
		void *elmaddr = (char *)base + i * elmsize;
		if(memcmp(keyaddr, elmaddr, elmsize) != 0)
			return elmaddr;
	}
	return NULL;
}

void *match2(void *key, void *base, int n, int elmsize, 
	int (*callback)(void *, void*)) {
	int i;
	for(i = 0; i < n; i++) {
		void *elmaddr = (char*)base + i *elmsize;
		if(callback(key, elmaddr) == 0){
			return elmaddr;
		}
	}
	return NULL;
}

int intcmp(void *a, void *b) {
	int *ap = a;
	int *bp = b;
	
	return *ap - *bp;
}

int stringcmp(void *a, void *b) {
	char *str1 = *(char **)a;
	char *str2 = *(char **)b;
	return strcmp(str1, str2);
}

void newstack(stack *s) {

}
