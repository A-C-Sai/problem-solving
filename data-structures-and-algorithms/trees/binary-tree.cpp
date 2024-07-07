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
        cout << "Enter Left Child Value of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new struct Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.push(t);
        }
        cout << "Enter Right Child Value of " << p->data << ": ";
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

void preorder(struct Node *node) // O(n)
{
    // # of calls : n (for # of nodes) + (n+1) (for null pointers) = 2n+1
    // stack size : O(h+2) where logn <= h <= n
    if (node)
    {
        cout << node->data << " ";
        preorder(node->lchild);
        preorder(node->rchild);
    }
    cout << endl;
}

void inorder(struct Node *node) // O(n)
{
    // # of calls : n (for # of nodes) + (n+1) (for null pointers) = 2n+1
    // stack size : h+2 where logn <= h <= n
    if (node)
    {
        inorder(node->lchild);
        cout << node->data << " ";
        inorder(node->rchild);
    }
    cout << endl;
}

void postorder(struct Node *node) // O(n)
{

    if (node)
    {
        postorder(node->lchild);
        postorder(node->rchild);
        cout << node->data << " ";
    }
    cout << endl;
}

void iPreorder(struct Node *node)
{
    stack<struct Node *> st;
    while (!(node == nullptr && st.empty()))
    {
        if (node)
        {
            cout << node->data << " ";
            st.push(node);
            node = node->lchild;
        }
        else
        {
            node = st.top()->rchild;
            st.pop();
        }
    }
    cout << endl;
}

void iInorder(struct Node *node)
{
    stack<struct Node *> st;
    while (!(node == nullptr && st.empty()))
    {
        if (node)
        {
            st.push(node);
            node = node->lchild;
        }
        else
        {
            node = st.top();
            st.pop();
            cout << node->data << " ";
            node = node->rchild;
        }
    }
    cout << endl;
}

int main()
{
    createTree();
    iInorder(root);

    return 0;
}