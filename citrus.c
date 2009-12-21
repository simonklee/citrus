#define true 1
#define false 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citrus.h"

// structures.
struct suit suit, *suit_ptr;

// func proto-types.
struct test *add_test();

// Initilize our list and add a empty test case.
void init() {
	suit_ptr = &suit;
	memset(suit_ptr, 0, sizeof *suit_ptr);
	//suit.tests = add_test();
}

// Is it true?
void assert(int value) {
	struct test *t = add_test();
	if(value == true){
		t->pass = true;
	}
	else {
		t->pass = false;
	}
}

// Create a new node for our tests, add it to list.
struct test *add_test() {
	struct test *node;
	
	node = (struct test*)malloc(sizeof(struct test));
	memset(node, 0, sizeof node);
	
	if(suit_ptr->tests == 0){
		suit_ptr->tests = node;
	} else {
		node->prev = suit_ptr->tests; // link it.
		suit_ptr->tests = node; // set last test as head.
	}
	suit_ptr->total++; // increment test cases.
	suit_ptr->tests = node; // the new node is set as head.
	
	return suit_ptr->tests; // return head. 
}

void summary(){
	int pass = 0, fail = 0;
	struct test *heads = suit_ptr->tests;
	printf("*********************\n");
	while(heads) {
		if(heads->pass == true)
			pass++;
		else if(heads->pass == false)
			fail++;
		heads = heads->prev;
	}
	printf("pass: %d, fail: %d\n", pass, fail);
	printf("total: %d\n\n", suit_ptr->total);
}
