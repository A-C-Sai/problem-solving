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

void countDuplicated(vector<int> vec) // O(n)
{
    int i;
    for (i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i + 1] == vec[i])
        {
            int j = i + 1;
            while (j < vec.size() && vec[j] == vec[i])
                j++;
            cout << vec[i] << ": " << j - i << " times" << endl;
            i = j - 1;
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
    countDuplicated(v);
    return 0;
}