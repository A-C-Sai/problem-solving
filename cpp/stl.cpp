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
    return 0;
}
