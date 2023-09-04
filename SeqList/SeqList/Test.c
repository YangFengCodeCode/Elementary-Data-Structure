#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"SeqList.h"




void TestSeqList3()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	//SLPopFront(&sl);
	SLPrint(&sl);

	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLDestroy(&sl);
}



void TestSeqList5()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLErase(&sl, 2);
	SLPrint(&sl);

	int x;
	scanf("%d", &x);
	int pos = SLFind(&sl, x);
	if (pos != -1)
	{
		SLErase(&sl, pos);
	}
	SLPrint(&sl);

	SLDestroy(&sl);

}

void TestSeqList6()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLModify(&sl, 2, 20);
	sl.a[2] = 20;

	SLPrint(&sl);

	/*int x;
	scanf("%d", &x);
	int pos = SLFind(&sl, x);
	if (pos != -1)
	{
		SLModify(&sl, pos, x*10);
	}
	SLPrint(&sl);*/

	int pos, x;
	scanf("%d%d", &pos, &x);
	//sl.a[pos] = x;
	SLModify(&sl, pos, x);

	SLPrint(&sl);

	SLDestroy(&sl);
}

void TestSeqList7()
{
	/*SL* sl = NULL;
	SLInit(sl);
	SLPushBack(sl, 1);
	SLPushBack(sl, 2);
	SLPushBack(sl, 3);
	SLPushBack(sl, 4);
	SLPushBack(sl, 5);
	SLPrint(sl);*/

	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLPopFront(&sl);

	SLDestroy(&sl);
}



void TestSeqList9()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);

	SLPushFront(&sl, 400);
	SLPopFront(&sl);
	SLPrint(&sl);
	SLDestroy(&sl);
}



void TestSeqList4()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);
	SLInsert(&sl, 3, 40);
	SLPrint(&sl);

	SLErase(&sl, 3);
	SLPrint(&sl);

	SLDestroy(&sl);

}
int main()
{
	TestSeqList4();

	return 0;
}

//void menu()
//{
//	printf("****************************************\n");
//	printf("1、尾插  2、头插\n");
//	printf("3、头删  4、尾删\n");
//	// ...
//	printf("7、打印 -1、退出\n");
//
//	printf("****************************************\n");
//}
//
//// 16:05继续
//int main()
//{
//	SL sl;
//	SLInit(&sl);
//	int option = 0;
//	do
//	{
//		menu();
//		scanf("%d", &option);
//
//		if (option == 1)
//		{
//			//printf("请依次输入输入你要插入的数据，以-1结束\n");
//			printf("请依次输入你要插入数据个数和数据\n");
//			int n = 0;
//			scanf("%d", &n);
//
//			int x = 0;
//			for (int i = 0; i < n; i++)
//			{
//				scanf("%d", &x);
//				SLPushBack(&sl, x);
//			}
//		}
//		else if (option == 2)
//		{
//			SLPopFront(&sl);
//		}
//		else if (option == 7)
//		{
//			SLPrint(&sl);
//		}
//	} while (option != -1);
//
//	SLDestroy(&sl);
//
//	return 0;
//}

//int* p1 = (int*)malloc(12);

//int* p2 = realloc(p1, 200);

//printf("%p, %p\n", p1, p2);

//////////////////////////////////////////////////////////////////////////////////////////
// single link table
//typedef int SLTDataType;
//struct SListNode
//{
//	SLTDataType data;
//	struct SListNode* next;
//};
//
//typedef struct SListNode SLTNode;

//typedef int SLTDataType;
//typedef struct SListNode
//{
//	SLTDataType data;
//	struct SListNode* next;
//}SLTNode;
//
//void PrintSList(SLTNode* phead)
//{
//	SLTNode* cur = phead;
//	while (cur != NULL)
//	{
//		printf("%d->", cur->data);
//		cur = cur->next;
//		//++cur;
//	}
//
//	printf("NULL\n");
//}
//
//int main()
//{
//	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
//	n1->data = 10;
//
//	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
//	n2->data = 20;
//
//	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
//	n3->data = 30;
//
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = NULL;
//
//	PrintSList(n1);
//
//	return 0;
//}