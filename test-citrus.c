
#include <stdio.h>
#include "citrus.h"

int main(int argc, char *argv[]) {
	init();
	assert(1);
	assert(0);
	assert(1);

	summary();
	return 0;
}
