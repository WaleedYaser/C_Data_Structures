#define MAXSTACK	100
#define STACK_ENTRY int

typedef struct _stack {
	int 			top;
	STACK_ENTRY		entry[MAXSTACK];
} Stack;

void init_stack(Stack *ps);

/* pre: the stack is initialized and not full */
void push(STACK_ENTRY e, Stack *ps);

/* pre: the stack is initialized and not empty */
void pop(STACK_ENTRY *pe, Stack *ps);

int stack_empty(const Stack *ps);

int stack_full(const Stack *ps);

/* pre: the stack is initialized and not empty */
void stack_top(STACK_ENTRY *pe, const Stack *ps);

/* pre: the stack is initialized */
int stack_size(const Stack *ps);

/* pre: the stack is initialized */
void clear_stack(Stack *ps);

/* pre: the stack is initialized */
void traverse_stack(Stack *ps, void (*pf)(STACK_ENTRY));
