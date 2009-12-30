#ifndef _CITRUS_H_
#define _CITRUS_H_

#define true 1
#define false 0

// structures.
typedef struct Test {
	struct Test *prev;
	int pass;
	int count;
} Test;

typedef struct {
	struct Test *tests;
	int total;
} Suit;

// functions.
int Assert(Suit *s, int value);
int Equals(Suit *s, int expected, int actual);
int EqualsT(Suit *s, int expected, int actual, int truth);
int EqualsA(Suit *s, void *a, void *b, int n, int elmsize, 
			int (*callback)(void *, void*));
void Summary(Suit *s);	

// functions, helpers.	
int IntComp(void *a, void *b);
int StringComp(void *a, void *b);

#endif
