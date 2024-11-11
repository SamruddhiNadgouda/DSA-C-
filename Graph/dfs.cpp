#include <iostream>
#include <vector>
using namespace std;

class Graph
{
public:
    void dfs(int node, vector<int> &ans, vector<bool> &visited, vector<int> adj[])
    {
        visited[node] = true;
        ans.push_back(node);

        for (auto x : adj[node])
        {
            if (!visited[x])
            {
                dfs(x, ans, visited, adj);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, ans, visited, adj);
            }
        }
        return ans;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<int> adj[V];

    // Input the edges
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming it's an undirected graph
    }

    Graph g;

    // Get DFS traversal result
    vector<int> dfsResult = g.dfsOfGraph(V, adj);

    // Output the result
    cout << "DFS traversal of the graph: ";
    for (int i = 0; i < dfsResult.size(); i++)
    {
        cout << dfsResult[i] << " ";
    }
    cout << endl;

    return 0;
}
