void InitializeQueue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->item = 0;
}

bool QueueIsFull(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq)
{
	return pq->items == 0;
}

int QueueItemCount(const Queue *pq)
{
	return pq->items;
}
