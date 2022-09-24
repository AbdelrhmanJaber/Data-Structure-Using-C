#include<stdio.h>
#include<stdlib.h>
#include"standard_types.h"
#include"Stack.h"

enum 
{
	PUSH_STACK=1,
	POP_STACK,
	COUNT_STACK_NODES,
	PRINT_STACK,
	CLEAR_STACK
};
void main(void)
{
	u8 count;
	u32 option;
	node*TopStack=NULL;
	
	while (1)
	{
		printf("\n======================================\n");
		printf("1- push elements to the stack\n");
		printf("2- pop elements from the stack\n");
		printf("3- Count the nodes of the stack\n");
		printf("4- print the element of the stack\n5- clear the stack\n");
		printf("6- exit\nEnter the option you want: ");
		scanf("%d",&option);
		printf("\n======================================\n");
		switch(option)
		{
			case PUSH_STACK:
			TopStack=push(&TopStack);
			break;
			case POP_STACK:
			TopStack=pop(&TopStack);
			break;
			case COUNT_STACK_NODES:
			count=CountNodes (&TopStack);
			printf("number of nodes in stack = %d\n",count);
			break;
			case PRINT_STACK:
			PrintStack(&TopStack);
			break;
			case CLEAR_STACK:
            TopStack=ClearStack(&TopStack);
            break;			
		}
		if(option>=6||option<1)
	        break;
	}
}