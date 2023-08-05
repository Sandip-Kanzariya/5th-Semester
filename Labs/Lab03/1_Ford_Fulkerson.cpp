// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>> &rgraph, int s, int t, vector<int> &parent)
{

    //
    vector<int> visited(parent.size());
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    //
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < rgraph.size(); v++)
        {
            if (visited[v] == 0 && rgraph[u][v] > 0)
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }

                q.push(v);
                visited[v] = 1;
                parent[v] = u;
            }
        }
    }
    return false;
}
int ford_fulkerson(vector<vector<int>> &graph, int s, int t)
{

    // Create
    vector<vector<int>> rgraph(graph.size(), vector<int>(graph[0].size()));

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            rgraph[i][j] = graph[i][j];
        }
    }

    // Parent
    vector<int> parent(graph.size(), -1);

    int max_flow = 0;

    while (bfs(rgraph, s, t, parent))
    {
        int path_flow = INT_MAX;

        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];

            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    return max_flow;
}
int main()
{

    int nodes = 6, edges;

    /*
    cout << "Enter Number of Node : ";
    cin >> nodes;

    cout << "Enter Number of Edges : ";
    cin >> edges;
    vector<vector<int>> graph(nodes, vector<int>(nodes));

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; // 0 based Index
        // graph[u - 1][v - 1] = w; // 1 based Index
    }

    for (auto k : graph)
    {
        for (auto l : k)
        {
            cout << l << " ";
        }
        cout << "\n";
    }
    */
    
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};

    cout << "Maximum Flow : " << ford_fulkerson(graph, 0, nodes - 1);
    return 0;
}