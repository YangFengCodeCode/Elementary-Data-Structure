//void TreeDestroy(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//
//	TreeDestroy(root->left);
//	TreeDestroy(root->right);
//	free(root);
//	//root = NULL;
//}



//BTNode* TreeFind(BTNode* root, int x)
//{
//	if (root == NULL)
//		return NULL;
//
//	if (root->val == x)
//		return root;
//
//	BTNode* ret = NULL;
//	ret = TreeFind(root->left, x);
//	if (ret)
//		return ret;
//
//	ret = TreeFind(root->right, x);
//	if (ret)
//		return ret;
//
//	return NULL;
//}

//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
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
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//
//
//
//
//}


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
//    return issametree(p->left, q->left) && issametree(p->right, q->right);
//}
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (root == NULL)
//    {
//        return false;
//    }
//    if (root->val == subRoot->val)
//    {
//        if (issametree(root, subRoot))
//        {
//            return true;
//        }
//    }
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//
//}


//int TreeSize(struct TreeNode* root)
//{
//    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//void preorder(struct TreeNode* root, int* a, int* i)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    a[(*i)++] = root->val;
//    preorder(root->left, a, i);
//    preorder(root->right, a, i);
//}
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//    int n = TreeSize(root);
//    int* a = (int*)malloc(n * sizeof(int));
//    int j = 0;
//    preorder(root, a, &j);
//    *returnSize = n;
//    return a;
//}
#include<stdio.h>
#include<stdlib.h>


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

int TreeSize(BTNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

void preorder(BTNode* root, int* a, int* pi)
{
    if (root = NULL)
    {
        return;
    }
    preorder(root->left, a, pi);

    a[(*pi)++] = root->val;
    preorder(root->right, a, pi);
}
int* inorderTraversal(BTNode* root, int* returnSize) {
    int n = TreeSize(root);
    int* a = (int*)malloc(sizeof(int) * n);
    int j = 0;
    preorder(root, a, &j);

    *returnSize = n;
    return a;

}
int main()
{
    // 手动构建
    BTNode* node1 = BuyNode(1);
    BTNode* node2 = BuyNode(1);
    BTNode* node3 = BuyNode(2);
    BTNode* node4 = BuyNode(3);
    BTNode* node5 = BuyNode(4);
    

    node1->left = node2;
    node1->right = node4;
    node2->left = node3;
    node4->left = node5;
    int* a = inorderTraversal(root, );
}


void LevelOrder(BTNode* root)
{
    Que q;
    QueueInit(&q);

    if (root)
        QueuePush(&q, root);

    while (!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        printf("%d ", front->val);
        if (front->left)
            QueuePush(&q, front->left);

        if (front->right)
            QueuePush(&q, front->right);

        QueuePop(&q);
    }
    printf("\n");

    QueueDestroy(&q);
}


