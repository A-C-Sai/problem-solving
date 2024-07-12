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

int Delete(struct Heap *h)
{
    // O(logn)
    int maxElement = h->data[0];
    h->data[0] = h->data[h->currLength - 1];
    h->currLength--;

    int i = 0;
    while ((2 * i + 1) < h->currLength || (2 * i + 2) < h->currLength)
    {
        int flag = 1;
        if (h->data[2 * i + 1] > h->data[i])
        {
            swap(&h->data[2 * i + 1], &h->data[i]);
            i = 2 * i + 1;
            flag = 0;
        }
        else if (h->data[2 * i + 2] > h->data[i])
        {
            swap(&h->data[2 * i + 2], &h->data[i]);
            i = 2 * i + 2;
            flag = 0;
        }

        if (flag) // if the element is greater than or equal to it children it is in correct position and be exit loop
            break;
    }

    return maxElement;
}

int main()
{
    struct Heap h;
    h.currLength = 0;
    h.capacity = 10;
    h.data = new int[h.capacity];
    int arr[8] = {25, 15, 19, 12, 10, 9, 40, 32};
    createHeap(&h, arr, 8);
    cout << Delete(&h) << endl;
    cout << Delete(&h) << endl;

    int k;
    for (k = 0; k < h.currLength; k++)
    {
        cout << h.data[k] << " ";
    }
    cout << endl;
    free(h.data);

    return 0;
}