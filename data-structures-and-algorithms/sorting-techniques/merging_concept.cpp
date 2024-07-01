#include <bits/stdc++.h>
using namespace std;

int *merging(int A[], int B[], int m, int n)
{

    // Merging 2 arrays - combining 2 sorted arrays in a single sorted array
    // Array sizes may be different, minimum 1 element in each array
    // Time : O(m+n)
    // Space : O(m+n)

    int *res = new int[m + n];

    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (A[i] <= B[j])
            res[k++] = A[i++];
        else
            res[k++] = B[j++];
    }

    for (; i < m; i++)
        res[k++] = A[i];
    for (; j < n; j++)
        res[k++] = B[j];

    return res;
}

void mergingv2(int A[], int firstArraySize, int totalSize)
{
    // merging 2 lists from a single array

    int i = 0, j = firstArraySize, k = 0;
    int res[totalSize];

    while (i < firstArraySize && j < totalSize)
    {
        if (A[i] <= A[j])
            res[k++] = A[i++];
        else
            res[k++] = A[j++];
    }

    for (; i < firstArraySize; i++)
        res[k++] = A[i];
    for (; j < totalSize; j++)
        res[k++] = A[j];

    for (int l = 0; l < totalSize; l++)
    {
        A[l] = res[l];
    }
}

int main()
{
    // int A[6] = {1, 6, 8, 9, 10, 20};
    // int B[9] = {2, 3, 4, 11, 13, 14, 15, 19, 25};
    // int m = 6, n = 9;
    // int *C = merging(A, B, m, n);
    // for (int i = 0; i < (m + n); i++)
    //     cout << C[i] << " ";
    // cout << endl;

    // int D[8] = {1, 5, 7, 4, 8, 9, 10, 12};
    // int firstArraySize = 3;
    // int totalSize = 8;
    // mergingv2(D, 3, 8);
    // for (int i = 0; i < 8; i++)
    //     cout << D[i] << " ";
    // cout << endl;

    return 0;
}