#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges; // total # of nodes and edges in graph
    cin >> nodes >> edges;
    vector<int> graph[nodes + 1]; // adjacency list representation of undirected graph i.e. array of vectors

    int n1, n2; // edge pair
    for (int i = 0; i < edges; i++)
    {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    return 0;
}