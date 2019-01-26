#include "global.h"
#include "queue.h"

#ifdef LIMITED_MEMORY

void init_queue(Queue *pq)
{
	pq->front = 0;
	pq->rear  = -1;
	pq->size  = 0;
}

void enqueue(QUEUE_ENTRY e, Queue *pq)
{
	pq->rear = (pq->rear + 1) % MAX_QUEUE;
	pq->entry[pq->rear] = e;
	pq->size++;
}

void dequeue(QUEUE_ENTRY *pe, Queue *pq)
{
	*pe = pq->entry[pq->front];
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
	pq->front = 0;
	pq->rear  = -1;
	pq->size  = 0;
}

void traverse_queue(Queue *pq, void (*pf)(QUEUE_ENTRY))
{
	for (int i = 0; i < pq->size; ++i) {
		pf(pq->entry[(pq->front + i) % MAX_QUEUE]);
	}
}

#else

#include <stdlib.h>

void init_queue(Queue *pq)
{
	pq->front = NULL;
	pq->rear  = NULL;
	pq->size  = 0;
}

void enqueue(QUEUE_ENTRY e, Queue *pq)
{
	QNode *pn = (QNode *) malloc(sizeof(QNode));
	pn->entry = e;
	pn->next  = NULL;

	if (pq->rear)
		pq->rear->next = pn;
	else
		pq->front = pn;

	pq->rear = pn;
	pq->size++;
}

void dequeue(QUEUE_ENTRY *pe, Queue *pq)
{
	*pe = pq->front->entry;
	pq->size--;

	QNode *pn = pq->front;
	pq->front = pq->front->next;
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
		free(pq->front);
		pq->front = pq->rear;
	}
	pq->size = 0;
}

void traverse_queue(Queue *pq, void (*pf)(QUEUE_ENTRY))
{
	QNode *pn = pq->front;
	while (pn) {
		pf(pn->entry);
		pn = pn->next;
	}
}

#endif
