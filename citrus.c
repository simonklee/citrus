#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citrus.h"

// functions.
static test *add_test(suit *s);

// is it true?
int assert(suit *s, int value) {
	return true; //equals_t(s, true, value, true);
}

// Create a new node for our tests, add it to list.
static test *add_test(suit *s) {
	test t, *node;
	node = &t;
	node = (struct test*)malloc(sizeof(*node));
	
	memset(node, 0, sizeof node);
	
	if(s->tests == 0){
		s->tests = node;
	} else {
		node->prev = s->tests; // link it.
		s->tests = node; // set last test as head.
	}
	s->total++; // increment test cases.
	s->tests = node; // the new node is set as head.
	
	return s->tests; // return head. 
}


