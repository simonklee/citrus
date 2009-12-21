#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citrus.h"

// structs.
/*struct test {
	int pass;
	struct test *prev;
};
struct suit {
	int started;
	int total;
	struct test *tests;
};*/
//struct suit suit, *suit_ptr;

// functions.
static test *add_test(suit *s);

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
	test *t = add_test(s);
	if((expected == actual) == truth){
		t->pass = true;
		return true;
	} else {
		t->pass = false;
		return false;
	}		
}

// do these characters match?
int equals_a(suit *s, void *key, void *base, int n, int elm_size) {
	int i, j;
	test *t = add_test(s);
		
	for(i = 0; i < n; i++) {
		void *key_addr = (char *)key + i * elm_size;
		void *elm_addr = (char *)base + i * elm_size;
		if(memcmp(key_addr, elm_addr, elm_size) != 0){
			t->pass = false;
			return false;
		}
	}
	t->pass = true;
	return true;
}

// Print a summary of the text 
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

// Initilize our list and add a empty test case.
void init(suit *s) {
	memset(s, 0, sizeof *s);
}

// Create a new node for our tests, add it to list.
static test *add_test(suit *s) {
	test t, *node;
	node = &t;
	//node = (struct test*)malloc(sizeof(*node));
	
	memset(node, 0, sizeof node);
	
	if(s->tests == 0){
		//init();
		s->tests = node;
	} else {
		node->prev = s->tests; // link it.
		s->tests = node; // set last test as head.
	}
	s->total++; // increment test cases.
	s->tests = node; // the new node is set as head.
	
	return s->tests; // return head. 
}


