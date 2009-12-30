
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citrus.h"

static void testAssert(Suit *s);
static void testEquals(Suit *s);
static void testCompare(Suit *s);

int main(int argc, char *argv[]) {
	Suit *sp;
	
	// allocate memory.
	sp = malloc(sizeof (Suit *));
	memset(sp, 0, sizeof *sp);

	// run tests.
	testAssert(sp);
	testEquals(sp);
	testCompare(sp);
	
	// view summary.
	Summary(sp);
	free(sp);
	return 0;
}

void testAssert(Suit *s) {
	Assert(s, 1);
}

void testEquals(Suit* s) {
	
	Equals(s, false, false);
	Equals(s, true, true);
	Equals(s, 100, 100);
	
	EqualsT(s, 5, 4, false);
	
	int a[2] = {5, 4};
	int b[2] = {5, 4};
	
	EqualsA(s, &b, &a, 2, sizeof(int), IntComp);
	
	char *txt1[] = {"Abc", "Def", "Ghi", "Jkl"};
	char *txt2[] = {"Abc", "Def", "Ghi", "Jkl"};
	
	EqualsA(s, &txt2, &txt1, 4, sizeof(char *), StringComp);
}

static void testCompare(Suit *s) {
	int int1, int2;
	char *txt1, *txt2;
	
	txt1 = malloc(3 + 1);
	txt2 = malloc(3 + 1);
	
	txt1 = "Abc";
	txt2 = "Abc";
	
	Assert(s, !StringComp(&txt1, &txt2));
	
	txt1 = "Abc";
	txt2 = "Cbc";
	
	Assert(s, StringComp(&txt1, &txt2) == -2); // A:65 - C:67 = -2
	
	int1 = 0;
	int2 = 0;
	
	Assert(s, IntComp(&int1, &int2) == 0);
	
	int1 = 0;
	int2 = 1;
	
	Assert(s, IntComp(&int1, &int2) == -1); // 0 - 1 = -1;
}
