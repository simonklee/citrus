
#include <stdio.h>
#include <string.h>
#include "citrus.h"

void testassert(suit *s);

int main(int argc, char *argv[]) {
	suit s, *sp = &s;
	memset(sp, 0, sizeof *sp);
	testassert(sp);
	
	return 0;
}

void testassert(suit *s) {
	assert(s, 1);
}