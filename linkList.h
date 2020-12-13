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

Status InitLinkList(LinkListPtr head);

Status ClearLinkList(LinkListPtr head);

Status DestroyLinkList(LinkListPtr head);

Status TraverseLinkList(LinkList list);

boolean LinkList_Empty(LinkList list);

int LinkList_Length(LinkList list);

ElemType LinkList_GetElem(LinkList list, int index);

int LinkList_LocateElem(LinkList list, ElemType elem);

Status LinkList_Insert(LinkListPtr head, int index, ElemType elem);

Status LinkList_Delete(LinkListPtr head, int index);

LinkList CreatLinkList(int length);