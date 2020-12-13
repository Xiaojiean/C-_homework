/*
@file:		linkList.h
@brief:		链表和操作函数的C语言定义
@author:	Adlexer Xu
@date:		20/9/19
*/

// Visual Studio 2019
#pragma once
// 取消VS对scanf()返回值的报错
#pragma warning(disable:4996)

#include "cdefine.h"

typedef struct Node Node;

struct Node {
	ElemType elem;
	Node* next;
};

typedef Node LinkList;
typedef LinkList* LinkListPtr;

/*
@brief				初始化链表
@param head:		链表头指针
@return				状态
*/
Status InitLinkList(LinkListPtr head);

/*
@brief				清空链表
@param head:		链表头指针
@return				状态
*/
Status ClearLinkList(LinkListPtr head);

/*
@brief				销毁链表（包括头指针）
@param head:		链表头指针
@return				状态
*/
Status DestroyLinkList(LinkListPtr head);

/*
@brief				输出整个链表
@param list:		链表头
@return				状态
*/
Status TraverseLinkList(LinkList list);

/*
@brief				返回链表是否为空
@param list:		链表头
@return				bool类型
*/
boolean LinkList_Empty(LinkList list);

/*
@brief				返回链表长度
@param ListHead:	链表头
@return				int类型长度
*/
int LinkList_Length(LinkList list);

/*
@brief				返回该位置的链表元素
@param list:		链表头
@param index:		索引
@return				ElemType类型的该索引位置链表元素
*/
ElemType LinkList_GetElem(LinkList list, int index);

/*
@brief				返回该元素所处的链表索引位置
@param list:		链表头
@param elem:		该元素
@return				int类型索引
*/
int LinkList_LocateElem(LinkList list, ElemType elem);

/*
@brief				在该索引位置插入一个元素
@param head:		链表头指针
@param index:		索引
@param elem:		插入的元素
@return				状态
*/
Status LinkList_Insert(LinkListPtr head, int index, ElemType elem);

/*
@brief				在该索引位置删去一个元素
@param ListHead:	链表头指针
@param index:		索引
@return				状态
*/
Status LinkList_Delete(LinkListPtr head, int index);

/*
@brief				创建指定长度的链表并逐个赋值
@param length:		输入长度
@return				创建好的链表
*/
LinkList CreatLinkList(int length);