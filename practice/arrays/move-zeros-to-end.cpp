#include <bits/stdc++.h>
using namespace std;

void MoveToEnd(vector<int> &vec)
{

    // for (int i = vec.size() - 1; i >= 0; i--)
    // {
    //     if (vec[i] == 0)
    //     {
    //         for (int j = i; j < vec.size() - 1; j++)
    //         {
    //             if (vec[j + 1] != 0)
    //             {
    //                 int temp = vec[j];
    //                 vec[j] = vec[j + 1];
    //                 vec[j + 1] = temp;
    //             }
    //         }
    //     }
    // }

    int i = -1; // index of zero element
    for (int j = 0; j < vec.size(); j++)
    {
        if (vec[j] == 0)
        {
            i = j;
            break;
        }
    }
    for (int j = i + 1; j < vec.size(); j++)
    {
        if (vec[j] != 0)
        {
            vec[i] = vec[j];
            vec[j] = 0;
            i++;
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
    MoveToEnd(v);
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}