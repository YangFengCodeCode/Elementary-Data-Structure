#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

//向上调整
void AdjustUp(HPDataType* a, int child);

//向下调整
void AdjustDown(HPDataType* a, int n, int parent);

//交换
void Swap(HPDataType* p1, HPDataType* p2);
//打印
void HeapPrint(HP* php);
//初始化
void HeapInit(HP* php);
//销毁
void HeapDestroy(HP* php);
//插入
void HeapPush(HP* php, HPDataType x);
//删除
void HeapPop(HP* php);
//返回堆顶
HPDataType HeapTop(HP* php);
//是否为空
bool HeapEmpty(HP* php);



