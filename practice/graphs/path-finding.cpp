#include <bits/stdc++.h>
using namespace std;

vector<int> DFS(vector<vector<int>> adj, int start, int end)
{
    // Modified DFS algorithm
    // given a connected, undirected graph, a start node S and
    // an end node E, outputs the vertices on any path between S and E
    // in reverse (E to S) i.e. backtracking

    static vector<int> visited(adj.size(), 0);
    static vector<int> path;
    visited[start] = 1;

    for (auto n : adj[start])
    {
        if (!visited[n] && !visited[end])
        {
            DFS(adj, n, end);
        }
    }

    if (visited[end] == 1)
    {
        path.push_back(start);
    }

    return path;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adj(nodes + 1);
    for (int i = 0; i < edges; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    vector<int> path(DFS(adj, 15, 11));
    reverse(path.begin(), path.end());

    for (auto node : path)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}