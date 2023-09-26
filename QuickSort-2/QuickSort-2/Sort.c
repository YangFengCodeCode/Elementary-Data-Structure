#define _CRT_SECURE_NO_WARNINGS 1
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
	// 11:40
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

	ps->a[ps->top] = x;
	ps->top++;
}

void STPop(ST* ps)
{
	assert(ps);

	// 
	assert(ps->top > 0);

	--ps->top;
}

STDataType STTop(ST* ps)
{
	assert(ps);

	// 
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



void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


// 三数取中
int GetMidi(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	// left mid right
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])  // mid是最大值
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right]) // mid是最小
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}


void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
			}
			else
			{
				break;
			}
			end--;
		}
		a[end + 1] = tmp;
	}
}

int PartSort(int* a, int left, int right)
{
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);


	int keyi = left;
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}



void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	if ((end - begin + 1) > 10)
	{
		int keyi = PartSort(a, begin, end);
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	else
	{
		//插入排序
		InsertSort(a + begin, end - begin + 1);
	}
}


void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	STInit(&st);
	STPush(&st, end);
	STPush(&st, begin);
	while (!STEmpty(&st))
	{
		int left = STTop(&st);
		STPop(&st);

		int right = STTop(&st);
		STPop(&st);

		int keyi = PartSort(a, left, right);
		// [lefy,keyi-1] keyi [keyi+1, right]
		if (keyi + 1 < right)
		{
			STPush(&st, right);
			STPush(&st, keyi + 1);
		}

		if (left < keyi - 1)
		{
			STPush(&st, keyi - 1);
			STPush(&st, left);
		}
	}

	STDestroy(&st);
}
int main()
{
	int arr[] = { 6,1,3,4, 6,9, 10 };
	QuickSort(arr, 0, 6);
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", arr[i]);
	}
}