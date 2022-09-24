#include<stdio.h>
#include<stdlib.h>
#include"standard_types.h"
#include"Linked_List.h"

enum
{
	CREATE_LIST=1,
	DISPLAY_LIST,
	COUNT_NODES,
	SEARCH,
	INSERT_AT_BEGANING,
	INSERT_AT_END,
	INSERT_BEFORE,
	INSERT_AFTER,
	INSERT_AT_POSITION,
	DELETE_NODE_BY_VALUE,
	DELETE_NODE_BY_NODE_NUMBER,
	PRINT_REVERSE,
	REVERSE_LIST
};

void main(void)
{
	node *head=NULL;
	u32 option,number1,number2,data1,data2,position1,position2,position3;
	u8 counter;
	while(1)
	{
		printf("\n================================\n");
		printf("1/CREATE LIST  2/DISPLAY LIST  \n3/COUNT NODES  4/SEARCH");
		printf("\n5/INSERT AT BEGANING  6/INSERT AT END  \n7/INSERT BEFORE  ");
		printf("8/INSERT AFTER  \n9/INSERT AT POSITION  10/DELETE NODE BY VALUE  ");
		printf("11/DELETE NODE BY NODE NUMBER  \n12/PRINT REVERSE  13/REVERSE LIST  ");
		printf("\n14/terminate the code\nEnter the option: ");
		printf("\n================================\n");
		scanf("%d",&option);
		
		switch(option)
		{
			case CREATE_LIST:
			printf("Input the number of nodes in the list: ");
			scanf("%d",&number1);
			head=CreateList(head,number1);
			break;
			
			case DISPLAY_LIST:
			head=DisplayList(head);
			break;
			
			case COUNT_NODES:
			counter=CountNodes(head);
			printf("\nthe number of nodes = %d",counter);
			break;
			
			case SEARCH:
			printf("Enter the data you want to search: ");
			scanf("%d",&data1);
			Search(head,data1);
			break;
			
			case INSERT_AT_BEGANING:
			head=InsertAtBegaining(head);
			break;
			
			case INSERT_AT_END :
			head=InsertAtEnd(head);
			break;
			
			case INSERT_BEFORE:
			printf("Enter the position to insert the data before it: ");
			scanf("%d",&position1);
			head=InsertBefore(head,position1);
			break;
			
			case INSERT_AFTER:
			printf("Enter the position to insert the data after it: ");
			scanf("%d",&position2);
			head=InsertAfter(head,position2);
			break;
			
			case INSERT_AT_POSITION:
			printf("Enter the position to insert the data on it: ");
			scanf("%d",&position3);
			head=InsertAtPoisiton(head,position3);
			break;
			
			case DELETE_NODE_BY_VALUE:
			printf("Enter the data to be removed: ");
			scanf("%d",&data2);
			head=DeleteNodeByValue(head,data2);
			break;
			
			case DELETE_NODE_BY_NODE_NUMBER:
			printf("Enter the number of node you want to be deleted: ");
			scanf("%d",&number2);
			head=DeleteNodeByNodeNumber(head,number2);
			break;
			
			case PRINT_REVERSE:
			head=PrintReverse(head);
			break;
			
			case REVERSE_LIST:
			head=ReverseList(head);
			break;
		}
		if(option==14)
			break;
	}
	
}