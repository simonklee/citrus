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
} Suite;

// functions.
int Assert(Suite *s, int value);
int Equals(Suite *s, int expected, int actual);
int EqualsT(Suite *s, int expected, int actual, int truth);
int EqualsA(Suite *s, void *a, void *b, int n, int elmsize, 
			int (*callback)(void *, void*));
void Summary(Suite *s);	

// functions, helpers.	
int IntComp(void *a, void *b);
int StringComp(void *a, void *b);

#endif
