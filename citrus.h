
#ifndef _CITRUS_H_
#define _CITRUS_H_

#define true 1
#define false 0

// functions.
void init();
int assert(int value);
int equals(int expected, int actual);
int equals_t(int expected, int actual, int truth);
void summary();
#endif
