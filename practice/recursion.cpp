#include <bits/stdc++.h>
using namespace std;

// Reverse An Array

// 1. Using 2 Pointers

void reverse1(int A[], int n)
{
    int i, j;
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

// 2. Using 1 Pointer

void reverse2(int A[], int n)
{
    int i;
    for (i = 0; i < n / 2; i++)
    {
        int temp = A[i];
        A[i] = A[n - 1 - i];
        A[n - 1 - i] = temp;
    }
}

// 3. Using Recursion
void reverse3(int A[], int n, int i)
{
    if (i == n / 2)
        return;
    int temp = A[i];
    A[i] = A[n - 1 - i];
    A[n - 1 - i] = temp;
    reverse3(A, n, i + 1);
}

int main()
{

    int arr[6] = {2, 3, 5, 4, 7, 8};
    int i;
    for (i = 0; i < 6; i++)
        cout << arr[i] << " ";
    cout << endl;
    reverse3(arr, 6, 0);
    for (i = 0; i < 6; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}