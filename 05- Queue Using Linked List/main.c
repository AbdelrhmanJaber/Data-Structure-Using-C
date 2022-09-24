#include<Stdio.h>
#include<stdlib.h>
#include"queue.h"

enum
{
	CREATE_QUEUE=1,
	ENQUEUE,
	DEQUEUE,
	FIRST_ELEMENT,
	QUEUE_SIZE,
	IS_EMPTY,
	IS_FULL,
	PRINT_QUEUE
};
void main (void)
{
	int option,DequeueValue;
	queue *q = malloc(sizeof(queue));
	printf("%d",q);

	while(1)
	{
		printf("\n==============================\n");
		printf("1- Create a Queue\n2- EnQueue\n3- DeQueue\n");
		printf("4- First Element of the queue\n5- Queue Size\n");
		printf("6- Check Queue Empty\n7- Check Queue Full\n");
		printf("8- Print Queue\n9-Exit\n");
		printf("Enter the option you want: ");
		scanf("%d",&option);
		printf("\n==============================\n");
		
		switch(option)
		{
			case CREATE_QUEUE:
				CreateQueue(q);
				break;
			
			case ENQUEUE:
				if(IsFull(q))
					printf("sorry the queue is full!\n");
				else
					enqueue(q);
				break;
			
			case DEQUEUE:
				if(IsEmpty(q))
					printf("the queue is empty\n");
				else
				{
					dequeue(q,&DequeueValue);
					printf("the dequeue value = %d",DequeueValue);
				}
				break;
				
			case FIRST_ELEMENT:
				if(IsEmpty(q))
					printf("the queue is empty\n");
				else
					printf("the front element = %d",FirstElement(q));
				break;
			
			case QUEUE_SIZE:
				printf("the size of queue is %d elements",QueueSize(q));
				break;
			
			case IS_EMPTY:
				if (IsEmpty(q))
					printf("the queue is empty\n");
				else
					printf("the queue isn't empty\n");
				break;
			
			case IS_FULL:
				if(IsFull(q))
					printf("the queue is full\n");
				else
					printf("the queue isn't full\n");
				break;
			
			case PRINT_QUEUE:
				if(IsEmpty(q))
					printf("the queue is empty\n");
				else
				PrintQueue(q);
				break;
		}
		if(option>=9||option<1)
			break;
	}
}