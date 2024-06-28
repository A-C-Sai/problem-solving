#include <stdio.h>

void extractDigitsReverseOrder(int x) // O(log10(N))
{
    while (x > 0)
    {
        printf("%d", x % 10);
        x = x / 10;
    }
    printf("\n");
}

int reverseNumber(int x)
{
    int res = 0;
    while (x > 0)
    {
        int lastDigit = x % 10;
        res = res * 10 + lastDigit;
        x = x / 10;
    }
    return res;
}

// Amstrong Numbers - numbers whose sum of cubes of each individual digit result in the original number

void printDivisors(double n)
{
    for (double i = 1; i * i <= n; i++) // O(sqrt(N))
    {
        if ((int)n % (int)i == 0)
        {
            printf("%d\n", (int)i);
            if ((int)n / (int)i != i)
                printf("%d\n", (int)n / (int)i);
        }
    }
}

int main()
{
    printDivisors(36);
    return 0;
}