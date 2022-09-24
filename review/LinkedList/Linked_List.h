#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct myStruct
{
	u32 data;
	struct myStruct* next;
}node;
node* CreateList(node*head,u32 number);
node* DisplayList(node*head);
u8 CountNodes (node*head);
void Search(node*head,u32 data);
node* InsertAtBegaining(node*head);
node* InsertAtEnd(node*head);
node* InsertBefore(node*head,u32 position);
node* InsertAfter(node*head,u32 position);
node* InsertAtPoisiton(node*head,u32 position);
node* DeleteNodeByValue(node*head,u32 data);
node* DeleteNodeByNodeNumber(node*head,u32 data);
node* PrintReverse(node*head);
node* ReverseList(node*head);
#endif