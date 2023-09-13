#define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


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


void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%d ", root->val);
	PrevOrder(root->left);
	PrevOrder(root->right);
}


void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}


void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
}


//int size = 0;
//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	else
//		size++;
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//
//}


int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}


int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);

}


// 第k层的节点个数
int TreeKLevel(BTNode* root, int k)
{
	assert(k > 0);

	if (root == NULL)
		return 0;

	if (k == 1)
	{
		return 1;
	}

	return TreeKLevel(root->left, k - 1)
		+ TreeKLevel(root->right, k - 1);
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

	node1->left = node2;
    node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;


	PrevOrder(node1);
	printf("\n");

	InOrder(node1);
	printf("\n");

	PostOrder(node1);
	printf("\n");

	int ret1 = TreeSize(node1);
	printf("%d\n", ret1);

	//size = 0;
	int ret2 = TreeSize(node1);
	printf("%d\n", ret2);

	int ret3 = TreeLeafSize(node1);
	printf("%d\n", ret3);


	int ret4 = TreeKLevel(node1, 2);
	printf("%d\n", ret4);
}



//bool isUnivalTree(struct TreeNode* root) {
//	if (root == NULL)
//	{
//		return true;
//	}
//	if (root->left && root->left->val != root->val) {
//		return false;
//	}
//
//	if (root->right && root->right->val != root->val)
//	{
//		return false;
//	}
//
//	return  isUnivalTree(root->left) && isUnivalTree(root->right);
//
//}