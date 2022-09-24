#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 100
typedef struct myStruct
{
	u32 StackArray[MAX_SIZE];
	s32 top;
}stack;
void CreateStack(stack*s);
void push(stack*s);
u32 pop(stack*s);
u32 IsEmpty(stack*s);
u32 IsFullStack(stack*s);
u32 CountStack(stack*s);
void PrintStack(stack*s);
#endif