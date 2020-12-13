#include <stdio.h>
#include <malloc.h>
#include <process.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

#include "sequnenceList.h"

Status InitSqList(SqListPtr list) {
	list->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!list->elem) exit(OVERFLOW);
	list->length = 0;
	list->size = LIST_INIT_SIZE;
	return OK;
}

void ShowSqList(SqListPtr list) {
	if (list->length == 0) {
		printf("empty list!\n");
		return;
	}
	for (ElemType* p = list->elem; p <= list->elem + list->length - 1; p++) {
		printf("%d ", (int)*p);
	}
	printf("\n");
}

SqList MergeSqList(SqList list1, SqList list2) {
	SqList newList;
	newList.length = list1.length + list2.length;
	newList.size = list1.size + list2.size;
	newList.elem = (ElemType*)malloc(newList.length * sizeof(ElemType));
	if (!newList.elem) exit(OVERFLOW);

	return newList;
}

Status SqList_Insert(SqListPtr list, int index, ElemType elem) {
	if (index < 1 || index > list->length + 1) return ERROR;
	if (list->length >= list->size) {
		ElemType* newElemPtr = (ElemType*)realloc(list->elem, ((size_t)list->size + LIST_INCREMENT) * sizeof(ElemType));
		if (!newElemPtr) exit(OVERFLOW);
		list->elem = newElemPtr;
		list->size += LIST_INCREMENT;
	}

	ElemType* pos = list->elem + index - 1;
	for (ElemType* p = list->elem + list->length; p > pos; p--) *(p) = *(p - 1);
	*pos = elem;
	list->length++;

	return OK;
}

Status SqList_Delete(SqListPtr list, int index) {
	if (index < 1 || index > list->length) return ERROR;
	for (ElemType* p = &(list->elem[index - 1]); p <= list->elem + list->length + 1; p++) {
		*(p - 1) = *p;
	}

	list->length--;
	return OK;
}

ElemType SqList_Max(SqList list) {
	ElemType maxElem = list.elem[0];
	for (int i = 1; i < list.length; i++) {
		maxElem = max(maxElem, list.elem[i]);
	}

	return maxElem;
}

ElemType SqList_Min(SqList list) {
	ElemType minElem = list.elem[0];
	for (int i = 1; i < list.length; i++) {
		minElem = min(minElem, list.elem[i]);
	}

	return minElem;
}