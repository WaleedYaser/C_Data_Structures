#include "global.h"

typedef struct _List {
	void *entry[MAX_LIST];
	int size;
	int t_size;
} List;

void _init_list(List *pl, int z);
#define init_list(pl, type) _init_list(pl, sizeof(type))

void _insert_list(int p, void *pe, List *pl);
#define insert_list(p, e, pl) _insert_list(p, ((void *) &e), pl)

void delete_list(int p, void *pe, List *pl);

void retrieve_list(int p, void *pe, List *pl);

void _replace_list(int p, void *pe, List *pl);
#define replace_list(p, e, pl) _replace_list(p, ((void *) &e), pl)

int list_empty(const List *pl);

int list_full(const List *pl);

int list_size(const List *pl);

void clear_list(List *pl);

void traverse_list(List *pl, void (*pf)(void *));
