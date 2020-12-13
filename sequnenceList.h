#pragma once

#include "cdefine.h"

typedef struct {
	ElemType* elem;
	int length;
	int size;
}SqList;

typedef SqList* SqListPtr;

Status InitSqList(SqListPtr list);

void ShowSqList(SqListPtr list);

SqList MergeSqList(SqList list1, SqList list2);

Status SqList_Insert(SqListPtr list, int index, ElemType elem);

Status SqList_Delete(SqListPtr list, int index);

ElemType SqList_Max(SqList list);

ElemType SqList_Min(SqList list);