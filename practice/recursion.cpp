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

// Check if String is palindrome or not
bool isPalindrome(string s, int i)
{
    if (i == s.length() / 2)
        return true;
    if (s[i] != s[s.length() - 1 - i])
        return false;
    return isPalindrome(s, i + 1);
}

int main()
{

    return 0;
}