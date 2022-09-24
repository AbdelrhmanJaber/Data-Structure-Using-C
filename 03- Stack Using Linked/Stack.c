#include<stdio.h>
#include<stdlib.h>
#include"standard_types.h"
#include"Stack.h"

node*push(node**TopStack)
{
	node*temp=(node*)malloc(sizeof(node));//reverse an allocation at heap
	if(temp==NULL)
	{
		printf("The stack is full\n");
		return *TopStack;
	}
	else
	{
		printf("Enter the data of the top of the stack: ");
		scanf("%d",&temp->data);
		temp->next=*TopStack; //the node we added points to the last node added
		*TopStack=temp; //the top of the stack points to the first node of the stack
		return *TopStack;
	}
}

node*pop(node**TopStack)
{
	node*temp=*TopStack;//temp points to the top of the stack
	if(temp==NULL)
	{
		printf("the stack is empty\n");
		return *TopStack;
	}
	else
	{
	    *TopStack=temp->next;
	    free(temp);//pop the first element of the stack
	    return *TopStack;
	}
}

node*ClearStack(node**TopStack)
{
	node*temp1=*TopStack;
	node*temp2=*TopStack;
	while(temp1!=NULL)
	{
		temp1=temp1->next;
		free(temp2);
		temp2=temp1;
	}//all stack element deleted
	*TopStack=NULL;
	return *TopStack;
}

u8 CountNodes (node**TopStack)
{
	u8 count=0;
	node*temp=*TopStack;
	while(temp)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

void PrintStack(node**TopStack)
{
	node*temp=*TopStack;
	if(temp==NULL)
		printf("the stack is empty\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
