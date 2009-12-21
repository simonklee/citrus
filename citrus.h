
#ifndef _CITRUS_H_
#define _CITRUS_H_

#define true 1
#define false 0

typedef struct {
	int pass;
	struct test *prev;
} test;

typedef struct {
	int started;
	int total;
	struct test *tests;
} suit;


// functions.
int assert(suit *s, int value);
#endif
