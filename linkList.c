#include "linkList.h"

#include <stdio.h>
#include <malloc.h>
#include <process.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

Status InitLinkList(LinkListPtr head) {
	head = (LinkListPtr)malloc(sizeof(LinkList));
	// 不加内存判断，会有“取消对NULL指针的‘ListHead’的引用”的警告
	if (!(head)) exit(OVERFLOW);

	head->elem = 0;
	head->next = NULL;

	return OK;
}

Status ClearLinkList(LinkListPtr head) {
	Node* prevNode, * nextHead;
	if (!head || !head->next) return ERROR;

	prevNode = head->next;

	while (prevNode) {
		nextHead = prevNode->next;
		free(prevNode);
		prevNode = nextHead;
	}
	return OK;
}

Status DestroyLinkList(LinkListPtr head) {
	Node* prevNode, * nextNode;
	if (!head) return ERROR;

	// 连同头指针一起销毁
	prevNode = head;

	while (prevNode) {
		nextNode = prevNode->next;
		free(prevNode);
		prevNode = nextNode;
	}
	return OK;
}

Status TraverseLinkList(LinkList list) {
	Node* prevNode;
	prevNode = list.next;
	while (prevNode != NULL) {
		printf("%d ", (int)prevNode->elem);
		prevNode = prevNode->next;
	}
	return OK;
}

// 返回链表是否为空
bool LinkList_Empty(LinkList list) {
	return (list.next == NULL) ? 1 : 0;
}

int LinkList_Length(LinkList list) {
	Node* prevNode;
	int length = 0;
	if (!list.next) return 0;
	prevNode = list.next;

	while (prevNode) {
		length++;
		prevNode = prevNode->next;
	}

	return length;
}

ElemType LinkList_GetElem(LinkList list, int index) {
	if (!list.next) return 0;
	Node* prevNode = list.next;

	int prevIndex = 1;
	prevNode = list.next;

	while (prevNode && prevIndex < index) {
		prevIndex++;
		prevNode = prevNode->next;
	}

	if (prevIndex < index || !prevNode) return 0;

	return prevNode->elem;
}

int LinkList_LocateElem(LinkList list, ElemType elem) {
	if (!list.next) return ERROR;
	int index = 0;
	Node* prevNode = list.next;

	while (prevNode) {
		index++;
		if (prevNode->elem == elem) return index;
		prevNode = prevNode->next;
	}

	// 找不到这个数
	return 0;
}

Status LinkList_Insert(LinkListPtr head, int index, ElemType elem) {
	if (!head || !head->next) return ERROR;
	Node* prevNode;
	int prevIndex = 0;

	prevNode = head;
	while (prevNode && prevIndex < index - 1) {
		prevIndex++;
		prevNode = prevNode->next;
	}

	if (!prevNode) return ERROR;

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) exit(OVERFLOW);
	
	newNode->elem = elem;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
	return OK;
}

Status LinkList_Delete(LinkListPtr head, int index) {
	if (!head || !head->next) return ERROR;
	Node* prevNode;
	int prevIndex = 0;

	prevNode = head;
	while (prevNode->next && prevIndex < index - 1) {
		prevIndex++;
		prevNode = prevNode->next;
	}

	if (!prevNode->next) return ERROR;

	Node* delNode = prevNode->next;
	if (delNode->next) prevNode->next = delNode->next;
	else prevNode->next = NULL;


	free(delNode);
	return OK;
}

LinkList CreatLinkList(int length) {
	LinkList newList;
	InitLinkList(&newList);

	Node* prevNode, * nextNode;
	prevNode = &newList;
	for (int i = 0; i < length; i++) {
		ElemType elem;
		scanf_s("%d", &(int)elem);

		nextNode = (Node*)malloc(sizeof(Node));
		if (!nextNode) exit(OVERFLOW);
		nextNode->elem = elem;
		nextNode->next = NULL;

		prevNode->next = nextNode;
		prevNode = nextNode;
	}
	return newList;
}