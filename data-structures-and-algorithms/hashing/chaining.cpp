#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int hashFunction(int key)
{
    return key % 10;
}

void insertHelper(struct Node **chain, int key)
{
    // new node creation
    struct Node *n;
    n = new struct Node;
    n->data = key;
    n->next = nullptr;

    if (*chain == nullptr)
    {
        *chain = n;
    }
    else
    {
        struct Node *t = *chain;
        while (t->next != nullptr)
            t = t->next;
        t->next = n;
    }
}

void insert(struct Node *HT[], int key)
{
    int index = hashFunction(key);
    insertHelper(&HT[index], key);
}

void searchHelper(struct Node *chain, int key)
{
    if (chain == nullptr)
        cout << "search unsuccessful" << endl;
    else
    {
        struct Node *t = chain;
        while (t)
        {
            if (t->data == key)
            {
                cout << "key found at " << t << endl;
                return;
            }
            t = t->next;
        }
        cout << "search unsuccessful" << endl;
    }
}

void search(struct Node *HT[], int key)
{
    int index = hashFunction(key);
    searchHelper(HT[index], key);
}

int main()
{

    struct Node *hash_table[10];
    int i;

    for (i = 0; i < 10; i++)
        hash_table[i] = nullptr;

    insert(hash_table, 12);
    insert(hash_table, 122);
    insert(hash_table, 42);

    search(hash_table, 122);

    return 0;
}
