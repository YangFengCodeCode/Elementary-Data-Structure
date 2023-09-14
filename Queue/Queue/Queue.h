#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Que;

void QueueInit(Que* pq);
void QueueDestroy(Que* pq);
void QueuePush(Que* pq, QDataType x);
void QueuePop(Que* pq);
QDataType QueueFront(Que* pq);
QDataType QueueBack(Que* pq);
bool QueueEmpty(Que* pq);
int QueueSize(Que* pq);


