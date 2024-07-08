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

int main()
{
    vector<int> vec = {8, 20, 9, 7, 2, 1, 30};
    createBST(vec);

    return 0;
}