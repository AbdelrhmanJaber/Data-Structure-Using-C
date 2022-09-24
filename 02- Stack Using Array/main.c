#include<stdio.h>
#include"standard_types.h"
#include"stack.h"

void main(void)
{
	u32 element;
	stack s;
	CreateStack(&s);
	push(&s);
	push(&s);
	push(&s);
	push(&s);
	push(&s);
	printf("number of stack elements = %d\n",CountStack(&s));
	printf("the pop stack element value = %d\n",pop(&s));
	PrintStack(&s);
	
	CreateStack(&s);
	push(&s);
	push(&s);
	push(&s);
	printf("number of stack elements = %d\n",CountStack(&s));
	PrintStack(&s);
	
}