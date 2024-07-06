#include <bits/stdc++.h>
using namespace std;

/** Standard Template Library
 * Algorithms
 * Containers
 * Functions
 * Iterators
 */

// https://cplusplus.com/reference/stl/

int main()
{

    /* Vectors - self-managed arrays (dynamic array)
        - push_back(x) - insert the value x to the end of the vector O(1)
        - pop_back(x) - erase the last element O(1)
        - clear() - erase all elements O(n)
        - size() - returns the current size of the vector O(1)
    */

    vector<int> v;
    vector<pair<int, int>> v1;
    vector<int> v2(5);      // {0, 0, 0, 0, 0}
    vector<int> v3(5, 100); // {100, 100, 100, 100, 100}
    vector<int> v4 = {1, 2, 3, 4, 5};

    vector<int> v5(5, 2);
    vector<int> v6(v5);

    vector<int> b(2, 100);
    vector<int> c(2, -1); // {-1,-1}

    vector<int> d[50]; // Note : this is an array or 50 vectors

    v.push_back(1);
    v.push_back(2);
    cout << v[0] << " " << v.at(1) << endl; // 1 2

    v1.push_back({1, 2});

    for (vector<int>::iterator it = v4.begin(); it != v4.end(); it++)
    // end() is the iterator to a non-existent element (after the last element)
    {
        cout << *(it) << " "; // 1 2 3 4 5
    }
    cout << endl;
    for (vector<int>::reverse_iterator i = v4.rbegin(); i != v4.rend(); i++)
    {
        cout << *(i) << " "; // 5 4 3 2 1
    }
    cout << endl;
    for (auto element : v4)
    {
        cout << element << " "; // 1 2 3 4 5
    }
    cout << endl;

    v4.erase(v4.begin() + 1);             // {1,3,4,5}
    v4.erase(v4.begin(), v4.begin() + 2); // {4,5} here end is not included
    for (auto element : v4)
    {
        cout << element << " "; // 4 5
    }
    cout << endl;

    b.insert(b.begin(), 20);       // {20, 100, 100}
    b.insert(b.begin() + 1, 2, 5); // {20,5,5,100,100}
    for (auto element : b)
    {
        cout << element << " "; // 20 5 5 100 100
    }
    cout << endl;

    b.insert(b.begin() + 3, c.begin(), c.end()); // {20,5,5,-1,-1, 100,100}
    for (auto element : b)
    {
        cout << element << " "; // 20 5 5 -1 -1 100 100
    }
    cout << endl;

    cout << b.size() << endl; // 7
    b.pop_back();
    for (auto element : b)
    {
        cout << element << " "; // 20 5 5 -1 -1 100
    }
    cout << endl;
    cout << b.empty() << endl; // 0
    b.clear();

    /* sort()
        - function can be used to sort an array, vector or a string.
        - underlying sorting algo : gcc_sort; hybrid algo [quick, insertion and heap sort]
        - O(nlogn)
        - syntax: sort(start pointer,end pointer+1)
    */

    /* Pairs
        - way of creating a composite datatype composed of 2 different primitive/composite
          datatypes
        - use case : returning 2 values from a function
        - sorting arrays/vectors of pairs
        - sorting done by first element if unequal else second element
    */
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

    // Iterators behave a lot like pointers

    /* Set
        - container which keeps a unique copy of every element in sorted order.
        - NOTE: cannot access element with [] notation (random access not allowed)

        insert(x) - insert value x into set, do nothing if already present O(logn)
        erase(x) - erase the value x from set if present O(logn)
        count(x) - returncs 0 if x is not in set and 1 if c is in set O(logn)
        clear() - erase all elements O(n)
        size() - returns the current size of the set O(1)

        - set iterators offer less features than vector iterators
        - it++,it--,++it,--it --> these are valid and work in O(nlogn) time
        NOTE: it+5 or it+=2 are INVALID

        find(x) - returns iterator to element with value x. returns end() if not found O(logn)
        lower_bound(x) - returns iterator to first element which is >= x. returns end() if not found O(logn)
        upper_bound(x) - returns iterator to first element which is > x. returns end() if not found O(logn)
        erase(it) - erases the elemet with iterator it. O(logn)
    */

    /* Map
        - special array in which the indicies(keys) of elements can be negative or very big or even strings. Like python dictonaries.
        - syntax: map<key_datatype, value_datatype> m;
        Note: similar to sets where values are unique and sorted, in maps the keys are unique and sorted
        - map iterators behave similar to set iterators, but upon doing *it, instead of getting the value you get a pair of {key, value}
        - good for frequency
     */

    return 0;
}
