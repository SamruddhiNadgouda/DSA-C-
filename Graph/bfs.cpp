#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
public:
    int nodes;
    vector<vector<int>> adjList;

    Graph(int n)
    {
        nodes = n;
        adjList.resize(n);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void bfs(int start)
    {
        vector<bool> visited(nodes, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int neighbors : adjList[curr])
            {
                if (!visited[neighbors])
                {
                    visited[neighbors] = true;
                    q.push(neighbors);
                }
            }
        }
    }
};

int main()
{
    Graph g(5);
    // Define edges
    g.addEdge(0, 3);
    g.addEdge(3, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 4);

    cout << "BFS traversal starting from node 0: ";
    g.bfs(0); // Perform BFS starting from node 0
    return 0;
}