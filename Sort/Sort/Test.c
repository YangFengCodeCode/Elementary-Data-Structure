#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"


void Test1()
{
	int arr[] = { 1,3,2,5,4,7,9 };
	InsertSort(arr, 7);
	PrintArray(arr, 7);
}

void Test2()
{
	int arr[] = { 10, 1,3,2,5,4,7,9 };
	ShellSort(arr, 8);
	PrintArray(arr, 8);
}


void Test3()
{
	int arr[] = { 10,1,3,2,5,4,7,9 };
	HeapSort(arr, 8);
	PrintArray(arr, 8);
}


void Test4()
{
	int arr[] = { 10,1,3,2,5,4,7,9 };
	SelectSort(arr, 8);
	PrintArray(arr, 8);
}


void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = N - 1; i >= 0; --i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();


	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}

int main()
{
	TestOP();
	return 0;
}
