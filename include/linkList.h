/*
@file:		linkList.h
@brief:		����Ͳ���������C���Զ���
@author:	Adlexer Xu
@date:		20/9/19
*/

// Visual Studio 2019
#pragma once
// ȡ��VS��scanf()����ֵ�ı���
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
@brief				��ʼ������
@param head:		����ͷָ��
@return				״̬
*/
Status InitLinkList(LinkListPtr head);

/*
@brief				�������
@param head:		����ͷָ��
@return				״̬
*/
Status ClearLinkList(LinkListPtr head);

/*
@brief				������������ͷָ�룩
@param head:		����ͷָ��
@return				״̬
*/
Status DestroyLinkList(LinkListPtr head);

/*
@brief				�����������
@param list:		����ͷ
@return				״̬
*/
Status TraverseLinkList(LinkList list);

/*
@brief				���������Ƿ�Ϊ��
@param list:		����ͷ
@return				bool����
*/
boolean LinkList_Empty(LinkList list);

/*
@brief				����������
@param ListHead:	����ͷ
@return				int���ͳ���
*/
int LinkList_Length(LinkList list);

/*
@brief				���ظ�λ�õ�����Ԫ��
@param list:		����ͷ
@param index:		����
@return				ElemType���͵ĸ�����λ������Ԫ��
*/
ElemType LinkList_GetElem(LinkList list, int index);

/*
@brief				���ظ�Ԫ����������������λ��
@param list:		����ͷ
@param elem:		��Ԫ��
@return				int��������
*/
int LinkList_LocateElem(LinkList list, ElemType elem);

/*
@brief				�ڸ�����λ�ò���һ��Ԫ��
@param head:		����ͷָ��
@param index:		����
@param elem:		�����Ԫ��
@return				״̬
*/
Status LinkList_Insert(LinkListPtr head, int index, ElemType elem);

/*
@brief				�ڸ�����λ��ɾȥһ��Ԫ��
@param ListHead:	����ͷָ��
@param index:		����
@return				״̬
*/
Status LinkList_Delete(LinkListPtr head, int index);

/*
@brief				����ָ�����ȵ����������ֵ
@param length:		���볤��
@return				�����õ�����
*/
LinkList CreatLinkList(int length);