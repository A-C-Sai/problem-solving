#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root = nullptr;

void insert(int key)
{
    struct Node *t, *p, *q;

    if (root == nullptr)
    {
        t = new struct Node;
        t->lchild = t->rchild = nullptr;
        t->data = key;
        root = t;
        return;
    }

    p = root, q = nullptr;

    while (p)
    {
        if (p->data == key)
            return;
        else if (key < p->data)
        {
            q = p;
            p = p->lchild;
        }
        else
        {
            q = p;
            p = p->rchild;
        }
    }

    t = new struct Node;
    t->lchild = t->rchild = nullptr;
    t->data = key;
    key < q->data ? q->lchild = t : q->rchild = t;
}

void createBST(vector<int> v)
{
    for (auto i = v.begin(); i != v.end(); i++)
    {
        insert(*i);
    }
}

struct Node *rInsert(struct Node *node, int n)
{
    if (node == nullptr)
    {
        node = new struct Node;
        node->lchild = node->rchild = nullptr;
        node->data = n;
    }
    else if (n < node->data)
    {
        node->lchild = rInsert(node->lchild, n);
    }
    else if (n > node->data)
    {
        node->rchild = rInsert(node->rchild, n);
    }

    return node;
}

void inorder(struct Node *n)
{
    stack<struct Node *> st;
    while (!(n == nullptr && st.empty()))
    {
        if (n)
        {
            st.push(n);
            n = n->lchild;
        }
        else
        {
            n = st.top();
            st.pop();
            cout << n->data << " ";
            n = n->rchild;
        }
    }
    cout << endl;
}

struct Node *search(struct Node *n, int key)
{
    while (n)
    {
        if (n->data == key)
        {
            return n;
        }
        else if (key < n->data)
            n = n->lchild;
        else
            n = n->rchild;
    }
    return nullptr;
}

void rSearch(struct Node *node, int n)
{
    if (node == nullptr)
    {
        cout << "Search Unsuccessful" << endl;
        return;
    }

    if (node->data == n)
    {
        cout << "Found element" << endl;
        return;
    }
    else if (n < node->data)
        rSearch(node->lchild, n);
    else
        rSearch(node->rchild, n);
}

struct Node *inorderPredecessor(struct Node *node)
{ // right most node of left subtree
    node = node->lchild;
    while (node && node->rchild)
    {
        node = node->rchild;
    }
    return node;
}

struct Node *inorderSuccessor(struct Node *node)
{ // left most node of right subtree
    node = node->rchild;
    while (node && node->lchild)
    {
        node = node->lchild;
    }
    return node;
}

// TODO: Understand and implement deleteNode in BST
// search and delete
// replace deleted node with either inorder predecessor or inorder successor
// O(logn)
// modifications O(logn)

// TODO: generating BST from preorder or postorder
// one of BST's properties is that the inorder give the sorted order of elements
// either the preorder or postorder is enough to create a BST
// O(n)
// clue: need a stack, understand how elements are positioned (conditions which dictate their position)
// clue: in preorder root is the first element, in postorder root is the last element

int main()
{
    vector<int> vec = {8, 20, 9, 7, 2, 1, 30};
    createBST(vec);
    rSearch(root, 7);
    rSearch(root, 2);
    rSearch(root, 31);

    return 0;
}