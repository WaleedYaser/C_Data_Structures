#include <stdio.h>
#include <stdlib.h>

#define STACK_ENTRY int
#include "stack.h"

void draw(STACK_ENTRY e) {
	printf("drawing \"%d\"...\n", e);
}

int main()
{
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
}
