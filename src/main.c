#include "stack.h"
#include "queue.h"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
// red not yellow
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
// green not cyan
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define PRINT_TITLE(s) printf(ANSI_COLOR_BLUE s ANSI_COLOR_RESET)

void draw(int *e) {
	printf("drawing %d\n", *e);
}

void draw_stack(int *pe) {
	printf("drawing %d\n", *pe);
}

void test_stack(void);
void test_queue(void);
void test_list(void);

void test_tower_of_hanoi(void);

int main(void)
{
	test_stack();
	test_queue();
	test_list();

	test_tower_of_hanoi();

}

void test_stack(void)
{
#ifdef LIMITED_MEMORY
	PRINT_TITLE("===== stack with array test =====\n");
#else
	PRINT_TITLE("===== stack with linked list test =====\n");
#endif
	Stack s;
	int e;
	init_stack(&s, int);
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

	traverse_stack(&s, draw_stack);
	clear_stack(&s);
	printf("stack %s\n", stack_empty(&s) ? "cleared" : "not cleared");

	Stack s2;
	char c;
	init_stack(&s2, char);
	char *pw = "hello, world";
	for (int i = 0; pw[i] != '\0'; ++i)
		push(pw[i], &s2);
	while(!stack_empty(&s2)) {
		pop(&c, &s2);
		printf("%c\n", c);
	}
	clear_stack(&s2);
	printf("stack %s\n", stack_empty(&s2) ? "cleared" : "not cleared");
	PRINT_TITLE("=======================================\n");
}

void test_queue(void)
{
	PRINT_TITLE("===== queue test =====\n");
	Queue q;
	int e;
	init_queue(&q, int);
	for (int i = 0; i < 10; ++i) {
		e = i;
		if (!queue_full(&q))
			enqueue(e, &q);
		else {
			fprintf(stderr, "queue is full!\n");
			exit(1);
		}
	}

	for (int i = 0; i < 5; ++i) {
		dequeue(&e, &q);
		printf("%d\n", e);
	}

	for (int i = 0; i < 5; ++i) {
		e = i;
		if (!queue_full(&q))
			enqueue(e, &q);
		else {
			fprintf(stderr, "queue is full!\n");
			exit(1);
		}
	}

	while (!queue_empty(&q)) {
		dequeue(&e, &q);
		printf("%d\n", e);
	}

	for (int i = 0; i < 10; ++i) {
		e = i;
		if (!queue_full(&q))
			enqueue(e, &q);
		else {
			fprintf(stderr, "queue is full!");
			exit(1);
		}
	}

	traverse_queue(&q, draw);

	clear_queue(&q);
	printf("queue is %s\n", queue_empty(&q) ? "cleared" : "not cleared");

	Queue q2;
	init_queue(&q2, char);
	char *pw = "hello, world";
	char c;
	for (int i = 0; pw[i] != '\0'; ++i)
		enqueue(pw[i], &q2);
	while(!queue_empty(&q2)) {
		dequeue(&c, &q2);
		printf("%c\n", c);
	}

	clear_queue(&q2);
	printf("queue is %s\n", queue_empty(&q2) ? "cleared" : "not cleared");

	PRINT_TITLE("======================\n");
}

void test_list(void)
{
	PRINT_TITLE("===== list test =====\n");
	List l;
	int e;
	init_list(&l, int);
	for (int i = 0; i < 10; ++i) {
		e = i;
		if (i <= list_size(&l) && !list_full(&l))
			insert_list(i, e, &l);
		else {
			fprintf(stderr, "list wrong index!\n");
			exit(1);
		}
	}

	for (int i = 0; i < 5; ++i) {
		if (i < list_size(&l))
			retrieve_list(i, &e, &l);
		printf("%d\n", e);
	}

	for (int i = 0; i < 5; ++i) {
		e = i;
		if (i < list_size(&l) && !list_full(&l))
			insert_list(i, e, &l);
		else {
			fprintf(stderr, "list wrong index!\n");
			exit(1);
		}
	}

	while (!list_empty(&l)) {
		delete_list(0, &e, &l);
		printf("%d\n", e);
	}

	for (int i = 0; i < 10; ++i) {
		e = i;
		if (!list_full(&l))
			insert_list(0, e, &l);
		else {
			fprintf(stderr, "list is full!");
			exit(1);
		}
	}

	traverse_list(&l, draw);

	clear_list(&l);
	printf("list is %s\n", list_empty(&l) ? "cleared" : "not cleared");

	List l2;
	init_list(&l2, char);
	char *pw = "hello, world";
	char c;
	for (int i = 0; pw[i] != '\0'; ++i)
		insert_list(i, pw[i], &l2);
	while(!list_empty(&l2)) {
		delete_list(0, &c, &l2);
		printf("%c\n", c);
	}

	clear_list(&l2);
	printf("list is %s\n", list_empty(&l2) ? "cleared" : "not cleared");

	PRINT_TITLE("======================\n");
}


void test_tower_of_hanoi(void)
{
	void move_disks(int count, int start, int finish, int temp);

	PRINT_TITLE("===== tower of hanoi =====\n");
	move_disks(3, 1, 3, 2);
	PRINT_TITLE("==========================\n");
}

void move_disks(int count, int start, int finish, int temp)
{
	if (count > 0) {
		move_disks(count - 1, start, temp, finish);
		printf("move disk %d from %d to %d\n", count, start, finish);
		move_disks(count - 1, temp, finish, start);
	}
}
