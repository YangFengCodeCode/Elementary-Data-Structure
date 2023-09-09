#include "Stack.h"

void STInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void STDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void STPush(ST* ps, STDataType x)
{
	assert(ps);

	//扩容
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity = newCapacity;
	}

	//插入
	ps->a[ps->top] = x;
	ps->top++;//top是栈顶的下一个位置
}

void STPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	--ps->top;
}

STDataType STTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}

int STSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

bool STEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}



//typedef char STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//void STInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->capacity = 0;
//	ps->top = 0;
//}
//
//void STDestroy(ST* ps)
//{
//	assert(ps);
//
//	free(ps->a);
//	ps->a = NULL;
//	ps->top = ps->capacity = 0;
//}
//
//void STPush(ST* ps, STDataType x)
//{
//	assert(ps);
//
//	//扩容
//	if (ps->top == ps->capacity)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			exit(-1);
//		}
//
//		ps->a = tmp;
//		ps->capacity = newCapacity;
//	}
//
//	//插入
//	ps->a[ps->top] = x;
//	ps->top++;//top是栈顶的下一个位置
//}
//
//void STPop(ST* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//
//	--ps->top;
//}
//
//STDataType STTop(ST* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//
//	return ps->a[ps->top - 1];
//}
//
//int STSize(ST* ps)
//{
//	assert(ps);
//
//	return ps->top;
//}
//
//bool STEmpty(ST* ps)
//{
//	assert(ps);
//
//	return ps->top == 0;
//}
//
//bool isValid(char* s) {
//	ST st;
//	STInit(&st);
//	while (*s)
//	{
//		//左括号进栈
//		if (*s == '(' || *s == '{' || *s == '[')
//		{
//			STPush(&st, *s);
//		}
//		else
//		{
//			if (STEmpty(&st))
//			{
//				STDestroy(&st);
//				return false;
//			}
//			//进栈
//			char topval = STTop(&st);
//			STPop(&st);
//			if ((*s == ']' && topval != '[') || (*s == '}' && topval != '{') || (*s == ')' && topval != '('))
//			{
//				STDestroy(&st);
//				return false;
//			}
//
//		}
//		s++;
//	}
//
//	bool ret = STEmpty(&st);
//	STDestroy(&st);
//	return ret;
//
//
//
//
//}