#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    int balanceFactor;
    struct Node *rchild;
};

struct Node *root = nullptr;

int nodeHeight(struct Node *node)
{
    if (node == nullptr)
        return 0;
    return max(nodeHeight(node->lchild), nodeHeight(node->rchild)) + 1;
}

struct Node *Insert(struct Node *node, int value)
{
    if (node == nullptr)
    {
        struct Node *t = new struct Node;
        t->lchild = t->rchild = nullptr;
        t->data = value;
        t->balanceFactor = 0;
        return t;
    }
    if (value < node->data)
    {
        node->lchild = Insert(node->lchild, value);
    }
    else if (value > node->data)
    {
        node->rchild = Insert(node->rchild, value);
    }
    node->balanceFactor = nodeHeight(node->lchild) - nodeHeight(node->rchild);

    if (node->balanceFactor == 2 && node->lchild->balanceFactor == 1)
    { // LL rotation
        root = node->lchild;
        root->rchild == nullptr ? node->lchild = nullptr : node->lchild = root->rchild;
        root->rchild = node;
        node->balanceFactor = nodeHeight(node->lchild) - nodeHeight(node->rchild);
        root->balanceFactor = nodeHeight(root->lchild) - nodeHeight(root->rchild);
    }
    else if (node->balanceFactor == -2 && node->lchild->balanceFactor == -1)
    { // RR rotation
        root = node->rchild;
        root->lchild == nullptr ? node->rchild = nullptr : node->rchild = root->lchild;
        root->lchild = node;
        node->balanceFactor = nodeHeight(node->lchild) - nodeHeight(node->rchild);
        root->balanceFactor = nodeHeight(root->lchild) - nodeHeight(root->rchild);
    }
    else if (node->balanceFactor == 2 && node->lchild->balanceFactor == -1)
    { // LR rotation
        root = node->lchild->rchild;
        root->lchild == nullptr ? node->lchild->rchild = nullptr : node->lchild->rchild = root->lchild;
        root->lchild = node->lchild;
        root->rchild == nullptr ? node->lchild = nullptr : node->lchild = root->rchild;
        root->rchild = node;
        root->balanceFactor = nodeHeight(root->lchild) - nodeHeight(root->rchild);
        root->lchild->balanceFactor = nodeHeight(root->lchild->lchild) - nodeHeight(root->lchild->rchild);
        root->rchild->balanceFactor = nodeHeight(root->rchild->lchild) - nodeHeight(root->rchild->rchild);
    }

    return node;
}

int main()
{
    int arr[3] = {30, 20, 10};
    for (int i = 0; i < 3; i++)
    {
        if (root == nullptr)
        {
            root = Insert(root, arr[i]);
        }
        else
            Insert(root, arr[i]);
    }

    return 0;
}