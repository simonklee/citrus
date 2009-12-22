
#ifndef _CITRUS_H_
#define _CITRUS_H_

#define true 1
#define false 0

// structures.
typedef struct prev_test {
	int pass;
	void fault;
	struct prev_test *prev;
} test;

typedef struct {
	int started;
	int total;
	struct prev_test *tests;
} suit;

// functions.
int assert(suit *s, int value);
int equals(suit *s, int expected, int actual);
int equals_t(suit *s, int expected, int actual, int truth);
int equals_a(suit *s, void *a, void *b, int n, int elmsize, 
	int (*callback)(void *, void*), int line);
void summary(suit *s);	

// functions, helpers.	
int integercmp(void *a, void *b);
int stringcmp(void *a, void *b);

#endif