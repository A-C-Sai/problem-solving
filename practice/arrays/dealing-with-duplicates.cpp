#include <bits/stdc++.h>
using namespace std;

void findDuplicates(vector<int> vec) // O(N)
{
    int lastDuplicate = INT_MIN;
    int i;
    for (i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] == vec[i + 1] && vec[i] != lastDuplicate)
        {
            lastDuplicate = vec[i];
            cout << vec[i] << endl;
        }
    }
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
    findDuplicates(v);
    return 0;
}