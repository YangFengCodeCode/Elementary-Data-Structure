#define _CRT_SECURE_NO_WARNINGS 1


//void SLTDestroy(SLTNode** pphead)
//{
//	assert(pphead);
//	SLTNode* cur = *pphead;
//	while (cur)
//	{
//	
//	}
//}




//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code here
//    struct ListNode* slow = pListHead, * fast = pListHead;
//    while (k)
//    {
//        if (fast == NULL) {
//            return NULL;
//
//        }
//        fast = fast->next;
//        k--;
//    }
//    while (fast)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow;
//}



//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        // write code here
//        struct ListNode* ihead, * itail, * ghead, * gtail;
//        ihead = itail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        ghead = gtail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        struct ListNode* cur = pHead;
//        while (cur)
//        {
//            if (cur->val < x)
//            {
//                itail->next = cur;
//                itail = itail->next;
//            }
//            else {
//
//                gtail->next = cur;
//                gtail = gtail->next;
//            }
//            cur = cur->next;
//
//        }
//
//        itail->next = ghead->next;
//        gtail->next = NULL;
//        struct ListNode* newhead = ihead->next;
//        free(ihead);
//        free(ghead);
//        pHead = newhead;
//        return pHead;
//
//
//    }
//};