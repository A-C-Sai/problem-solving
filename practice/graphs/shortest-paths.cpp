#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<vector<int>> adj, int node)
{
    // given a unweighted, undirected graph and a start node S
    // output the length of the shortest path from S to every
    // other node. If a node is not reachable from S, its distance
    // will be -1
    vector<int> visited(adj.size(), 0);
    queue<int> q;
    vector<int> distances(adj.size(), -1);

    visited[node] = 1;
    distances[node] = {0};
    q.push(node);

    while (!q.empty())
    {
        for (auto neighbor : adj[q.front()])
        {
            if (!visited[neighbor])
            {
                distances[neighbor] = distances[q.front()] + 1;
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
        q.pop();
    }

    return distances;
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

    int startNode = 1;
    vector<int> distances(BFS(adj, startNode));
    for (int i = 1; i < distances.size(); i++)
    {
        if (distances[i] == -1)
            cout << i << " : Not Reachable" << endl;
        else
            cout << i << " : " << distances[i] << endl;
    }
    return 0;
}