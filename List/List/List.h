#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

//扩容
LTNode* BuyLTNode(LTDataType x);

//初始化
LTNode* LTInit();

//打印
void LTPrint(LTNode* phead);

//尾插尾删
void LTPushBack(LTNode* phead, LTDataType x);
void LTPopBack(LTNode* phead);

//头插头删
void LTPushFront(LTNode* phead, LTDataType x);
void LTPopFront(LTNode* phead);

//链表大小
int LTSize(LTNode* phead);

//找值位置
LTNode* LTFind(LTNode* phead, LTDataType x);

// 在pos位置插入x
void LTInsert(LTNode* pos, LTDataType x);
// 删除pos位置
void LTErase(LTNode* pos);


