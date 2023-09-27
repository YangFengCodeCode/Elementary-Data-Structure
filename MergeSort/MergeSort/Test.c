#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"


void Test1()
{
	int a[] = {1, 7, 2, 3, 9, 6, 10};
	MergeSort(a, 7);
	Print(a, 7);
}
int main()
{
	Test1();
	return 0;
}