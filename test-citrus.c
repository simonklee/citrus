#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <citrus.h>

static void testAssert(Suite *s);
static void testEquals(Suite *s);
static void testCompare(Suite *s);

int main(int argc, char *argv[]) {
	Suite *suite;
	
	// allocate memory.
	suite = malloc(sizeof (Suite *));
	memset(suite, 0, sizeof *suite);

	// run tests.
	testAssert(suite);
	testEquals(suite);
	testCompare(sp);
	
	// view summary.
	Summary(suite);
	free(suite);
	return 0;
}

void testAssert(Suite *s) {
	Assert(s, 1);
}

void testEquals(Suite* s) {
	
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

static void testCompare(Suite *s) {
	int int1, int2;
	char *txt1, *txt2;
	
	txt1 = malloc(3 + 1);
	txt2 = malloc(3 + 1);
	
	txt1 = "Abc";
	txt2 = "Abc";
	
	Assert(s, !StringComp(&txt1, &txt2));
	
	txt1 = "Abc";
	txt2 = "Cbc";

	Assert(s, StringComp(&txt1, &txt2) == -1); // less then equal to = -1
	
	int1 = 0;
	int2 = 0;
	
	Assert(s, IntComp(&int1, &int2) == 0);
	
	int1 = 0;
	int2 = 1;
	
	Assert(s, IntComp(&int1, &int2) == -1); // 0 - 1 = -1;
}
