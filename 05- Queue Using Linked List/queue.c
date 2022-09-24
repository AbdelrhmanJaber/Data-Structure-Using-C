#include<Stdio.h>
#include<stdlib.h>
#include"queue.h"

queue* CreateQueue(queue* pq)
{
	pq->front=NULL;
	pq->rear=NULL;
	pq->size=0;
	return pq;
	
}
queue* enqueue(queue *pq)
{
	QueueNode*temp=(QueueNode*)malloc(sizeof(QueueNode));
	if(temp!=NULL)
	{
		printf("Enter the data of the rear of the queue: ");
		scanf("%d",&temp->data);
		temp->next=NULL;
		
		if((pq->rear)==NULL)
			pq->front=temp;
		else
			pq->rear->next=temp;
		
		pq->rear=temp;
		pq->size++;
		return pq;
	}
	
}

queue* dequeue(queue* pq,int *DequeueValue)
{
	*DequeueValue=pq->front->data;
	QueueNode*temp=pq->front;
	pq->front=temp->next;
	free(temp);
	pq->size--;
	return pq;
}

int FirstElement (queue* pq)
{
	int element=pq->front->data;
	return element;
}

int IsFull(queue* pq)
{
	return 0;
}

int IsEmpty(queue* pq)
{
	if(pq->front==NULL)
		return 1;
	else
		return 0;
}

int QueueSize(queue* pq)
{
	return pq->size;
}

void PrintQueue(queue* pq)
{
	QueueNode* temp=pq->front;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

