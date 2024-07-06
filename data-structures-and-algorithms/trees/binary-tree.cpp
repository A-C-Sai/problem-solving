#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root = nullptr;

void createTree()
{
    int x;
    struct Node *p, *t;

    // initial set up
    queue<struct Node *> q;
    cout << "Enter Root Value: ";
    cin >> x;
    root = new struct Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.push(root);

    while (!q.empty())
    {
        p = q.front();
        cout << "Enter Left Child Value: ";
        cin >> x;
        if (x != -1)
        {
            t = new struct Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.push(t);
        }
        cout << "Enter Right Child Value: ";
        cin >> x;
        if (x != -1)
        {
            t = new struct Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.push(t);
        }
        q.pop();
    }
}

int main()
{
    createTree();

    return 0;
}