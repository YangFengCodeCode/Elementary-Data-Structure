#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		perror("malloc fail");
		return;
	}
	//将数组全部初始化为0
	memset(count, 0, sizeof(int) * range);

	//计数
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	//排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}

int main()
{
	int arr[] = { 5, 6, 7, 1, 3, 9, 2, 5, 1, 1 };
	CountSort(arr, sizeof(arr) / sizeof(int));
	
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


