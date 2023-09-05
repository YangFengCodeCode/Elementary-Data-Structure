#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"


//void TestSList2()
//{
//	SLTNode* plist = NULL;
//	SLTPushBack(&plist, 1);
//	SLTPushBack(&plist, 2);
//	SLTPushBack(&plist, 3);
//	SLTPushBack(&plist, 4);
//	SLTPushBack(&plist, 5);
//	SLTPrint(plist);
//
//	SLTPushFront(&plist, 10);
//	SLTPushFront(&plist, 20);
//	SLTPushFront(&plist, 30);
//	SLTPushFront(&plist, 40);
//	SLTPrint(plist);
//}

//void TestSList3()
//{
//	SLTNode* plist = NULL;
//	SLTPushBack(&plist, 1);
//	SLTPushBack(&plist, 2);
//	SLTPushBack(&plist, 3);
//	SLTPushBack(&plist, 4);
//	SLTPushBack(&plist, 5);
//	SLTPrint(plist);
//
//
//	SLTPopBack(&plist);
//	SLTPrint(plist);
//
//	SLTPopBack(&plist);
//	SLTPrint(plist);
//
//	SLTPopBack(&plist);
//	SLTPrint(plist);
//
//	SLTPopBack(&plist);
//	SLTPrint(plist);
//
//	SLTPopBack(&plist);
//	SLTPrint(plist);
//
//	// SLTPopBack(&plist);
//	// SLTPrint(plist);
//}

//void TestSList4()
//{
//	SLTNode* plist = NULL;
//	SLTPushBack(&plist, 1);
//	SLTPushBack(&plist, 2);
//	SLTPushBack(&plist, 3);
//	SLTPushBack(&plist, 4);
//	SLTPushBack(&plist, 5);
//	SLTPrint(plist);
//
//	SLTPopFront(&plist);
//	SLTPrint(plist);
//
//	SLTPopFront(&plist);
//	SLTPrint(plist);
//
//	SLTPopFront(&plist);
//	SLTPrint(plist);
//
//	SLTPopFront(&plist);
//	SLTPrint(plist);
//
//	SLTPopFront(&plist);
//	//SLTPopFront(&plist);
//	SLTPrint(plist);
//}

//void TestSList5()
//{
//	SLTNode* plist = NULL;
//	SLTPushBack(&plist, 1);
//	SLTPushBack(&plist, 2);
//	SLTPushBack(&plist, 3);
//	SLTPushBack(&plist, 4);
//	SLTPushBack(&plist, 5);
//	SLTPrint(plist);
//
//	SLTNode* pos = SLTFind(plist, 3);
//	SLTInsert(&plist, pos, 30);
//}
//

void TestSList1()
{
	int n;
	printf("请输入链表的长度：");
	scanf("%d", &n);
	printf("\n请依次输入每个节点的值:");
	SLTNode* plist = NULL;

	for (size_t i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		SLTNode* newnode = BuySListNode(val);

		// 头插
		newnode->next = plist;
		plist = newnode;
	}

	SLTPrint(plist);

}


void TestSList2()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);//传地址 才能改变结构体
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);
	SLTPrint(plist);

}


void TestSList3()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);
	SLTPrint(plist);


	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

}


void TestSList4()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);
}




void TestSList5()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);
	SLTPrint(plist);

	int x;
	scanf("%d", &x);
	SLTNode* pos = SLTFind(plist, x);
	SLTInsert(&plist, pos, 40);
	SLTPrint(plist);

}

void TestSList6()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);
	SLTPrint(plist);

	int x;
	scanf("%d", &x);
	SLTNode* pos = SLTFind(plist, x);
	if (pos)
	{
		SLTInsertAfter(pos, 20);
	}
	SLTPrint(plist);
}



void TestSList7()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);
	SLTPrint(plist);

	int x;
	scanf("%d", &x);
	SLTNode* pos = SLTFind(plist, x);
	if (pos)
	{
		SLTErase(&plist, pos);
		pos = NULL;
	}
	SLTPrint(plist);

}


void TestSList8()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);
	SLTPrint(plist);

	int x;
	scanf("%d", &x);
	SLTNode* pos = SLTFind(plist, x);
	if (pos)
	{
		SLTEraseAfter(pos);
		pos = NULL;
	}
	SLTPrint(plist);

}

int main()
{
	TestSList8();
	return 0;
}

//void Swap1(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//void Swap2(int** pp1, int** pp2)
//{
//	int* tmp = *pp1;
//	*pp1 = *pp2;
//	*pp2 = tmp;
//}
//
//int main()
//{
//	TestSList2();
//
//
//	int a = 0, b = 1;
//	Swap1(&a, &b);
//
//	int* x1 = &a, *x2 = &b;
//	Swap2(&x1, &x2);
//	//Swap1(x1, x2);
//
//
//	return 0;
//}