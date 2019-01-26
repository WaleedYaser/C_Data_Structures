#include "global.h"

#ifdef LIMITED_MEMORY

typedef struct _stack {
	int		t_size;
	int 	top;
	void	*entry[MAX_STACK];
} Stack;

#else

typedef struct _Stack_Node {
	STACK_ENTRY		entry;
	struct _Stack_Node	*next;
} Stack_Node;

typedef struct _Stack {
	Stack_Node		*top;
	int				size;
} Stack;

#endif

void _init_stack(Stack *ps, int z);
#define init_stack(ps, type) _init_stack(ps, sizeof(type))

/* pre: the stack is initialized and not full */
void _push(void *pe, Stack *ps);
#define push(e, ps) _push(((void *) &e), ps)

/* pre: the stack is initialized and not empty */
void pop(void *pe, Stack *ps);

int stack_empty(const Stack *ps);

int stack_full(const Stack *ps);

/* pre: the stack is initialized and not empty */
void stack_top(void *pe, const Stack *ps);

/* pre: the stack is initialized */
int stack_size(const Stack *ps);

/* pre: the stack is initialized */
void clear_stack(Stack *ps);

/* pre: the stack is initialized */
void traverse_stack(Stack *ps, void (*pf)(void *));
