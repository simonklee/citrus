#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <citrus.h>
#include "stack.h"

int main(int argc, char *argv[]) {
	int top, i;
	Stack stack;
	Suite *suite;
	
	// Allocate memory.
	suite = malloc(sizeof *suite);
	memset(suite, 0, sizeof *suite);
	StackNew(&stack, sizeof(int));
	
	// Test Push, Pop.
	top = 99;
	StackPush(&stack, &top);
	StackPop(&stack, &i);
	Equals(suite, i, 99);
	
	// Test Pushing 99 times.
	top = 99;
	for (i = 0; i < 100; i++) {
		StackPush(&stack, &i);
		if (i == top) {
			StackPop(&stack, &top);
		}
	}
	Equals(suite, top, 99);
	
	// Write summary.
	Summary(suite);
	free(suite);
	return 0;
}
