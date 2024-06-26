#include <stdio.h>
#include <stdlib.h>

int main()
{

    int A[] = {8, 5, 7, 3, 2};
    int n = 5;

    /*
                min     max
        time    O(1)    O(n^2)
        swap    O(1)    O(n^2) --> if array is sorted in descending order

        adaptive by nature O(n)
        stable algorithm

    */

    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        temp = A[i];

        while (j > -1 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = temp;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
