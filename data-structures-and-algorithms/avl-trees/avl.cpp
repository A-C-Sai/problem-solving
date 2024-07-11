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

struct Node *LLrotation(struct Node *node)
{
    struct Node *p = node->lchild;
    node->lchild = p->rchild;
    p->rchild = node;
    p->balanceFactor = nodeHeight(p->lchild) - nodeHeight(p->rchild);
    p->rchild->balanceFactor = nodeHeight(p->rchild->lchild) - nodeHeight(p->rchild->rchild);

    if (node == root)
        root = p;
    return p;
}

struct Node *RRrotation(struct Node *node)
{
    struct Node *p = node->rchild;
    node->rchild = p->lchild;
    p->lchild = node;
    p->balanceFactor = nodeHeight(p->lchild) - nodeHeight(p->rchild);
    p->lchild->balanceFactor = nodeHeight(p->lchild->lchild) - nodeHeight(p->lchild->rchild);
    if (node == root)
        root = p;
    return p;
}

struct Node *LRrotation(struct Node *node)
{
    struct Node *p = node->lchild->rchild;
    struct Node *pl = p->lchild;
    struct Node *pr = p->rchild;
    p->lchild = node->lchild;
    p->rchild = node;
    node->lchild->rchild = pl;
    node->lchild = pr;
    p->balanceFactor = nodeHeight(p->lchild) - nodeHeight(p->rchild);
    p->lchild->balanceFactor = nodeHeight(p->lchild->lchild) - nodeHeight(p->lchild->rchild);
    p->rchild->balanceFactor = nodeHeight(p->rchild->lchild) - nodeHeight(p->rchild->rchild);

    if (node == root)
        root = p;
    return p;
}

struct Node *RLrotation(struct Node *node)
{
    struct Node *p = node->rchild->lchild;
    struct Node *pl = p->lchild;
    struct Node *pr = p->rchild;
    p->lchild = node;
    p->rchild = node->rchild;
    node->rchild->lchild = pr;
    node->rchild = pl;
    p->balanceFactor = nodeHeight(p->lchild) - nodeHeight(p->rchild);
    p->lchild->balanceFactor = nodeHeight(p->lchild->lchild) - nodeHeight(p->lchild->rchild);
    p->rchild->balanceFactor = nodeHeight(p->rchild->lchild) - nodeHeight(p->rchild->rchild);

    if (node == root)
        root = p;
    return p;
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
        return LLrotation(node);
    }
    else if (node->balanceFactor == -2 && node->rchild->balanceFactor == -1)
    { // RR rotation
        return RRrotation(node);
    }
    else if (node->balanceFactor == 2 && node->lchild->balanceFactor == -1)
    { // LR rotation
        return LRrotation(node);
    }
    else if (node->balanceFactor == -2 && node->rchild->balanceFactor == 1)
    { // RL rotation
        return RLrotation(node);
    }

    return node;
}

int main()
{
    int arr[14] = {67, 50, 45, 30, 25, 39, 58, 22, 79, 5, 4, 3, 70, 37};
    for (int i = 0; i < 14; i++)
    {
        if (root == nullptr)
        {
            root = Insert(root, arr[i]);
        }
        else
            Insert(root, arr[i]);
    }

    cout << nodeHeight(root) << endl;
    return 0;
}

// TODO: Deletion from AVL tree, study and implement
// Use recursive function
// need to make sure tree is balanced after deletion of node, perform rotations if necessary