#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph
{
public:
    // create unordered map to store adjacency list where pair containing a node and its list of adjacent nodes.
    // unordered_map<int, list<int>> adj;

    // void addEdge(int u, int v, bool direction)
    // {
    //     // direction - 0 => undirected graph
    //     // direction - 1 => directed graph

    //     // create edge between u and v
    //     adj[u].push_back(v);

    //     if (direction == 0)
    //     {
    //         adj[v].push_back(u);
    //     }
    // }

    // // To print the adjacency list
    // void printAdjList()
    // {
    //     for (auto i : adj)
    //     {
    //         cout << i.first << "->";
    //         // i.second is the list of adjacent nodes (neighbors)
    //         for (auto j : i.second)
    //         {
    //             cout << j << ", ";
    //             // It lists all nodes connected to the current node (i.first) in the adjacency list.
    //         }
    //         cout << endl;
    //     }
    // }

    vector<vector<int>> printAdjList(int n, int m, vector<vector<int>> &edges)
    {
        // Initialize a vector of vectors to represent adjacency list
        vector<vector<int>> ans(n);

        // Populate the adjacency list with edges
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            // Since it is an undirected graph, add each node to the other's adjacency list
            ans[u].push_back(v);
            ans[v].push_back(u);
        }

        // Prepare the final adjacency list with each node's list
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            adj[i].push_back(i); // Include the node itself
            for (int j = 0; j < ans[i].size(); j++)
            {
                adj[i].push_back(ans[i][j]);
            }
        }
        return adj;
    }
};

// int main()
// {
//     int n;
//     cout << "Enter no. of nodes: ";
//     cin >> n;

//     int m;
//     cout << "Enter no. of edges: ";
//     cin >> m;

//     Graph g;

//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         g.addEdge(u, v, 0);
//     }
//     g.printAdjList();
//     return 0;
// }

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Prepare to read edges
    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter each edge as a pair of nodes (u v):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i][0] = u;
        edges[i][1] = v;
    }

    Graph g;
    vector<vector<int>> adjList = g.printAdjList(n, m, edges);

    // Display the adjacency list
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << i << " -> ";
        for (int j = 1; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}