#define LSTACK_ENTRY int

typedef struct _Stack_Node {
	LSTACK_ENTRY		entry;
	struct _Stack_Node	*next;
} Stack_Node;

typedef struct _LStack {
	Stack_Node		*top;
	int				size;
} LStack;

void init_lstack(LStack *ls);

/* pre: lstack is initialized */
void ls_push(LSTACK_ENTRY e, LStack *pls); 

/* pre: lstack is initialized and not empty */
void ls_pop(LSTACK_ENTRY *pe, LStack *pls);

/* pre: lstack is initialized */
int lstack_empty(const LStack *pls);

int lstack_full(const LStack *pls);

/* pre: lstack is initialized and not empty */
void lstack_top(LSTACK_ENTRY *pe, const LStack *pls);

/* pre: lstack is initialized */
int lstack_size(const LStack *ps);

/* pre: lstack is initialized */
void clear_lstack(LStack *pls);

/* pre: lstack is initialized */
void traverse_lstack(LStack *pls, void (*pf)(LSTACK_ENTRY));
