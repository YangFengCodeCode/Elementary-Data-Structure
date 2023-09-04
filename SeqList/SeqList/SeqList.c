#include"SeqList.h"

void SLInit(SL* ps)
{
	assert(ps);//断言 防止是空指针

	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc failed");
		exit(-1);
		//return;
	}

	ps->size = 0;
	ps->capacity = 4;
}

void SLDestroy(SL* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SLPrint(SL* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SLCheckCapacity(SL* ps)
{
	assert(ps);

	// 满了要扩容
	if (ps->size == ps->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(ps->a, ps->capacity * 2 * (sizeof(SLDataType)));
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity *= 2;
	}
}

// 17:25继续
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	SLCheckCapacity(ps);//检查是否要扩容

	ps->a[ps->size] = x;
	ps->size++;
}

void SLPopBack(SL* ps)
{
	assert(ps);

	// 温柔的检查
	//if (ps->size == 0)
		//return;

	// 暴力的检查
	assert(ps->size > 0);

	//ps->a[ps->size - 1] = 0;
	ps->size--;

}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	SLCheckCapacity(ps);

	// 挪动数据
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;

}

void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);

	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}

	ps->size--;
}

int SLFind(SL* ps, SLDataType x)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}

	return -1;
}

// 在pos位置插入x
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);

	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}

// 删除pos位置的值
void SLErase(SL* ps, int pos)
{
	assert(ps);

	assert(pos >= 0 && pos < ps->size);

	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}

	ps->size--;
}

void SLModify(SL* ps, int pos, SLDataType x)
{
	assert(ps);

	assert(pos >= 0 && pos < ps->size);

	ps->a[pos] = x;
}
