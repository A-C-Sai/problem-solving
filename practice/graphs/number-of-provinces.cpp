#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> adj, int node, vector<int> &visited)
{

    visited[node] = 1;
    for (auto n : adj[node])
    {
        if (!visited[n])
        {
            DFS(adj, n, visited);
        }
    }
}

int numProvinces(vector<vector<int>> adj)
{
    // O(N) + O(V+2E)
    vector<int> visited(adj.size());
    int provinces = 0;
    for (int i = 1; i < visited.size(); i++)
    {
        if (visited[i] != 1)
        {
            provinces++;
            DFS(adj, i, visited);
        }
    }
    return provinces;
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

    cout << "Number of Provinces : " << numProvinces(adj) << endl;
    return 0;
}