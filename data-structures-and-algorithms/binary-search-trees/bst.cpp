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

void search(struct Node *n, int key)
{
    while (n)
    {
        if (n->data == key)
        {
            cout << key << " found" << endl;
            return;
        }
        else if (key < n->data)
            n = n->lchild;
        else
            n = n->rchild;
    }
    cout << key << " not found" << endl;
}

int main()
{
    vector<int> vec = {8, 20, 9, 7, 2, 2, 39, 40, 77, 99, 1, 30, 0, 1};
    createBST(vec);
    inorder(root);
    search(root, 1);
    search(root, 21);
    search(root, 39);
    search(root, 36);

    return 0;
}