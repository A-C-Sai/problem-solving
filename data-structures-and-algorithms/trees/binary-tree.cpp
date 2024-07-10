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

// void iPostorder(struct Node *node)
// {
//     stack<pair<struct Node *, bool>> st;
//     pair<struct Node *, bool> t;
//     while (!(node == nullptr && st.empty()))
//     {
//         if (node)
//         {
//             st.push({node, true});
//             node = node->lchild;
//         }
//         else
//         {
//             t = st.top();
//             st.pop();

//             if (t.second)
//             {
//                 t.second = false;
//                 st.push(t);
//                 node = t.first->rchild;
//             }
//             else
//                 cout << t.first->data << " ";
//         }
//     }
//     cout << endl;
// }

void levelOrderTraversal()
{
    queue<struct Node *> q;
    q.push(root);
    struct Node *t;
    while (!q.empty())
    {
        t = q.front();

        cout << t->data << " ";
        if (t->lchild)
            q.push(t->lchild);
        if (t->rchild)
            q.push(t->rchild);
        q.pop();
    }
}

int countNodes(struct Node *node)
{
    if (node)
    {
        return countNodes(node->lchild) + countNodes(node->rchild) + 1;
    }
    return 0;
}

int treeHeight(struct Node *node)
{
    // height of tree = # of edges in the longest path from root node to a leaf node
    // height of tree = height of root node
    // height of tree with 1 node = 0
    // runtime will we proportional to the # of nodes O(n)
    if (node == nullptr)
        return -1;
    return max(treeHeight(node->lchild), treeHeight(node->rchild)) + 1;
}

bool checkLeftSubTree(struct Node *node, int value)
{
    // performing preorder traversal of every node in the left subtree of a given node
    if (node)
    {
        if (node->data < value)
        {
            return checkLeftSubTree(node->lchild, value) && checkLeftSubTree(node->rchild, value);
        }
        return false;
    }
    return true;
}

bool checkRightSubTree(struct Node *node, int value)
{
    // performing preorder traversal of every node in the left subtree of a given node
    if (node)
    {
        if (node->data > value)
        {
            return checkRightSubTree(node->lchild, value) && checkRightSubTree(node->rchild, value);
        }
        return false;
    }
    return true;
}

bool isBST(struct Node *node) // O(n^2)
{
    // all elements in the left subtree have to be less than the current node
    // all elements in the right subtree have to be greater than the current node
    // for every node all it descendents are visited
    // TODO: inorder traversal of a BST should give us sorted list this will reduce time complexity to O(n)
    if (node == nullptr)
        return true;
    return checkLeftSubTree(node->lchild, node->data) && checkRightSubTree(node->rchild, node->data) && isBST(node->lchild) && isBST(node->rchild);
}

int main()
{
    createTree();
    isBST(root) == true ? cout << "BST" << endl : cout << "NOT BST" << endl;

    return 0;
}