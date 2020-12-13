#pragma once
#include "linkList.h"

typedef struct stack {
	int length;
	LinkList list;
}Stack;

typedef Stack* StackPtr;

Status InitStack(StackPtr stack);

Status ClearStack(StackPtr stack);

boolean Stack_Empty(Stack stack);

int Stack_Length(Stack stack);

ElemType Stack_Back(Stack stack);

Status Stack_pushBack(StackPtr stack, ElemType elem);

Status Stack_popBack(StackPtr stack);