
#include <stdio.h>
#include "citrus.h"

void test_assert();
void test_equals();

int main(int argc, char *argv[]) {
	init();	
	test_assert();
	test_equals();
	summary();
	
	return 0;
}

void test_assert() {
	assert(1);
}

void test_equals() {
	equals(false, false);
	equals(true, true);
	equals_t(false, true, false);
}
