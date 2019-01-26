#include "stack.h"
#include "global.h"

#include <stdlib.h>
#include <string.h>

#ifdef LIMITED_MEMORY

void _init_stack(Stack *ps, int z)
{
	ps->top = 0;
	ps->t_size = z;
}

void _push(void *pe, Stack *ps)
{
	void *ptr = malloc(ps->t_size);
	memcpy(ptr, pe, ps->t_size);
	ps->entry[ps->top++] = ptr;
}

void pop(void *pe, Stack *ps)
{
	memcpy(pe, ps->entry[--ps->top], ps->t_size);
	free(ps->entry[ps->top]);
}

int stack_empty(const Stack *ps)
{
	return ps->top <= 0;
}

int stack_full(const Stack *ps)
{
	return ps->top >= MAX_STACK;
}

void stack_top(void *pe, const Stack *ps)
{
	memcpy(pe, ps->entry[ps->top - 1], ps->t_size);
}

int stack_size(const Stack *ps)
{
	return ps->top;
}

void clear_stack(Stack *ps)
{
	while (ps->top >= 0)
		free(ps->entry[ps->top--]);
	ps->top = 0;
}

void traverse_stack(Stack *ps, void (*pf)(void *))
{
	for (int i = ps->top; i > 0; --i)
		pf(ps->entry[i - 1]);
}

#else

void _init_stack(Stack *ps, int z)
{
	ps->top = NULL;
	ps->size = 0;
	ps->t_size = z;
}

void _push(void *pe, Stack *ps)
{
	Stack_Node *pn = (Stack_Node *) malloc(sizeof(Stack_Node));

	void *ptr = malloc(ps->t_size);
	memcpy(ptr, pe, ps->t_size);

	pn->entry = ptr;
	pn->next = ps->top;
	ps->top = pn;

	ps->size++;
}

void pop(void *pe, Stack *ps)
{
	memcpy(pe, ps->top->entry, ps->t_size);

	Stack_Node *pn = ps->top;
	ps->top = pn->next;
	free(pn->entry);
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

void stack_top(void *pe, const Stack *ps)
{
	memcpy(pe, ps->top->entry, ps->t_size);
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
		free(pn->entry);
		free(pn);
	}
	ps->size = 0;
}

void traverse_stack(Stack *ps, void (*pf)(void *))
{
	Stack_Node *pn = ps->top;

	while (pn) {
		pf(pn->entry);
		pn = pn->next;
	}
}

#endif
