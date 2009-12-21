#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citrus.h"

// (member) functions.
static test *addtest(suit *s);

// is it true?
int assert(suit *s, int value) {
	return equals_t(s, true, value, true);
}

// does it match?
int equals(suit *s, int expected, int actual) {
	equals_t(s, expected, actual, true);
}

// does it match, are you sure?
int equals_t(suit *s, int expected, int actual, int truth) {
	test *t = addtest(s);
	if((expected == actual) == truth){
		t->pass = true;
		return true;
	} else {
		t->pass = false;
		return false;
	}		
}

// match a generic set of datatype's stored in two arrays.
// use functions(void *, void *) as comparators. 
int equals_a(suit *s, void *key, void *base, int n, int elmsize, 
	int (*callback)(void *, void*)) {
	
	int i;
	test *t = addtest(s);
	for(i = 0; i < n; i++) {
		void *keyaddr = (char *)key + i * elmsize;
		void *elmaddr = (char*)base + i *elmsize;
		if(callback(keyaddr, elmaddr) != 0){
			t->pass = false;
			return false;
		}
	}
	t->pass = true;
	return true;
}

int integercmp(void *a, void *b) {
	int *ap = a;
	int *bp = b;
	
	return *ap - *bp;
}

int stringcmp(void *a, void *b) {
	char *str1 = *(char **)a;
	char *str2 = *(char **)b;
	
	return strcmp(str1, str2);
}

// Create a new node for our tests, add it to list.
static test *addtest(suit *s) {
	test *node;
	node = malloc(sizeof *node);
	memset(node, 0, sizeof *node);
	
	// no need to link it if it is our first time.
	if(s->tests == 0){
		s->tests = node;
	} else {
		node->prev = s->tests; // link it.
		s->tests = node; // set last test as head.
	}
	
	s->total++; // increment.
	return s->tests; // return head. 
}

// print a summary of the test's.
void summary(suit* s){
	int pass = 0, fail = 0;
	test *heads = s->tests;
	
	printf("*********************\n");
	while(heads) {
		if(heads->pass == true)
			pass++;
		else if(heads->pass == false)
			fail++;
		heads = heads->prev;
	}
	printf("pass: %d, fail: %d\n", pass, fail);
	printf("total: %d\n\n", s->total);
}

