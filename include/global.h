#ifndef GLOBAL_H
#define GLOBAL_H

#define LIMITED_MEMORY

typedef struct _Element_Type {
	int year;
	int tmp;
	float age;
} Element_Type;

#define MAXELEMENTS 100

typedef int STACK_ENTRY;
#define MAX_STACK MAXELEMENTS

typedef int QUEUE_ENTRY;
#define MAX_QUEUE MAXELEMENTS

#endif
