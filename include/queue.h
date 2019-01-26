#include "global.h"

#ifdef LIMITED_MEMORY

typedef struct _Queue {
	int		front;
	int		rear;
	int		size;
	int		t_size;
	void	*entry[MAX_QUEUE];
} Queue;

#else

typedef struct _QNode {
	void			*entry;
	struct _QNode	*next;
} QNode;

typedef struct LQueue {
	QNode 			*front;
	QNode			*rear;
	int				size;
	int				t_size;
} Queue;

#endif

void _init_queue(Queue *pq, int z);
#define init_queue(pq, type) _init_queue(pq, sizeof(type))

/* pre: queue is initialized and not full*/
void _enqueue(void *pe, Queue *pq);
#define enqueue(e, pq) _enqueue(((void *) &e), pq)

/* pre: queue is initialized and not empty */
void dequeue(void *pe, Queue *pq);

/* pre: queue is initialized */
int queue_empty(const Queue *pq);

/* pre: queue is initialized */
int queue_full(const Queue *pq);

/* pre: queue is initialized */
int queue_size(const Queue *pq);

/* pre: queue is initialized */
void clear_queue(Queue *pq);

/* pre: queue is initialized */
void traverse_queue(Queue *pq, void (*pf)(void *));
