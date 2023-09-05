#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//打印
void SLTPrint(SLTNode* phead);

//扩容
SLTNode* BuySListNode(SLTDataType x);

//尾插头插
void SLTPushBack(SLTNode** pphead, SLTDataType x);
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//尾删头删
void SLTPopBack(SLTNode** pphead);
void SLTPopFront(SLTNode** pphead);

//找值
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);

// 在pos之前插入x
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

// 在pos以后插入x
void SLTInsertAfter(SLTNode* pos, SLTDataType x);

// 删除pos位置
void SLTErase(SLTNode** pphead, SLTNode* pos);

// 删除pos的后一个位置
void SLTInsertAfter(SLTNode* pos);