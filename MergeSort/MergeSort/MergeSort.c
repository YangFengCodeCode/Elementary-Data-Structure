#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}



void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (end <= begin)
	{
		return;
	}
	int mid = (begin + end) / 2;
    _MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);

	//归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid+1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] > a[begin2])
		{
			tmp[index++] = a[begin2++];
		}
		else
		{
			tmp[index++] = a[begin1++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	//拷贝回原数组
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
}
