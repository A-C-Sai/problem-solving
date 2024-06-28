#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *A, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int k, j;
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        }

        if (k != i)
            swap(&A[i], &A[k]);
    }
}

int main()
{

    int A[] = {8, 6, 3, 2, 5, 4};
    int n = 6;
    selectionSort(A, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}