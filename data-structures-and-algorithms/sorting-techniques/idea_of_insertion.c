#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create(int *arr, int n)
{
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = arr[0];
    struct Node *last = head;
    struct Node *t;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        last->next = t;
        last = t;
    }

    last->next = NULL;
}

int main()
{

    // inserting element in a sorted array O(1)-O(n)
    // int currLength = 7;
    // int A[8] = {2, 6, 10, 15, 20, 25, 30};
    // int b = 1;

    // int i = currLength - 1;
    // while (A[i] > b)
    // {
    //     A[i + 1] = A[i];
    //     i--;
    // }
    // A[i + 1] = b;

    // inserting elemnt in a sorted linked list
    // int n = 5;
    // int A[] = {2, 6, 10, 15, 20};
    // create(A, 5);

    // struct Node* q = NULL;
    // struct Node* p = head;
    // struct Node* t = NULL;
    // int b = 18;

    // while(p->data < b){
    //     q=p;
    //     p=p->next;
    // }

    // t = (struct Node*)malloc(sizeof(struct Node));
    // t->data = b;

    // if (q) {
    //     q->next = t;
    //     t->next = p;
    // }
    // else{
    //     t->next = head;
    //     head = t;
    // }

    // iterative procedure to free linked list
    // struct Node *temp;

    // while (head != NULL)
    // {
    //     temp = head;
    //     head = head->next;
    //     free(temp);
    // }

    return 0;
}