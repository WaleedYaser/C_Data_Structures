#include "list.h"
#include "global.h"

#include <stdlib.h>
#include <string.h>

void _init_list(List *pl, int z)
{
	pl->size = 0;
	pl->t_size = z;
}

void _insert_list(int p, void *pe, List *pl)
{
	void *ptr = malloc(pl->t_size);
	memcpy(ptr, pe, pl->t_size);

	for (int i = pl->size -1; i >= p; --i)
		pl->entry[i+1] = pl->entry[i];

	pl->entry[p] = ptr;
	pl->size++;
}

void delete_list(int p, void *pe, List *pl)
{
	memcpy(pe, pl->entry[p], pl->t_size);
	free(pl->entry[p]);

	for (int i = p; i < pl->size - 1; ++i)
		pl->entry[i] = pl->entry[i+1];
	pl->size--;
}

void retrieve_list(int p, void *pe, List *pl)
{
	memcpy(pe, pl->entry[p], pl->t_size);
}

void _replace_list(int p, void *pe, List *pl)
{
	memcpy(pl->entry[p], pe, pl->t_size);
}

int list_empty(const List *pl)
{
	return !pl->size;
}

int list_full(const List *pl)
{
	return pl->size >= MAX_LIST;
}

int list_size(const List *pl)
{
	return pl->size;
}

void clear_list(List *pl)
{
	for (int i = 0; i < pl->size; ++i)
		free(pl->entry[i]);
	pl->size = 0;
}

void traverse_list(List *pl, void (*pf)(void *))
{
	for (int i = 0; i < pl->size; ++i)
		pf(pl->entry[i]);
}
