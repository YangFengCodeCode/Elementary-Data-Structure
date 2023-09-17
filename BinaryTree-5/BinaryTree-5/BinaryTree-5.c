#define _CRT_SECURE_NO_WARNINGS 

//bool issametree(struct TreeNode* p, struct TreeNode* q)
//{
//    if (p == NULL && q == NULL)
//    {
//        return true;
//    }
//    if (p == NULL || q == NULL)
//    {
//        return false;
//    }
//    if (p->val != q->val)
//    {
//        return false;
//    }
//    return issametree(p->left, q->right) && issametree(p->right, q->left);
//}
//bool isSymmetric(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return false;
//    }
//
//    return issametree(root->left, root->right);
//
//
//}


//int maxDepth(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return 0;
//    }
//
//    int ret1 = maxDepth(root->left);
//    int ret2 = maxDepth(root->right);
//    return(fmax(ret1, ret2) + 1);
//
//}



#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Que;


void QueueInit(Que* pq)
{
	assert(pq);

	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QueueDestroy(Que* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QueuePush(Que* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}

	pq->size++;
}
bool QueueEmpty(Que* pq)
{
	assert(pq);

	return pq->head == NULL;
}
void QueuePop(Que* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}

	pq->size--;
}

QDataType QueueFront(Que* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

QDataType QueueBack(Que* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}



int QueueSize(Que* pq)
{
	assert(pq);

	return pq->size;
}

// 不是增删查改，学习二叉树结构
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	int val;
}BTNode;


BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	node->val = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}


// 判断二叉树是否是完全二叉树
int TreeComplete(BTNode* root)
{
	Que q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
		QueuePop(&q);

	}

	//// 已经遇到空节点，如果队列中后面的节点还有非空，就不是完全二叉树
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}

	QueueDestroy(&q);
	return true;
}


int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	return fmax(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}

int main()
{
	// 手动构建
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);
	BTNode* node8 = BuyNode(8);
	BTNode* node9 = BuyNode(9);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	node2->right = node7;
	node3->left = node8;
	node6->right = node9;

	

	printf("TreeComplete：%d\n", TreeComplete(node1));

	return 0;
}

//void InsertSort(int* a, int n)
//{
//	// [0,end]有序，把end+1位置的插入到前序序列
//	// 控制[0,end+1]有序
//	for (size_t i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		int tmp = a[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + 1] = a[end];
//			}
//			else
//			{
//				break;
//			}
//
//			--end;
//		}
//
//		a[end + 1] = tmp;
//	}
//}
//
//int main()
//{
//	int a[] = { 3,4,2,1,7,8,5 };
//	InsertSort(a, 7);
//
//	return 0;
//}


//二叉树的遍历
#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	char val;
} BTNode;
BTNode* CreatTree(char* a, int* pi) {
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;

	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->val = a[*pi];
	(*pi)++;
	root->left = CreatTree(a, pi);
	root->right = CreatTree(a, pi);
	return root;
}

void PrintInorder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	PrintInorder(root->left);
	printf("%c ", root->val);
	PrintInorder(root->right);
}
int main() {
	char arr[100];
	scanf("%s", arr);
	int i = 0;
	BTNode* root = CreatTree(arr, &i);
	PrintInorder(root);

}
