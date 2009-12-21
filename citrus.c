#define true 1
#define false 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citrus.h"

//#typedef struct suit suit;

// Test structure.
struct test *add_test();
struct suit suit, *suit_ptr;

// Initilize our list and add a empty test case.
void init() {
	struct test *nod;
	suit_ptr = &suit;
	suit.total = -1;
	suit.tests = add_test(nod);
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
	struct test *node, *head;
	node = (struct test*)malloc(sizeof(struct test));
	memset(node, 0, sizeof node);
	
	head = suit_ptr->tests; // set last test as head.
	suit_ptr->total++; // increment test cases.
	node->next = head;
	
	return node;
}

void summary(){
	printf("*********************\n");
	printf("total:\t%d\n", 
}
