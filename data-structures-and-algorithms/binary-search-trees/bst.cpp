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
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
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
{
    // left most node of right subtree; minimim in right subtree
    // TODO: What if give node doesnt have a right subtree, implement later

    node = node->rchild;
    while (node && node->lchild)
    {
        node = node->lchild;
    }
    return node;
}

struct Node *inorderSuccessorV2(struct Node *node, int key)
{

    struct Node *successor = nullptr;
    struct Node *addrKey = search(node, key);

    if (addrKey)
    {
        if (addrKey->rchild)
        {
            successor = addrKey->rchild;
            while (successor && successor->lchild)
            {
                successor = successor->lchild;
            }
        }
        else
        {
            struct Node *ancestor = root;
            while (ancestor != addrKey)
            {
                if (key < ancestor->data)
                {
                    successor = ancestor;
                    ancestor = ancestor->lchild;
                }
                else
                    ancestor = ancestor->rchild;
            }
        }
    }
    return successor;
}

// Logic:
// Min element : left most element of left subtree
// Max element : right most element of right subtree

// TODO: try to implement recursive deleteNode in BST but the current approach seems more intuitive and consumes less stack space

bool degree0(struct Node *node)
{ // check if node is a leaf node
    return node->lchild == node->rchild;
}
bool degree1(struct Node *node)
{ // check if node has only one child
    return (node->lchild && node->rchild == nullptr) || (node->rchild && node->lchild == nullptr);
}
bool degree2(struct Node *node)
{ // check if node has 2 children
    return node->lchild && node->rchild;
}

void deleteNode(struct Node *node, int value)
{
    // search and delete
    // replace deleted node with either inorder predecessor or inorder successor
    // O(logn) - search for key and inorder successor
    // stack size O(1), 1st call is call to delete specified node, 2nd call to delete inorder successor

    struct Node *p = node, *q = nullptr;
    while (p && p->data != value) // p will try to find the node of interest, q will be the tailing pointer to its parent
    {
        q = p;
        if (value < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }

    if (p)
    {
        if (degree0(p))
        {
            p->data < q->data ? q->lchild = nullptr : q->rchild = nullptr;
            free(p);
        }
        else if (degree1(p))
        {
            if (p->lchild)
            {
                p->data < q->data ? q->lchild = p->lchild : q->rchild = p->lchild;
            }
            else
            {
                p->data < q->data ? q->lchild = p->rchild : q->rchild = p->rchild;
            }
            free(p);
        }
        else
        {
            // if node to be deleted has has 2 children replace it with the inorder successor
            // Inorder successor has children = {0,1} i.e. trivial problem
            int t = inorderSuccessor(p)->data; // store inorder successor data
            deleteNode(root, t);               // delete inorder successor first
            p->data = t;                       // replace current node data with inorder successor data
        }
    }
}

// TODO: generating BST from preorder or postorder
// one of BST's properties is that the inorder give the sorted order of elements
// either the preorder or postorder is enough to create a BST
// O(n)
// clue: need a stack, understand how elements are positioned (conditions which dictate their position)
// clue: in preorder root is the first element, in postorder root is the last element

int main()
{
    vector<int> vec;
    vec.push_back(8);
    vec.push_back(20);
    vec.push_back(9);
    vec.push_back(7);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(30);
    vec.push_back(25);
    vec.push_back(79);
    vec.push_back(32);
    vec.push_back(14);
    vec.push_back(26);
    vec.push_back(5);
    createBST(vec);
    for (int i = 0; i < vec.size(); i++)
    {
        struct Node *n = inorderSuccessorV2(root, vec[i]);
        n == nullptr ? cout << vec[i] << " Maximum element in the tree" << endl : cout << vec[i] << " " << n->data << endl;
    }

    return 0;
}
