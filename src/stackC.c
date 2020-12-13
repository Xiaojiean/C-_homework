/*
@file:		StackC.h
@brief:		栈的C语言
@author:	Adlexer Xu
@date:		20/9/27
*/

#include "StackC.h"

#include <stdio.h>
#include <malloc.h>
#include <process.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

Status InitStack(StackPtr stack) {
	InitLinkList(&(stack->list));
	stack->length = 0;
	return OK;
}

Status ClearStack(StackPtr stack) {
	ClearLinkList(&(stack->list));
	stack->length = 0;
	return OK;
}

boolean Stack_Empty(Stack stack) {
	return stack.length == 0 ? 1 : 0;
}

int Stack_Length(Stack stack) {
	return stack.length;
}

ElemType Stack_Back(Stack stack) {
	return LinkList_GetElem(stack.list, stack.length);
}

Status Stack_pushBack(StackPtr stack, ElemType elem) {
	stack->length++;
	return LinkList_Insert(&(stack->list), stack->length, elem);
}

Status Stack_popBack(StackPtr stack) {
	return LinkList_Delete(&(stack->list), stack->length);
}