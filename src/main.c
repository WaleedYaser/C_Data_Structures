#include "stack.h"
#include "linked_stack.h"

#include <stdio.h>
#include <stdlib.h>


void draw(STACK_ENTRY e) {
	printf("drawing \"%d\"...\n", e);
}

void test_stack(void);
void test_lstack(void);

int main()
{
	test_stack();
	test_lstack();
}

void test_stack(void)
{
	printf("===== stack test =====\n");
	Stack s;
	STACK_ENTRY e;
	init_stack(&s);
	for (int i = 0; i < 5; ++i) {
		e = i;
		if (!stack_full(&s))
			push(e, &s);
		else {
			fprintf(stderr, "stack is full!");
			exit(1);
		}
	}

	while (!stack_empty(&s)) {
		pop(&e, &s);
		printf("%d\n", e);
	}

	for (int i = 0; i < 10; ++i) {
		e = i;
		if (!stack_full(&s))
			push(e, &s);
		else {
			fprintf(stderr, "stack is full!");
			exit(1);
		}
	}
	
	if (!stack_empty(&s)) {
		stack_top(&e, &s);
		printf("stack top is: %d\n", e);
	}

	traverse_stack(&s, draw);
	clear_stack(&s);
	printf("stack %s\n", stack_empty(&s) ? "cleared" : "not cleared");
	printf("======================\n");
}

void test_lstack(void)
{
	printf("===== linked stack test =====\n");
	LStack ls;
	LSTACK_ENTRY e;
	init_lstack(&ls);
	for (int i = 0; i < 5; ++i) {
		e = i;
		if (!lstack_full(&ls))
			ls_push(e, &ls);
		else {
			fprintf(stderr, "stack is full!");
			exit(1);
		}
	}

	while (!lstack_empty(&ls)) {
		ls_pop(&e, &ls);
		printf("%d\n", e);
	}

	for (int i = 0; i < 10; ++i) {
		e = i;
		if (!lstack_full(&ls))
			ls_push(e, &ls);
		else {
			fprintf(stderr, "stack is full!");
			exit(1);
		}
	}
	
	if (!lstack_empty(&ls)) {
		lstack_top(&e, &ls);
		printf("stack top is: %d\n", e);
	}

	traverse_lstack(&ls, draw);

	clear_lstack(&ls);
	printf("linked stack %s\n", lstack_empty(&ls) ? "cleared" : "not cleared");
	printf("=============================\n");
}
