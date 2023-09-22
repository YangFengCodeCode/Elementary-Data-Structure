#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

// ����ȡ��
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
		else if (a[left] > a[right])  // mid�����ֵ
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
		else if (a[left] < a[right]) // mid����С
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}


int PartSort1(int* a, int left, int right)
{
	//����ȡ��
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);

	int keyi = left;
	while (left < right)
	{
		//��С
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}

		//�Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}

		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}

int PartSort2(int* a, int left, int right)
{
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);

	int key = a[left];
	//����keyֵ�Ժ� ����γɵ�һ����λ
	int hole = left;

	while (left < right)
	{
		//�ұ����ߣ���С�����ߵĿӣ��ұ��γ��µĿ�λ
		if (left < right && a[right] >= key)
		{
			right--;
		}

		a[hole] = a[right];
		hole = right;

		//������ߣ��Ҵ���ұߵĿӣ�����γ��µĿ�λ
		if (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

int PartSort3(int* a, int left, int right)
{
	int keyi = left;
	int prev = left;
	int cur = prev + 1;

	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
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
	int keyi = PartSort3(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

int main()
{
	int a[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}