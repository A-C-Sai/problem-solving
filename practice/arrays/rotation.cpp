#include <bits/stdc++.h>
using namespace std;

void Rotate(vector<int> &vec)
{
    // O(n)
    int first = vec[0];
    int i;
    for (i = 1; i < vec.size(); i++)
    {
        vec[i - 1] = vec[i];
    }
    vec[vec.size() - 1] = first;
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
    Rotate(v);
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}