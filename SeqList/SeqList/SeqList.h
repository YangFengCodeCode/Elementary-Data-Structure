#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// 动态顺序表
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;        // 存储有效数据个数
	int capacity;    // 空间大小
}SL;

// 管理数据 -- 增删查改
void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPrint(SL* ps);
void SLCheckCapacity(SL* ps);

// 头插头删 尾插尾删
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);




// 返回下标，没有找打返回-1
int SLFind(SL* ps, SLDataType x);

// 在pos位置插入x
void SLInsert(SL* ps, int pos, SLDataType x);
// 删除pos位置的值
void SLErase(SL* ps, int pos);

void SLModify(SL* ps, int pos, SLDataType x);





