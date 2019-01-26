#include "stack.h"
#include "global.h"

#ifdef LIMITED_MEMORY

void init_stack(Stack *ps)
{
	ps->top = 0;
}

void push(STACK_ENTRY e, Stack *ps)
{
	ps->entry[ps->top++] = e;
}
void pop(STACK_ENTRY *pe, Stack *ps)
{
	*pe = ps->entry[--ps->top];
}

int stack_empty(const Stack *ps)
{
	return ps->top <= 0;
}

int stack_full(const Stack *ps)
{
	return ps->top >= MAX_STACK;
}

void stack_top(STACK_ENTRY *pe, const Stack *ps)
{
	*pe = ps->entry[ps->top - 1];
}

int stack_size(const Stack *ps)
{
	return ps->top;
}

void clear_stack(Stack *ps)
{
	ps->top = 0;
}

void traverse_stack(Stack *ps, void (*pf)(STACK_ENTRY))
{
	for (int i = ps->top; i > 0; --i)
		pf(ps->entry[i - 1]);
}

#else

#include <stdlib.h>

void init_stack(Stack *ps)
{
	ps->top = NULL;
	ps->size = 0;
}

void push(STACK_ENTRY e, Stack *ps)
{
	Stack_Node *pn = (Stack_Node *) malloc(sizeof(Stack_Node));

	pn->entry = e;
	pn->next = ps->top;
	ps->top = pn;

	ps->size++;
}

void pop(STACK_ENTRY *pe, Stack *ps)
{
	*pe = ps->top->entry;

	Stack_Node *pn = ps->top;
	ps->top = pn->next;
	free(pn);

	ps->size--;
}

int stack_empty(const Stack *ps)
{
	return ps->top == NULL;
}

int stack_full(const Stack *ps)
{
	return 0;
}

void stack_top(STACK_ENTRY *pe, const Stack *ps)
{
	*pe = ps->top->entry;
}

int stack_size(const Stack *ps)
{
	return ps->size;
}

void clear_stack(Stack *ps)
{
	Stack_Node *pn;
	while (ps->top) {
		pn = ps->top;
		ps->top = pn->next;
		free(pn);
	}
	ps->size = 0;
}

void traverse_stack(Stack *ps, void (*pf)(STACK_ENTRY))
{
	Stack_Node *pn = ps->top;

	while (pn) {
		pf(pn->entry);
		pn = pn->next;
	}
}

#endif
