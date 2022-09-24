#include<stdio.h>
#include"standard_types.h"
#include"stack.h"

void CreateStack(stack*s)
{
	s->top=-1;
}

void push(stack*s)
{
	u32 element;
	if((s->top)==MAX_SIZE)
	   printf("Stack is full\n");
    else
	{
		s->top++;
		printf("Enter an element of the stack: ");
		scanf("%d",&element);
		s->StackArray[s->top]=element;
	}
}

u32 pop(stack*s)
{
	if(s->top==-1)
	{
		printf("the stack is empty\n");
		return -1;
	}
	else
	{
		u32 element;
		element=s->StackArray[s->top];
		s->top--;
		return element;
	}
}

u32 IsEmpty(stack*s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

u32 IsFullStack(stack*s)
{
	if(s->top>=MAX_SIZE)
		return 1;
	else 
		return 0;
}

u32 CountStack(stack*s)
{
	u32 counter=0;
	s8 flag=s->top;
	while(flag>-1)
	{
		counter++;
		flag--;
	}
	return counter;
}

void PrintStack(stack*s)
{
	stack*temp=s;
	while((temp->top)>-1)
	{
		printf("%d ",s->StackArray[s->top]);
		s->top--;
	}
}