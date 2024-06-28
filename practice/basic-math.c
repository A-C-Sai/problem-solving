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

void isPrimeBruteForce(int n)
{
    // A number which has only 2 factors i.e. 1 and itself

    int c = 1;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            c++;
    }

    c == 2 ? printf("%d Prime\n", n) : printf("%d Not Prime\n", n);
}

void isPrime(int n)
{
    int c = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            c++;
            if (n / i != i)
                c++;
        }
    }

    c == 2 ? printf("%d Prime\n", n) : printf("%d Not Prime\n", n);
}

int main()
{
    for (int i = 0; i <= 36; i++)
    {
        isPrime(i);
    }
    return 0;
}