#include <bits/stdc++.h>
using namespace std;

struct Heap
{
    int *data;
    int currLength;
    int capacity;
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Insert(struct Heap *h, int value) // O(log[2]n)
{
    if (h->currLength == h->capacity)
    {
        h->data = (int *)realloc(h->data, h->capacity * 2); // when full capacity is reached we will be allocated more memory
        h->capacity = h->capacity * 2;
    }
    h->data[h->currLength++] = value; // store element at next availabel position in array
    int i;
    for (i = h->currLength - 1; i > 0; i = (i - 1) / 2)
    {
        int flag = 1;
        if (h->data[(i - 1) / 2] < h->data[i]) // check if parent is smaller than newly inserted value
        {
            flag = 0;
            swap(&h->data[(i - 1) / 2], &h->data[i]); // swap
        }
        if (flag)
            break;
    }
}

void createHeap(struct Heap *h, int A[], int n) // O(nlogn)
{                                               // max heap due to condition in Insert function
    int j;
    for (j = 0; j < n; j++)
    {
        Insert(h, A[j]);
    }
}

int main()
{
    struct Heap h;
    h.currLength = 0;
    h.capacity = 10;
    h.data = new int[h.capacity];
    int arr[8] = {25, 15, 19, 12, 10, 9, 40, 32};
    int arr1[3] = {70, 2, 18};
    createHeap(&h, arr, 8);
    createHeap(&h, arr1, 3);
    int k;
    for (k = 0; k < h.currLength; k++)
    {
        cout << h.data[k] << " ";
    }
    cout << endl;
    free(h.data);

    return 0;
}