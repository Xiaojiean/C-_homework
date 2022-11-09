/*
@file:		sequnenceListC.h
@brief:		顺序表和操作函数的C语言定义
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
@brief			初始化顺序表
@param	list:	引用顺序表地址
@return			状态
*/
Status InitSqList(SqListPtr list);

/*
@brief			显示顺序表中所有元素(int)
@param	list:	引用顺序表地址
*/
void ShowSqList(SqListPtr list);

/*
@brief			将两个顺序表合并并返回新顺序表
@param	list1:	顺序表1
@param	list2:	顺序表2
@return			合并后的新顺序表
*/
SqList MergeSqList(SqList list1, SqList list2);

/*
@brief			根据索引从顺序表中插入一个元素
@param	list:	引用顺序表地址
@param  index:	插入索引
@param	elem:	插入元素
@return			状态
*/
Status SqList_Insert(SqListPtr list, int index, ElemType elem);

/*
@brief			根据索引从顺序表中删除一个元素
@param	list:	引用顺序表地址
@param  index:	删除索引
@return			状态
*/
Status SqList_Delete(SqListPtr list, int index);

/*
@brief			获取顺序表中最大值
@param	list:	顺序表
@return			最大值
*/
ElemType SqList_Max(SqList list);

/*
@brief			获取顺序表中最小值
@param	list:	顺序表
@return			最小值
*/
ElemType SqList_Min(SqList list);