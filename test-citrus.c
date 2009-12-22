
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citrus.h"

void testassert(suit *s);
void testequals(suit *s);
void testcompare(suit *s);

int main(int argc, char *argv[]) {
	suit *sp;
	
	// allocate memory.
	sp = malloc(sizeof *sp);
	memset(sp, 0, sizeof *sp);
	
	// run tests.
	testassert(sp);
	testequals(sp);
	testcompare(sp);
	
	// view summary.
	summary(sp);
	free(sp);
	return 0;
}

void testassert(suit *s) {
	assert(s, 1);
}

void testequals(suit* s) {
	
	equals(s, false, false);
	equals(s, true, true);
	equals(s, 100, 100);
	
	equals_t(s, 5, 4, false);
	
	int a[2] = {5, 4};
	int b[2] = {5, 4};
	
	equals_a(s, &b, &a, 2, sizeof(int), integercmp, __LINE__);
	
	char *txt1[] = {"Abc", "Def", "Ghi", "Jkl"};
	char *txt2[] = {"bbc", "Def", "Ghi", "Jkl"};
	
	equals_a(s, &txt2, &txt1, 4, sizeof(char *), stringcmp, __LINE__);
}

void testcompare(suit *s) {
	int int1, int2;
	char *txt1, *txt2;
	
	txt1 = malloc(3 + 1);
	txt2 = malloc(3 + 1);
	
	txt1 = "Abc";
	txt2 = "Abc";
	
	//printf(*txt1);
	assert(s, stringcmp(&txt1, &txt2) == 0);
	
	txt1 = "Abc";
	txt2 = "Cbc";
	
	assert(s, stringcmp(&txt1, &txt2) == -2); // A:65 - C:67 = -2
	
	int1 = 0;
	int2 = 0;
	
	assert(s, integercmp(&int1, &int2) == 0);
	
	int1 = 0;
	int2 = 1;
	
	assert(s, integercmp(&int1, &int2) == -1); // 0 - 1 = -1;
}
