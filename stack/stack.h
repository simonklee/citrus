#ifndef _STACK_H_
#define _STACK_H_

typedef struct {
	void *elems;
	int stackLenght;
	int allocLenght;
	int elemSize;
} Stack; 

void StackNew(Stack *s, int elemSize);
void StackFree(Stack *s);
void StackPush(Stack *s, void *elemAddr);
void StackPop(Stack *s, void *elemAddr);

#endif