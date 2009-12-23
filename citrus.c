#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citrus.h"

// (member) functions.
static Test *addTest(Suit *s);

// Is it true?
int Assert(Suit *s, int value) {
	return EqualsT(s, true, value, true);
}

// Does it match?
int Equals(Suit *s, int expected, int actual) {
	return EqualsT(s, expected, actual, true);
}

// Does it match, are you sure?
int EqualsT(Suit *s, int expected, int actual, int truth) {
	Test *t = addTest(s);
	if ((expected == actual) == truth) {
		t->pass = true;
		return true;
	} else {
		t->pass = false;
		return false;
	}		
}

// Match a generic set of datatype's stored in two arrays.
// use functions(void *, void *) as comparators. 
int EqualsA(Suit *s, void *a, void *b, int n, int elmsize, 
	int (*callback)(void *, void*)) {
	
	int i, err;
	Test *t = addTest(s);
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

// How to compare integers.
int IntComp(void *a, void *b) {
	int *ap = a;
	int *bp = b;
	
	return *ap - *bp;
}

// How to compare strings.
int StringComp(void *a, void *b) {
	char *str1 = *(char **)a;
	char *str2 = *(char **)b;
	
	return strcmp(str1, str2);
}

// Create a new node for our tests, add it to list.
static Test *addTest(Suit *s) {
	int i;
	Test *node;
	node = malloc(sizeof *node);
	memset(node, 0, sizeof *node);
		
	// No need to link it if it is our first time.
	if (s->tests == 0) {
		s->tests = node;		
		node->count++;
	} else {
		node->prev = s->tests; // Link it.
		node->count = node->prev->count + 1;
		s->tests = node; // Set last test as head.
	}
	
	s->total++; // Increment.
	return s->tests; // Return head. 
}

// Print a summary of the test's.
void Summary(Suit* s) {
	int pass = 0, fail = 0;
	Test *heads = s->tests;
	
	printf("*******TESTING********\n");
	while (heads) {
		if (heads->pass == true) {
			pass++;
			printf("test %d\tOK \n", heads->count);
		}
		else if (heads->pass == false) {
			fail++;
			printf("test %d\tFAILED \n", heads->count);
		}
		heads = heads->prev;
	}
	printf("******SUMMARY********\n");
	printf("pass: %d, fail: %d\n", pass, fail);
	printf("total: %d\n", s->total);
}
