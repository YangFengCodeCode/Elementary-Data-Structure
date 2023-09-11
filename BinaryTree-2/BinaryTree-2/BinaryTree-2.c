#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
//typedef int HPDataType;


//void AdjustUp(HPDataType* a, int child)
//{
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (a[child] > a[parent])//建大堆
//		{
//			Swap(&a[child], &a[parent]);
//			child = parent;
//			parent = (parent - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

//void Swap(HPDataType* p1, HPDataType* p2)
//{
//	HPDataType tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//void AdjustDown(HPDataType* a, int n, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		if (child + 1 < n && a[child + 1] < a[child])
//		{
//			++child;
//		}
//
//		if (a[child] < a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			// 继续往下调整
//			parent = child;
//			child = child * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//// 升序
//void HeapSort(int* a, int n)
//{
//	//建大堆
//	for (int i = (n-1-1)/2; i >=0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}
//
//
//
//int main()
//{
//	int a[] = { 2,3,5,7,4,6,8 };
//	HeapSort(a, sizeof(a) / sizeof(int));
//
//	return 0;
//}


//TOP - K问题：即求数据结合中前K个最大的元素或者最小的元素，一般情况下数据量都比较大。
//比如：专业前10名、世界500强、富豪榜、游戏中前100的活跃玩家等。
//对于Top - K问题，能想到的最简单直接的方式就是排序，但是：如果数据量非常大，排序就不太可取了(可能
//	数据都不能一下子全部加载到内存中)。最佳的方式就是用堆来解决，基本思路如下：
//	1. 用数据集合中前K个元素来建堆
//	前k个最大的元素，则建小堆
//	前k个最小的元素，则建大堆
//	2. 用剩余的N - K个元素依次与堆顶元素来比较，不满足则替换堆顶元素


typedef int HPDataType;

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			// 继续往下调整
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void PrintTopK(const char* filename, int k)
{
	// 1. 建堆--用a中前k个元素建堆 （小堆）
	FILE* fout = fopen(filename, "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}

	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc fail");
		return;
	}

	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minheap[i]);
	}

	// 前k个数建小堆
	for (int i = (k - 2) / 2; i >= 0; --i)
	{
		AdjustDown(minheap, k, i);
	}


	// 2. 将剩余n-k个元素依次与堆顶元素交换，不满则则替换
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (x > minheap[0])
		{
			// 替换你进堆
			minheap[0] = x;
			AdjustDown(minheap, k, 0);
		}
	}


	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	}
	printf("\n");

	fclose(fout);
}

// fprintf  fscanf

void CreateNDate()
{
	// 造数据
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		int x = (rand() + i) % 100000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

int main()
{
	CreateNDate();
	PrintTopK("data.txt", 5);

	return 0;
}