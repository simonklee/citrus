
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citrus.h"

static void testAssert(Suit *s);
static void testEquals(Suit *s);
static void testCompare(Suit *s);

int main(int argc, char *argv[]) {
	Suit *sp, sp_;
	
	// allocate memory.
	sp = malloc(sizeof (Suit *));
	//memset(sp, 0, sizeof *sp);
	
	sp_.total = 0;
	//sp=&sp_;
	
	printf("sizeof(int) %d\n", sizeof(int));
	printf("sizeof(sp_.total) %d\n", sizeof(sp_.total));
	printf("sizeof(Test) %d\n", sizeof(Test *));	
	printf("sizeof(Suit) %d\n", sizeof(Suit));
	printf("sizeof(Suit *) %d\n", sizeof(Suit *));
	printf("sizeof(sp->total) %d\n", sizeof(sp->total));	
	printf("sizeof(&sp->total) %d\n", sizeof(&sp->total));	
	printf("sizeof(sp->tests) %d\n", sizeof(sp->tests));	
	printf("sizeof(&sp->tests) %d\n", sizeof(&sp->tests));	
	/*printf("&sp_\n");
	printf("%p\n", &sp_);
	printf("%p\n", &sp_.total);
	printf("%p\n", &sp_.tests);*/
	printf("*sp\n");
	printf("%p\n", sp);
	printf("%p\n", &sp->total);
	printf("%p\n", &sp->tests);
//	Assert(sp, 1);
	
//	printf("%p\n", &sp->tests->pass);
	// run tests.
	//testAssert(sp);
	//testEquals(sp);
	//testCompare(sp);
	
	// view summary.
	//Summary(sp);
//	free(sp);
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
	
	//printf(*txt1);
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
