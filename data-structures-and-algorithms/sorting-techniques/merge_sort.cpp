#include <bits/stdc++.h>
using namespace std;

/* 2-way Merge Sort (iterative process)

    Problem statement :
        array of n elements -> array of n lists each containing 1 element (sorted) ready to be merged

    Aim : Merge n lists into a single sorted list

    Time : In each pass, work done = merging n elements. Total # of passes = logn so, O(nlogn)

    When we merge we need a extra array


*/

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int res[h + 1];

    while (i <= mid && j <= h)
    {
        if (A[i] <= A[j])
            res[k++] = A[i++];
        else
            res[k++] = A[j++];
    }

    for (; i <= mid; i++)
        res[k++] = A[i];
    for (; j <= h; j++)
        res[k++] = A[j];

    for (i = l; i <= h; i++)
    {
        A[i] = res[i];
    }
}

void IMergeSort(int A[], int n)
{
    int p, l, h, mid, i;
    for (p = 2; p <= n; p *= 2)
    {
        for (i = 0; i + p - 1 <= n; i += p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
    }
    if (p / 2 < n) // when list size is not in powers of 2, one extra merge is required
        merge(A, 0, p / 2 - 1, n);
}

/* Recursive Merge Sort

    -> Divide and Conquer
    -> recurrence relation: T(N) = 2T(N/2)+n
    -> merging is done in post-order traversal (left-right-root)
    -> Time O(nlogn)

    Pros:
        -> large size list
        -> linked list
        -> external sorting
        -> stable

    Cons:
        -> extra space (not inplace sort)
        -> no small problem
        -> observed to take longer on smaller size lists n <= 15, we can use the help of insertion sort
        -> recursive, max stack space = logn
        -> total space O(n+logn) -> O(n)


*/

void rMergeSort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        rMergeSort(A, l, mid);
        rMergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

int main()
{
    int arr[] = {9, 7, 12, 20, 45, 3, 2, 50, 50};
    int n = 9;
    rMergeSort(arr, 0, 8);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}