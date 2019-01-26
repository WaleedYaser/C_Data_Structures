#include "global.h"
#include "queue.h"

#include <stdlib.h>
#include <string.h>

#ifdef LIMITED_MEMORY

void _init_queue(Queue *pq, int z)
{
	pq->front = 0;
	pq->rear  = -1;
	pq->size  = 0;
	pq->t_size = z;
}

void _enqueue(void *pe, Queue *pq)
{
	void *ptr = malloc(pq->t_size);
	memcpy(ptr, pe, pq->t_size);

	pq->rear = (pq->rear + 1) % MAX_QUEUE;
	pq->entry[pq->rear] = ptr;
	pq->size++;
}

void dequeue(void *pe, Queue *pq)
{
	memcpy(pe, pq->entry[pq->front], pq->t_size);
	free(pq->entry[pq->front]);

	pq->front = (pq->front + 1) % MAX_QUEUE;
	pq->size--;
}

int queue_empty(const Queue *pq)
{
	return pq->size == 0;
}

int queue_full(const Queue *pq)
{
	return pq->size >= MAX_QUEUE;
}

int queue_size(const Queue *pq)
{
	return pq->size;
}

void clear_queue(Queue *pq)
{
	for (int i = 0; i < pq->size; ++i)
		free(pq->entry[(pq->front + i) % MAX_QUEUE]);

	pq->front = 0;
	pq->rear  = -1;
	pq->size  = 0;
}

void traverse_queue(Queue *pq, void (*pf)(void *))
{
	for (int i = 0; i < pq->size; ++i) {
		pf(pq->entry[(pq->front + i) % MAX_QUEUE]);
	}
}

#else

void _init_queue(Queue *pq, int z)
{
	pq->front  = NULL;
	pq->rear   = NULL;
	pq->size   = 0;
	pq->t_size = z;
}

void _enqueue(void *pe, Queue *pq)
{
	QNode *pn = (QNode *) malloc(sizeof(QNode));

	void *ptr = malloc(pq->t_size);
	memcpy(ptr, pe, pq->t_size);

	pn->entry = ptr;
	pn->next  = NULL;

	if (pq->rear)
		pq->rear->next = pn;
	else
		pq->front = pn;

	pq->rear = pn;
	pq->size++;
}

void dequeue(void *pe, Queue *pq)
{
	memcpy(pe, pq->front->entry, pq->t_size);
	pq->size--;

	QNode *pn = pq->front;
	pq->front = pq->front->next;

	free(pn->entry);
	free(pn);

	if (!pq->front)
		pq->rear = NULL;
}

int queue_empty(const Queue *pq)
{
	return !pq->size;
}

int queue_full(const Queue *pq)
{
	return 0;
}

int queue_size(const Queue *pq)
{
	return pq->size;
}

void clear_queue(Queue *pq)
{
	while (pq->front) {
		pq->rear = pq->front->next;
		free(pq->front->entry);
		free(pq->front);
		pq->front = pq->rear;
	}
	pq->size = 0;
}

void traverse_queue(Queue *pq, void (*pf)(void *))
{
	QNode *pn = pq->front;
	while (pn) {
		pf(pn->entry);
		pn = pn->next;
	}
}

#endif
