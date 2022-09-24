#ifndef STACK_H
#define STACK_H
typedef struct myStruct
{
	u32 data;
	u8 counter;
	struct myStruct* next;
}node;

node*push(node**TopStack);
node*pop(node**TopStack);
node*ClearStack(node**TopStack);
void PrintStack(node**TopStack);
u8 CountNodes (node**TopStack);
#endif

