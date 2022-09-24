#ifndef QUEUE_H
#define QUEUE_H
#define MAX_SIZE 4
typedef struct myStruct
{
	int front;
	int rear;
	int size;
	int QueueArray[MAX_SIZE];
}queue;
void CreateQueue(queue *pq);
void enqueue(queue *pq);
int dequeue(queue *pq);
int FirstElement (queue *pq);
int IsEmpty (queue *pq);
int IsFull(queue *pq);
void PrintQueue(queue*pq);
#endif