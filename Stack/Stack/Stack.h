#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//初始化
void STInit(ST* ps);

//销毁
void STDestroy(ST* ps);

//插入
void STPush(ST* ps, STDataType x);

//删除
void STPop(ST* ps);

//找到top
STDataType STTop(ST* ps);

//计算大小
int STSize(ST* ps);

//栈变空
bool STEmpty(ST* ps);



