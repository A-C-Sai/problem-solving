#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int h)
{
    int pivot = A[l]; // by changing the position of pivot we can achieve variations of quick sort
    int i = l;
    int j = h;
    while (i < j)
    {
        while (i <= h && A[i] <= pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i < j)
            swap(&A[i], &A[j]);
    }
    swap(&A[l], &A[j]);
    return j; // partitioning index
}

void quickSort(int A[], int l, int h)
{
    // Best Case - Partitioning always in middle O(nlogn)
    // Worst Case - Sorted list (assuming we choose the first element as pivot) O(n^2) --> worst time always regardless of pivot position
    // divide and conquer algorithm; recursive algo
    // Space Complexity - O(logn) to O(n) max size of stack
    if (l < h)
    {
        int j = partition(A, l, h);
        quickSort(A, l, j - 1);
        quickSort(A, j + 1, h);
    }
}

int main()
{
    int arr[] = {30, 40, 44, 20, 10, 99, 87, 65, 73, 45, 20};
    quickSort(arr, 0, 10);
    int n = 11;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}