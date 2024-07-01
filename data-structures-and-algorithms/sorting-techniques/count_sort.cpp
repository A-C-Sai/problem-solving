#include <bits/stdc++.h>
using namespace std;

int findMax(int A[], int n)
{
    int i;
    int maxElement = A[0];
    for (i = 1; i < n; i++)
    {
        if (A[i] > maxElement)
            maxElement = A[i];
    }
    return maxElement;
}

void countSort(int A[], int n) // O(n)
{
    int max_element = findMax(A, n);
    int *count = new int[max_element + 1];

    for (int i = 0; i < max_element + 1; i++)
    {
        count[i] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        count[A[j]]++;
    }
    int k = 0, l = 0;
    while (k < max_element + 1)
    {
        if (count[k] > 0)
        {
            A[l++] = k;
            count[k]--;
        }
        else
        {
            k++;
        }
    }

    delete[] count;
}

int main()
{

    int arr[] = {6, 8, 12, 14, 1, 3, 7, 6, 9, 2};
    int n = 10;
    countSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}