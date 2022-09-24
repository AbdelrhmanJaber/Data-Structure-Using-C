#include<Stdio.h>
#include"Queue.h"

void CreateQueue(queue *pq)
{
	pq->front=2;
	pq->rear=1;
	pq->size=0;
}

void enqueue(queue *pq)
{
	pq->rear=((pq->rear)+1)%MAX_SIZE;
	printf("Enter the element of queue to the rear: ");
	scanf("%d",&pq->QueueArray[pq->rear]);
	pq->size++;
}

int dequeue(queue *pq)
{
	int dequeueVlaue;
	dequeueVlaue=pq->QueueArray[pq->front];
	pq->front=((pq->front)+1)%MAX_SIZE;
	pq->size--;
	return dequeueVlaue;
}

int FirstElement (queue *pq)
{
	int FrontElement;
	FrontElement=pq->QueueArray[pq->front];
	return FrontElement;
}

int IsEmpty (queue *pq)
{
	if(pq->size==0)
		return 1;
	else
		return 0;
}

int IsFull(queue *pq)
{
	if(pq->size>=MAX_SIZE)
		return 1;
	else
		return 0;
}

void PrintQueue(queue*pq)
{
	int FrontTemp=pq->front;
	int SizeTemp=pq->size;
	for (int i=0;i<SizeTemp;i++)
	{
		printf("%d ",pq->QueueArray[FrontTemp]);
		FrontTemp=(FrontTemp+1)%MAX_SIZE;
	}
}