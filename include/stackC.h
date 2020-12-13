/*
@file:		StackC.h
@brief:		栈的C语言定义
@author:	Adlexer Xu
@date:		20/9/27
*/

#pragma once
#include "linkList.h"

typedef struct stack {
	int length;
	LinkList list;
}Stack;

typedef Stack* StackPtr;

/*
@brief			初始化栈
@param	stack:	栈引用
@return			状态
*/
Status InitStack(StackPtr stack);

/*
@brief			清除栈中所有元素，重置栈
@param	stack:	栈引用
@return			状态
*/
Status ClearStack(StackPtr stack);

/*
@brief			判断栈是否为空
@param	stack:	栈
@return			bool类型
*/
boolean Stack_Empty(Stack stack);

/*
@brief			获取栈的当前长度
@param	stack:	栈
@return			长度
*/
int Stack_Length(Stack stack);

/*
@brief			获取栈顶元素
@param	stack:	栈
@return			栈顶元素
*/
ElemType Stack_Back(Stack stack);

/*
@brief			将元素加入栈
@param	stack:	栈引用
@param  elem:	元素
@return			状态
*/
Status Stack_pushBack(StackPtr stack, ElemType elem);

/*
@brief			将栈顶元素弹出
@param	stack:	栈引用
@return			状态
*/
Status Stack_popBack(StackPtr stack);