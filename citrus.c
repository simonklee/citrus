#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citrus.h"

// (member) functions.
static test *addtest(suit *s);

// is it true?
int asserts(suit *s, int value) {
	return equals_t(s, true, value, true);
}

// does it match?
int equals(suit *s, int expected, int actual) {
	return equals_t(s, expected, actual, true);
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
int equals_a(suit *s, void *a, void *b, int n, int elmsize, 
	int (*callback)(void *, void*)) {
	
	int i, err;
	test *t = addtest(s);
	for(i = 0; i < n; i++) {
		void *aaddr = (char *)a + i * elmsize;
		void *baddr = (char *)b + i * elmsize;
		if((err = callback(aaddr, baddr)) != 0){
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
	int i;
	test *node;
	node = malloc(sizeof *node);
	memset(node, 0, sizeof *node);
		
	// no need to link it if it is our first time.
	if(s->tests == 0){
		s->tests = node;		
		node->count++;
	} else {
		node->prev = s->tests; // link it.
		node->count = node->prev->count + 1;
		s->tests = node; // set last test as head.
	}
	
	s->total++; // increment.
	return s->tests; // return head. 
}

// print a summary of the test's.
void summary(suit* s){
	int pass = 0, fail = 0;
	test *heads = s->tests;
	
	printf("*******TESTING********\n");
	while(heads) {
		if(heads->pass == true){
			pass++;
			printf("test %d\tOK \n", heads->count);
		}
		else if(heads->pass == false){
			fail++;
			printf("test %d\tFAILED \n", heads->count);
		}
		heads = heads->prev;
	}
	printf("******SUMMARY********\n");
	printf("pass: %d, fail: %d\n", pass, fail);
	printf("total: %d\n", s->total);
}
