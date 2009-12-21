
#include <stdio.h>
#include "citrus.h"

int main(int argc, char *argv[]) {
	
	init();
	//printf("tests run: %d\n", suit->total);
	assert(1);
	assert(0);
	assert(0);
	//printf("tests run: %d\n", suit->total);
	summary();
	return 0;
}

/*int main(int argc, char *argv[]) {
	int i;
	struct test *head;

	for(i = 10; i >= 0; i--) {
		head = add_test(head);
		head->pass = i;
	}
	
	while(head) {
		printf("pass: %d\n", head->pass);
		head = head->next;
	}
	return 0;	
}*/
