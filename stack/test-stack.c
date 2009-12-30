#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "../citrus.h"

int main(int argc, char *argv[]) {
	int top, i, *ip;
	Stack stack;
	Suit *suit;
	
	// Allocate memory.
	suit = malloc(sizeof *suit);
	memset(suit, 0, sizeof *suit);
	StackNew(&stack, sizeof(int));
	
	// Test Push, Pop.
	top = 99;
	StackPush(&stack, &top);
	StackPop(&stack, &i);
	Equals(suit, i, 99);
	
	// Test Pushing 99 times.
	top = 99;
	for (i = 0; i < 100; i++) {
		StackPush(&stack, &i);
		if (i == top) {
			StackPop(&stack, &top);
		}
	}
	Equals(suit, top, 99);
	
	// Write summary.
	Summary(suit);
	free(suit);
	return 0;
}
