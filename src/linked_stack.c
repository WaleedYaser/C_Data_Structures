#include "linked_stack.h"

#include <stdlib.h>

void init_lstack(LStack *pls)
{
	pls->top = NULL;
	pls->size = 0;
}

void ls_push(LSTACK_ENTRY e, LStack *pls)
{
	Stack_Node *pn = (Stack_Node *) malloc(sizeof(Stack_Node));

	pn->entry = e;
	pn->next = pls->top;
	pls->top = pn;

	pls->size++;
}

void ls_pop(LSTACK_ENTRY *pe, LStack *pls)
{
	*pe = pls->top->entry;

	Stack_Node *pn = pls->top;
	pls->top = pn->next;
	free(pn);

	pls->size--;
}

int lstack_empty(const LStack *pls)
{
	return pls->top == NULL;
}

int lstack_full(const LStack *pls)
{
	return 0;
}

void lstack_top(LSTACK_ENTRY *pe, const LStack *pls)
{
	*pe = pls->top->entry;
}

int lstack_size(const LStack *pls)
{
	return pls->size;
}

void clear_lstack(LStack *pls)
{
	Stack_Node *pn;
	while (pls->top) {
		pn = pls->top;
		pls->top = pn->next;
		free(pn);
	}
	pls->size = 0;
}

void traverse_lstack(LStack *pls, void (*pf)(LSTACK_ENTRY))
{
	Stack_Node *pn = pls->top;

	while (pn) {
		pf(pn->entry);
		pn = pn->next;
	}
}
