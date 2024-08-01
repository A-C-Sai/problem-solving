#include <bits/stdc++.h>
using namespace std;

vector<int> Union(vector<int> &arr1, vector<int> &arr2)
{
    // union of two sorted arrays
    // 2 pointer approach
    // returns union of two arrays in sorted order
    // O(m+n)

    vector<int> unionArr;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            if (unionArr.size() != 0 && unionArr.back() == arr1[i])
                i++;
            else
                unionArr.push_back(arr1[i++]);
        }
        else if (arr2[j] < arr1[i])
        {
            if (unionArr.size() != 0 && unionArr.back() == arr2[j])
                j++;
            else
                unionArr.push_back(arr2[j++]);
        }
    }

    for (; i < arr1.size(); i++)
        unionArr.push_back(arr1[i]);
    for (; j < arr2.size(); j++)
        unionArr.push_back(arr2[j]);

    return unionArr;
}

int main()
{
    int a, b, x;
    cin >> a >> b;
    vector<int> arr1, arr2;
    for (int i = 0; i < a; i++)
    {
        cin >> x;
        arr1.push_back(x);
    }
    for (int j = 0; j < b; j++)
    {
        cin >> x;
        arr2.push_back(x);
    }

    for (auto e : Union(arr1, arr2))
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}