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
        if (A[i] <= A[j])
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

int main()
{
    int A[6] = {1, 6, 8, 9, 10, 20};
    int B[9] = {2, 3, 4, 11, 13, 14, 15, 19, 25};
    int m = 6, n = 9;
    int *C = merging(A, B, m, n);
    for (int i = 0; i < (m + n); i++)
        cout << C[i] << " ";
    cout << endl;
    return 0;
}