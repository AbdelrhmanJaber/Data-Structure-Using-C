#ifndef QUEUE_H
#define QUEUE_H
typedef struct myStruct
{
	int data;
	struct myStruct *next;
}QueueNode;

typedef struct QUEUE
{
	QueueNode*front;
	QueueNode*rear;
	int size;
}queue;
queue* CreateQueue(queue* pq);
queue* enqueue(queue *pq);
queue* dequeue(queue* pq,int *DequeueValue);
int FirstElement (queue* pq);
int IsFull(queue* pq);
int IsEmpty(queue* pq);
int QueueSize(queue* pq);
void PrintQueue(queue* pq);
#endif