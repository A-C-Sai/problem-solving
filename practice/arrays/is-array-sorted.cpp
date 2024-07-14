#include <bits/stdc++.h>
using namespace std;

void isSorted(vector<int> vec)
{
    // checks if array is sorted is ascending order
    // O(N)
    int i;
    for (i = 1; i < vec.size(); i++)
    {
        if (vec[i - 1] > vec[i])
        {
            cout << "Array is not sorted" << endl;
            return;
        }
    }
    cout << "Array is sorted" << endl;
}

int main()
{
    vector<int> v;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    while (ss >> num)
    {
        v.push_back(num);
    }
    isSorted(v);
    return 0;
}