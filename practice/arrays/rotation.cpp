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

// void leftRotate(vector<int> &vec, int D)
// {
//     D = D % vec.size();
//     int temp[D];
//     for (int i = 0; i < D; i++) // O(D)
//     {
//         temp[i] = vec[i];
//     }
//     for (int j = D; j < vec.size(); j++) // O(N-D)
//     {
//         vec[j - D] = vec[j];
//     }
//     for (int k = 0; k < D; k++) // O(D)
//     {
//         vec[vec.size() - D + k] = temp[k];
//     }
// }

void leftRotate(vector<int> &vec, int D)
{
    D = D % vec.size();
    reverse(vec.begin(), vec.begin() + D);
    reverse(vec.begin() + D, vec.end());
    reverse(vec.begin(), vec.end());
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
    leftRotate(v, 6);
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}