
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citrus.h"

void testassert(suit *s);
void testequals(suit *s);

int main(int argc, char *argv[]) {
	suit *sp;
	
	// allocate memory
	sp = malloc(sizeof *sp);
	memset(sp, 0, sizeof *sp);
	
	// run tests.
	testassert(sp);
	testequals(sp);
	
	// view summary.
	summary(sp);
	
	return 0;
}

void testassert(suit *s) {
	assert(s, 1);
}

void testequals(suit* s) {
	
	equals(s, false, false);
	equals(s, true, true);
	equals(s, 100, 100);
	
	equals_t(s, false, true, false);
	
	int a[2] = {5, 4};
	int b[2] = {5, 4};
	
	equals_a(s, &b, &a, 2, sizeof(int), integercmp);
	
	char *txt1[] = {"Abc", "Def", "Ghi", "Jkl"};
	char *txt2[] = {"Abc", "Def", "Ghi", "Jkl"};
	
	equals_a(s, &txt2, txt1, 4, sizeof(char *), stringcmp);
}