#include <bits/stdc++.h>
using namespace std;

void LargestElement(vector<int> vec) // O(n)
{
    int maxElement = vec[0];
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        if ((*i) > maxElement)
            maxElement = (*i);
    }
    cout << "Max Element: " << maxElement << endl;
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
    LargestElement(v);
    return 0;
}