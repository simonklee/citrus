#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citrus.h"

// structs.
struct test {
	int pass;
	struct test *prev;
};

struct suit {
	int started;
	int total;
	struct test *tests;
};

// structures.
struct suit suit, *suit_ptr;

// functions.
static struct test *add_test();
static void init();

// Is it true?
int assert(int value) {
	return equals_t(true, value, true);
}

// does it match?
int equals(int expected, int actual) {
	equals_t(expected, actual, true);
}

// are you sure?
int equals_t(int expected, int actual, int truth) {
	struct test *t = add_test();
	if((expected == actual) == truth){
		t->pass = true;
		return true;
	} else {
		t->pass = false;
		return false;
	}		
}

// Print a summary of the text 
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

// Initilize our list and add a empty test case.
static void init() {
	suit_ptr = &suit;
	memset(suit_ptr, 0, sizeof *suit_ptr);
}

// Create a new node for our tests, add it to list.
static struct test *add_test() {
	struct test *node;
	
	node = (struct test*)malloc(sizeof(struct test));
	memset(node, 0, sizeof node);
	
	if(suit_ptr == NULL){
		init();
		suit_ptr->tests = node;
	} else {
		node->prev = suit_ptr->tests; // link it.
		suit_ptr->tests = node; // set last test as head.
	}
	suit_ptr->total++; // increment test cases.
	suit_ptr->tests = node; // the new node is set as head.
	
	return suit_ptr->tests; // return head. 
}


