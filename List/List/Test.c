#define _CRT_SECURE_NO_WARNINGS 1

//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* slow = head, * fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast)
//        {
//            struct ListNode* meet = slow;
//            while (meet != head)
//            {
//                meet = meet->next;
//                head = head->next;
//            }
//            return meet;
//        }
//
//    }
//    return NULL;
//}



//struct ListNode* GetSameNode(struct ListNode* headA, struct ListNode* headB)
//{
//    struct ListNode* tailA = headA;
//    struct ListNode* tailB = headB;
//    int lenA = 1, lenB = 1;
//    while (tailA)
//    {
//        tailA = tailA->next;
//        lenA++;
//    }
//    while (tailB)
//    {
//        tailB = tailB->next;
//        lenB++;
//    }
//    if (tailA != tailB)
//    {
//        return NULL;
//    }
//    int k = abs(lenA - lenB);
//    if (lenA < lenB)
//    {
//        while (k--)
//        {
//            headB = headB->next;
//        }
//    }
//    else
//    {
//        while (k--)
//        {
//            headA = headA->next;
//        }
//    }
//    while (headA != headB)
//    {
//        headA = headA->next;
//        headB = headB->next;
//    }
//    return headA;
//}
//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* slow = head, * fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast)
//        {
//            struct ListNode* meet = slow->next;
//            slow->next = NULL;
//            return GetSameNode(meet, head);
//
//        }
//
//    }
//    return NULL;
//}







#include"List.h"

//void TestList1()
//{
//	LTNode* plist = LTInit();
//	LTPushBack(plist, 1);
//	LTPushBack(plist, 2);
//	LTPushBack(plist, 3);
//	LTPushBack(plist, 4);
//	LTPushBack(plist, 5);
//	LTPrint(plist);
//
//	LTPushFront(plist, 10);
//	LTPushBack(plist, 10);
//
//	LTPrint(plist);
//}

void TestList2()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPrint(plist);

	LTPopBack(plist);
	LTPopFront(plist);
	LTPrint(plist);

	LTPopFront(plist);
	LTPopFront(plist);
	LTPopFront(plist);
	//LTPopFront(plist);
	LTPrint(plist);
}

//void TestList3()
//{
//	LTNode* plist = LTInit();
//	LTPushBack(plist, 1);
//	LTPushBack(plist, 2);
//	LTPushBack(plist, 3);
//	LTPushBack(plist, 4);
//	LTPushBack(plist, 5);
//	LTPrint(plist);
//
//	LTPushFront(plist, 10);
//	LTPushFront(plist, 20);
//	LTPushFront(plist, 30);
//	LTPushFront(plist, 40);
//	LTPrint(plist);
//}

void TestList4()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);

	LTPopBack(plist);
	LTPrint(plist);
}


void TestList5()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPrint(plist);

	LTPopBack(plist);
	LTPopFront(plist);
	LTPrint(plist);
}

void TestList6()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPrint(plist);

	LTPopFront(plist);
	LTPopFront(plist);
	LTPopFront(plist);
	LTPrint(plist);
}



void TestList8()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPrint(plist);

	int x;
	scanf("%d", &x);
	LTNode* pos = LTFind(plist, x);

	LTErase(pos, 100);
	LTPrint(plist);
}
int main()
{
	TestList8();
	return 0;
}