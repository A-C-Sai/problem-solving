#include <bits/stdc++.h>
using namespace std;

/** Standard Template Library
 * Algorithms
 * Containers
 * Functions
 * Iterators
 */

int main()
{
    pair<int, int> p = {1, 3};
    cout << "First Element: "
         << p.first
         << " "
         << "Second Element: "
         << p.second << endl;

    pair<int, pair<int, int>> nested_pairs = {1, {2, 3}};
    cout << nested_pairs.first
         << " "
         << nested_pairs.second.first
         << " "
         << nested_pairs.second.second;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};

    vector<int> v;
    // v.push_back(1);
    // v.emplace_back(2);

    vector<pair<int, int>> vec;
    // vec.push_back({1, 2});
    // vec.emplace_back(3, 4);

    vector<int> v1(5, 100); // {100, 100, 100, 100, 100}
    vector<int> v2 = {1, 2, 3, 4, 5};

    vector<int> v3(5, 2);
    vector<int> v4(v3);

    vector<int> v5(5, 0);

    cout << endl;

    cout << v2[0] << " " << v2.at(2) << endl;

    cout << v2.back() << endl;

    for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    for (vector<int>::reverse_iterator i = v2.rbegin(); i != v2.rend(); i++)
    {
        cout << *(i) << " ";
    }
    cout << endl;
    for (auto element : v2)
    {
        cout << element << " ";
    }
    cout << endl;

    v2.erase(v2.begin() + 1);             // {1,3,4,5}
    v2.erase(v2.begin(), v2.begin() + 2); // {4,5} here end is not included
    for (auto element : v2)
    {
        cout << element << " ";
    }
    cout << endl;

    vector<int> b(2, 100);
    b.insert(b.begin(), 20);       // {20, 100, 100}
    b.insert(b.begin() + 1, 2, 5); // {20,5,5,100,100}
    for (auto element : b)
    {
        cout << element << " ";
    }
    cout << endl;

    vector<int> c(2, -1);                        // {-1,-1}
    b.insert(b.begin() + 3, c.begin(), c.end()); // {20,5,5,-1,-1, 100,100}
    for (auto element : b)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << b.size() << endl; // 7
    b.pop_back();
    for (auto element : b)
    {
        cout << element << " ";
    }
    cout << endl;
    cout << b.empty() << endl;
    b.clear();

    // v1 -> {10,20}
    // v2 -> {30,40}
    // v1.swap(v2)
    // v1 -> {30,40}
    // v2 -> {10,20}

    return 0;
}
