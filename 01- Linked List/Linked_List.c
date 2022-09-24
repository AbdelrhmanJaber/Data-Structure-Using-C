#include<stdio.h>
#include<stdlib.h>
#include"standard_types.h"
#include"Linked_List.h"

node* CreateList(node*head,u32 number)
{
	node* link=(node*)malloc(sizeof(node));//reverse a meomry allocation at heap
	if(head==NULL) //LIST IS EMPTY
	{
		//CREAT THE FIRST AND THE LAST NODE
        printf("Enter the data at position 1: ");
	    scanf("%d",&link->data);
		link->next=NULL;
		head=link;//head points to the first node
	}
	node* temp=head;
	    for(int i=0;i<number-1;i++)
		{
			while(temp->next!=NULL)
			{
		        temp=temp->next;//get the last node
			}
			node* link=(node*)malloc(sizeof(node)); //reverse a new meomry allocation for the next node at heap
			temp->next=link; //temp->next points to the new node
			printf("Enter the data at position %d: ",i+2);
		    scanf("%d",&link->data);
		    link->next=NULL;//the new node will be the last node and so on
		}
	return head;
}

node* DisplayList(node*head)
{
	node *link=head;
	while(link!=NULL)
	{
		printf("%d ",link->data); //print node data
		link=link->next;   //update the node to next one
	}
	printf("\n================================\n");
	return head;
}

u8 CountNodes (node*head)
{
	 u8 counter=0;
	node*temp=head;
	while(temp!=NULL)
	{
		counter++;
		temp=temp->next;
	}
	return counter;
}

void Search(node*head,u32 data)
{
    node* temp=head;
	u8 position=0,flag=0;
	while(temp!=NULL)
	{
		position++;
		if(temp->data==data)
		{
			flag=1;//data is exist
			printf("%d is founded at node number %d\n",data,position);
	    }
		temp=temp->next;//go to the next node to check
	}
	if(flag==0) //doesnot enter the if condition
		printf("%d doesnot exist at the linked list\n");
}

node* InsertAtBegaining(node*head)
{
	node* link=(node*)malloc(sizeof(node));
	printf("Enter the data at beganing: ");
	scanf("%d",&link->data);
	link->next=head;
	head=link;
	return head;
}

node* InsertAtEnd(node*head)
{
	node * link=(node*)malloc(sizeof(node));
	if(link!=NULL)
	{
	   //Enter the data of the node
	   printf("Enter the data at end: ");
       scanf("%d",&(link->data));
       link->next=NULL;	   //will be the last node
	if (head==NULL) //if the list is empty
		head=link; //the first and the last node
	else
	{
		node*temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		/*temp will be at the node n-1*/
		temp->next=link;
		/*temp which aka the n-1 node points to link the last node you added*/
	}
	   return head;
	}
}

node* InsertBefore(node*head,u32 position)
{
	node * link=(node*)malloc(sizeof(node));
	if(link!=NULL)
	{
	   //Enter the data of the node
	   printf("Enter the data before poistion %d: ",position);
       scanf("%d",&link->data);
	}
	if (position==1) 
	{
		link->next=head; 
		head=link;
    }    	
	else
	{
		node* temp=head;
		for(int i=1;i<position-1;i++)
		{
			temp=temp->next;
		}
		//temp now at position-1 node
		link->next=temp->next; //link points to the certain node to be inserted before
		temp->next=link;
	}
	return head;
}

node* InsertAfter(node*head,u32 position)
{
	node * link=(node*)malloc(sizeof(node));
	if(link!=NULL)
	{
	   //Enter the data of the node
	   printf("Enter the data after poistion %d: ",position);
       scanf("%d",&link->data);
	}
	node*temp=head;
	for(int i=1;i<position;i++)
		temp=temp->next;
	//temp->next points to the position to insert node after
	link->next=temp->next; //link is created after the certain node 
	temp->next=link; //the node at certain position points to link
	return head;
}

node* InsertAtPoisiton(node*head,u32 position)
{
	node * link=(node*)malloc(sizeof(node));
	if(link!=NULL)
	{
	   //Enter the data of the node
	   printf("Enter the data at poistion %d: ",position);
       scanf("%d",&link->data);
	if(position==1)
	{
		link->next=head;
		head=link;
	}
	else
	{
	node*temp=head;
	for(int i=1;i<position-1;i++)
		temp=temp->next;
	//temp pointer points to the node before the position you want
	//temp->next points to the node you want to create
	link->next=temp->next; //link is created at the certain node and points to position+1
	temp->next=link; //the node at certain position points to link
	}
	return head;
	}
}

node* DeleteNodeByValue(node*head,u32 data)
{
	u8 position=1,flag=0;
	node*temp=head;
	node*previous=head;
	if(temp->data==data)
	{
		head=temp->next; //update head to point to the new first node
		previous->next=temp;
		free(temp); //delete the first node
		printf("the value %d is founded at node %d and deleted\n",data,position);
		return head;
	}
	 temp=temp->next; //now previous->next=temp
	while(temp!=NULL)
	{
		position++;
		if(temp->data==data)
		{
			flag=1;
			break;
		}
		previous=temp;
		temp=temp->next;
	}
	if(flag==1) //data founded
	{
		previous->next=temp->next;
		free(temp);
		printf("the value %d is founded at node %d and deleted\n",data,position);
		return head;
	}
	if(flag==0) //data not founded
	{
		printf("the value %d doesnot exist at the list\n",data);
		return head;
	}
} 

node* DeleteNodeByNodeNumber(node*head,u32 position)
{
	node*temp=head;
	node*previous=head;
	if(position>CountNodes(head)) //check if the input position exists at the list
	{
		printf("node %d doesn't exist in the list\n");
		return head;
	}
	else 
    {
	  if(position==1)
	  {
		  head=temp->next;
		  free(temp);
		  return head;
	  }  
	  else if(position>1)
	  {
	     temp=temp->next;
	     for(int i=2;i<position;i++)
	     {
		     previous=temp;
		     temp=temp->next;
 	     }
	     previous->next=temp->next;
	     free(temp);
	     return head;
	  }
	}
}

node* PrintReverse(node*head)
{
	node*temp=head;
	if(temp==NULL)
		return head;
	PrintReverse(temp->next); //call the function until temp==NULL
	printf("%d ",temp->data); //print the list revistly
	return head;
}

node* ReverseList(node*head)
{
    node* current = head;
    node* previous = NULL;
    node*NextNode;
    while(current!=NULL)
	{
		NextNode=current->next; //NextNode as a temp pointer
		current->next=previous; //current->next now points to the previous node 
		previous=current;   //previous now has the address of the current node
  		current=NextNode;   //update current to the next node
	}
	head=previous;
    return head;	
}