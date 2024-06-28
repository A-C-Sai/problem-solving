#include <stdio.h>
#include <stdlib.h>

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

void printDivisors(int n)
{
    for (int i = 1; i * i <= n; i++) // O(sqrt(N))
    {
        if (n % i == 0)
        {
            printf("%d\n", i);
            if (n / i != i)
                printf("%d\n", n / i);
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

void gcd(int a, int b) // O(min(a,b))
{
    int min = a < b ? a : b;
    int gcd = 1;
    for (int i = min; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
            break;
        }
    }
    printf("%d\n", gcd);
}

/* Euclidean Algorithm

    gcd(a,b) = gcd(a-b,b) given a > b
    gcd(1,X) = 1
    gcd(X,X) = X

    gcd(a,b) = gcd(a%b,b) given a > b

*/

int euclidean(int a, int b) // O(logΦ(min(a,b)))
{

    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    return a ? a : b;
}

int rEuclidean(int a, int b)
{

    if (a == 0)
    {
        return b;
    }

    // return a > b ? euclidean(a - b, b) : euclidean(b - a, a);
    return a > b ? euclidean(a % b, b) : euclidean(b % a, a);
}

void findDivisors(int n)
{
    // find number of divisors for numbers from 1 to n
    // iterating through multiples
    // O(nlog(n)) < O(n*sqrt(n))

    int *H = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            H[j]++;
        }
    }

    for (int i = 1; i < 7; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\n");

    free(H);
}

int main()
{

    findDivisors(6);
    return 0;
}