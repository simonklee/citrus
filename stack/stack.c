#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "stack.h"

static void stackGrow(Stack *s);

void StackNew(Stack *s, int elemSize) {
	assert(elemSize > 0);
	s->elemSize = elemSize;
	s->stackLenght = 0;
	s->allocLenght = 4;
	s->elems = malloc(4 * elemSize);
	assert(s->elems != NULL);
}

void StackFree(Stack *s) {
	free(s->elems);
}

void StackPush(Stack *s, void *elemAddr) {
	if (s->stackLenght == s->allocLenght) {
		stackGrow(s);
	}
	void *target = (char *) s->elems + s->stackLenght * s->elemSize;
	memcpy(target, elemAddr, s->elemSize);
	s->stackLenght++;
}
void StackPop(Stack *s, void *elemAddr) {
	s->stackLenght--;
	void *source = (char *) s->elems + s->stackLenght * s->elemSize;
	memcpy(elemAddr, source, s->elemSize);
}

static void stackGrow(Stack *s) {
	s->allocLenght *= 2;
	s->elems = realloc(s->elems, s->allocLenght * s->elemSize);
	assert(s->elems != NULL);
}
