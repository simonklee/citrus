
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

typedef struct {
	int *yay;
} stack;

// functions.
int assert(suit *s, int value);
int equals(suit *s, int expected, int actual);
int equals_t(suit *s, int expected, int actual, int truth);
int equals_a(suit *s, void *key, void *base, int n, int elm_size); 
void summary(suit *s);
void init(suit* s);
#endif
