
typedef struct {
	void *elems;
	int lenght;
	
	int elem_size;
	int alloc_lenght;
} stack; 

void stacknew(stack *s, int elem_size);
void stackfree(stack *s);
void stackpush(stack *s, void *elem_addr);
void stackpop(stack *s, void *elem_addr);
