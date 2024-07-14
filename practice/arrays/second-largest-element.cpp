#include <bits/stdc++.h>
using namespace std;
// second largest element in the array without sorting

void SecondLargestElement(vector<int> vec) // O(n)
{
    vector<int> differences;
    int maxElement = vec[0];
    int leastDifference = INT_MIN;
    int secondLargest;
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        if ((*i) > maxElement)
            maxElement = (*i);
    }
    for (auto j = vec.begin(); j != vec.end(); j++)
    {
        differences.push_back((*j) - maxElement);
    }

    for (auto k = 0; k < differences.size(); k++)
    {
        if (differences[k] != 0 && differences[k] > leastDifference)
        {
            leastDifference = differences[k];
            secondLargest = vec[k];
        }
    }

    if (leastDifference == INT_MIN)
    {
        cout << "Second largest element doesn't exist" << endl;
    }
    else
        cout << "Second Largest: " << secondLargest << endl;
}

void SecondLargest(vector<int> vec) // O(n)
{
    int largest = vec[0];
    int secondLargest = INT_MIN;
    for (auto i = 0; i < vec.size(); i++)
    {
        if (vec[i] == largest)
        {
            continue;
        }
        else if (vec[i] > largest)
        {
            secondLargest = largest;
            largest = vec[i];
        }
        else if (vec[i] > secondLargest)
        {
            secondLargest = vec[i];
        }
    }

    if (secondLargest == INT_MIN)
    {
        cout << "Second largest element doesn't exist" << endl;
    }
    else
        cout << "Second Largest: " << secondLargest << endl;
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
    SecondLargest(v);
    return 0;
}