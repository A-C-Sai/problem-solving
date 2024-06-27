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

int main()
{

    // extractDigitsReverseOrder(7892);
    int a = reverseNumber(8769000);
    printf("%d\n", a);

    return 0;
}