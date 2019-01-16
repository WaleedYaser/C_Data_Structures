#define QUEUE_ENTRY int
#define MAX_QUEUE   10

typedef struct _Queue {
	int front;
	int rear;
	int size;
	QUEUE_ENTRY entry[MAX_QUEUE];
} Queue;

void init_queue(Queue *pq);

/* pre: queue is initialized and not full*/
void enqueue(QUEUE_ENTRY e, Queue *pq);

/* pre: queue is initialized and not empty */
void dequeue(QUEUE_ENTRY *pe, Queue *pq);

/* pre: queue is initialized */
int queue_empty(const Queue *pq);

/* pre: queue is initialized */
int queue_full(const Queue *pq);

/* pre: queue is initialized */
int queue_size(const Queue *pq);

/* pre: queue is initialized */
void clear_queue(Queue *pq);

/* pre: queue is initialized */
void traverse_queue(Queue *pq, void (*pf)(QUEUE_ENTRY));
