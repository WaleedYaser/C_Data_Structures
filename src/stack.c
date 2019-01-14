#include "stack.h"

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
	return ps->top >= MAXSTACK;
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
