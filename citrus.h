
#ifndef _CITRUS_H_
#define _CITRUS_H_

#define true 1
#define false 0

// functions.
int assert(int value);
int equals(int expected, int actual);
int equals_t(int expected, int actual, int truth);
int equals_a(void *key, void *base, int n, int elm_size); 
void summary();
#endif
