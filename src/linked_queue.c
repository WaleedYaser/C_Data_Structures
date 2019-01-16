#include "linked_queue.h"

#include <stdlib.h>

void init_lqueue(LQueue *plq)
{
	plq->front = NULL;
	plq->rear  = NULL;
	plq->size  = 0;
}

void lenqueue(LQUEUE_ENTRY e, LQueue *plq)
{
	QNode *pn = (QNode *) malloc(sizeof(QNode));
	pn->entry = e;
	pn->next  = NULL;

	if (plq->rear)
		plq->rear->next = pn;
	else
		plq->front = pn;

	plq->rear = pn;
	plq->size++;
}

void ldequeue(LQUEUE_ENTRY *pe, LQueue *plq)
{
	*pe = plq->front->entry;
	plq->size--;

	QNode *pq = plq->front;
	plq->front = plq->front->next;
	free(pq);

	if (!plq->front)
		plq->rear = NULL;
}

int lqueue_empty(const LQueue *plq)
{
	return !plq->size;
}

int lqueue_full(const LQueue *plq)
{
	return 0;
}

int lqueue_size(const LQueue *plq)
{
	return plq->size;
}

void clear_lqueue(LQueue *plq)
{
	while (plq->front) {
		plq->rear = plq->front->next;
		free(plq->front);
		plq->front = plq->rear;
	}
	plq->size = 0;
}

void traverse_lqueue(LQueue *plq, void (*pf)(LQUEUE_ENTRY))
{
	QNode *pn = plq->front;
	while (pn) {
		pf(pn->entry);
		pn = pn->next;
	}
}
