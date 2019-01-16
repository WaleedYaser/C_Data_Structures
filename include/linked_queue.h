#define LQUEUE_ENTRY int

typedef struct _QNode {
	LQUEUE_ENTRY 	entry;
	struct _QNode	*next;
} QNode;

typedef struct _LQueue {
	QNode 			*front;
	QNode			*rear;
	int				size;
} LQueue;

void init_lqueue(LQueue *plq);

/* pre: linked queue is initialized */
void lenqueue(LQUEUE_ENTRY e, LQueue *plq);

/* pre: linked queue is not empty */
void ldequeue(LQUEUE_ENTRY *pe, LQueue *plq);

/* pre: linked queue is initialized */
int lqueue_empty(const LQueue *plq);

/* pre: linked queue is initialized */
int lqueue_full(const LQueue *plq);

/* pre: linked queue is initialized */
int lqueue_size(const LQueue *plq);

/* pre: linked queue is initialized */
void clear_lqueue(LQueue *plq);

/* pre: linked queue is initialized */
void traverse_lqueue(LQueue *plq, void (*pf)(LQUEUE_ENTRY));
