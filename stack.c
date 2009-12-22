#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include <string.h>
static void stackgrow(stack *s);

void stacknew(stack *s, int elem_size) {
	assert(elem_size > 0);
	s->elem_size = elem_size;
	s->lenght = 0;
	s->alloc_lenght = 4;
	s->elems = malloc(4 * elem_size);
	assert(s->elems != NULL);
}

void stackfree(stack *s) {
	free(s->elems);
}

void stackpush(stack *s, void *elem_addr){
	if(s->lenght == s->alloc_lenght) {
		stackgrow(s);
	}
	void *target = (char *) s->elems + s->lenght * s->alloc_lenght;
	memcpy(target, elem_addr, s->elem_size);
	s->lenght++;
}
void stackpop(stack *s, void *elem_addr) {
	s->lenght--;
	void *source = (char *) s->elems + (s->lenght) * s->elem_size;
	memcpy(elem_addr, source, s->elem_size);
}

static void stackgrow(stack *s) {
	s->alloc_lenght *=2;
	s->elems = realloc(s->elems, s->alloc_lenght * s->elem_size);
	assert(s->elems != NULL);
}

int main(int argc, char *argv[]) {
	int top;
	stack s;
	stacknew(&s, sizeof(int));
	stackpop(&s, &top);
	return 0;
}