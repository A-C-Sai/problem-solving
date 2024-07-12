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

    int i = 0, j = 2 * i + 1; // j is currently pointing to the left child
    while (j < h->currLength)
    {
        if ((j + 1 < h->currLength) && (h->data[j + 1] > h->data[j]))
            j++;
        else if (h->data[j] > h->data[i])
        {
            swap(&h->data[j], &h->data[i]);
            i = j;
            j = 2 * i + 1;
        }
        else
            break;
    }
    return maxElement;
}

void HeapSort(struct Heap *h, int Arr[], int n)
{
    // O(nlogn)
    // sort elements in ascending order
    createHeap(h, Arr, n);
    int pos = n - 1;
    for (int l = 0; l < n; l++)
    {
        h->data[pos--] = Delete(h);
    }
    h->currLength = n;
}

void displayHeap(struct Heap h)
{
    for (int i = 0; i < h.currLength; i++)
    {
        cout << h.data[i] << " ";
    }
    cout << endl;
}

int main()
{
    struct Heap h;
    h.currLength = 0;
    h.capacity = 10;
    h.data = new int[h.capacity];
    int arr[14] = {2, 70, 45, 3, 1, 0, 35, 44, 67, 89, 75, 41, 19, 14};
    HeapSort(&h, arr, 14);
    displayHeap(h);
    free(h.data);

    return 0;
}