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

void unsortedArrayDuplicates(vector<int> vec)
{
    // O(n^2)
    // finding and counting duplicates in unsorted array
    // Can solve the problem with hashing in O(n) but require extra memory

    int i;
    for (i = 0; i < vec.size() - 1; i++)
    {

        int j;
        int count = 1;
        if (vec[i] != INT_MIN)
        {
            for (j = i + 1; j < vec.size(); j++)
            {
                if (vec[j] == vec[i])
                {
                    count++;
                    vec[j] = INT_MIN;
                }
            }
            if (count > 1)
                cout << vec[i] << ": " << count << " times" << endl;
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
    unsortedArrayDuplicates(v);
    return 0;
}