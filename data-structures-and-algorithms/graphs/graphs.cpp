#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &graph, int entryNode) // O(V+2E)
{
    vector<int> visited(graph.size(), 0);
    queue<int> q; // nodes who are yet to be explored

    cout << "BFS " << "starting on Node " << entryNode << " : ";

    // initial steps
    cout << entryNode << " ";
    visited[entryNode]++;
    q.push(entryNode);

    while (!q.empty()) // visit all nodes
    {
        // explore its neighbors
        for (auto i = graph[q.front()].begin(); i != graph[q.front()].end(); i++)
        {
            if (!visited[(*i)])
            {
                cout << (*i) << " ";
                visited[(*i)]++;
                q.push((*i));
            }
        }
        q.pop();
    }
    cout << endl;
}

void DFS(vector<vector<int>> graph, int Node)
{
    static vector<int> visited(graph.size(), 0);

    cout << Node << " ";
    visited[Node]++;
    for (auto n : graph[Node])
    {
        if (!visited[n])
        {
            DFS(graph, n);
        }
    }
}

int main()
{
    int nodes, edges; // total # of nodes and edges in graph
    cin >> nodes >> edges;
    vector<vector<int>> graph(nodes + 1); // adjacency list representation of undirected graph i.e. array of vectors

    int n1, n2; // edge pair
    for (int i = 0; i < edges; i++)
    {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    int Node;
    cin >> Node;
    DFS(graph, Node);

    return 0;
}