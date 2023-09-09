#define _CRT_SECURE_NO_WARNINGS 1

//struct Node* copyRandomList(struct Node* head) {
//    //插入新节点
//    struct Node* cur = head;
//    while (cur)
//    {
//        struct Node* next = cur->next;
//        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
//        copy->val = cur->val;
//
//        //插入
//        cur->next = copy;
//        copy->next = next;
//        cur = next;
//    }
//
//    cur = head;
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        if (cur->random == NULL)
//        {
//            copy->random = NULL;
//        }
//        else
//        {
//            copy->random = cur->random->next;
//        }
//
//        cur = copy->next;
//    }
//
//
//    //尾插
//    cur = head;
//    struct Node* copyhead = NULL, * copytail = NULL;
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        struct Node* next = copy->next;
//        if (copytail == NULL)
//        {
//            copyhead = copytail = copy;
//        }
//        else
//        {
//            copytail->next = copy;
//            copytail = copytail->next;
//        }
//        //恢复原链表
//        cur->next = next;
//        //往下走
//        cur = next;
//    }
//
//    return copyhead;
//
//}


#include "Stack.h"

void TestStack1()
{
	ST st;
	STInit(&st);
	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	STPush(&st, 5);

	while (!STEmpty(&st))
	{
		printf("%d ", STTop(&st));
		STPop(&st);
	}
	printf("\n");

	STDestroy(&st);
}

int main()
{
	TestStack1();

	return 0;
}