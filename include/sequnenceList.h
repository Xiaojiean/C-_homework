/*
@file:		sequnenceListC.h
@brief:		˳���Ͳ���������C���Զ���
@author:	Adlexer Xu
@date:		20/9/7
*/
#pragma once

#include "cdefine.h"

typedef struct {
	ElemType* elem;
	int length;
	int size;
}SqList;

typedef SqList* SqListPtr;

/*
@brief			��ʼ��˳���
@param	list:	����˳����ַ
@return			״̬
*/
Status InitSqList(SqListPtr list);

/*
@brief			��ʾ˳���������Ԫ��(int)
@param	list:	����˳����ַ
*/
void ShowSqList(SqListPtr list);

/*
@brief			������˳���ϲ���������˳���
@param	list1:	˳���1
@param	list2:	˳���2
@return			�ϲ������˳���
*/
SqList MergeSqList(SqList list1, SqList list2);

/*
@brief			����������˳����в���һ��Ԫ��
@param	list:	����˳����ַ
@param  index:	��������
@param	elem:	����Ԫ��
@return			״̬
*/
Status SqList_Insert(SqListPtr list, int index, ElemType elem);

/*
@brief			����������˳�����ɾ��һ��Ԫ��
@param	list:	����˳����ַ
@param  index:	ɾ������
@return			״̬
*/
Status SqList_Delete(SqListPtr list, int index);

/*
@brief			��ȡ˳��������ֵ
@param	list:	˳���
@return			���ֵ
*/
ElemType SqList_Max(SqList list);

/*
@brief			��ȡ˳�������Сֵ
@param	list:	˳���
@return			��Сֵ
*/
ElemType SqList_Min(SqList list);