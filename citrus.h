
#ifndef _CITRUS_H_
#define _CITRUS_H_

// structs.
struct test {
	int pass;
	struct test *prev;
};

struct suit {
	int total;
	struct test *tests;
};

// functions.
void init();
void assert(int value);

#endif
