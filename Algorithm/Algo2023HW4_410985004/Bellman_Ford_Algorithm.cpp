#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> get_graph(int n, int m)
{
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    return graph;
}

bool negative_cycle(vector<vector<int>> &graph, vector<int> &distance, vector<int> &parent)
{
    for (int u = 1; u < graph.size(); u++)
    {
        for (int v = 1; v < graph.size(); v++)
        {
            if (graph[u][v] != INT_MAX && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    bool again = 1;
    cout << "Bellman-Ford Algorithm" << endl;
    while (again)
    {
        cout << "Input: n m (n: number of vertices, m: number of edges)" << endl;
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph = get_graph(n, m);
        int start;
        cin >> start;
        string no_solution = "There is a negative weight cycle in the graph";
        vector<int> distance(n + 1, INT_MAX);
        vector<int> parent(n + 1, -1);
        distance[start] = 0;
        parent[start] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int u = 1; u <= n; u++)
            {
                for (int v = 1; v <= n; v++)
                {
                    if (graph[u][v] != INT_MAX && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
                    {
                        distance[v] = distance[u] + graph[u][v];
                        parent[v] = u;
                    }
                }
            }
        }
        if (negative_cycle(graph, distance, parent))
        {
            cout << no_solution << endl;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                cout << distance[i] << " ";
            }
            cout << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << parent[i] << " ";
            }
            cout << endl;
        }
        cout << "again? (1/0)" << endl;
        cin >> again;
    }
    cout << "Bye!" << endl;
    return 0;
}

/*
Input
5 8
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 2 1
4 3 5
5 4 -3
1
Output
0 -1 2 -2 1
0 1 2 5 2
--------------------
Input
5 5
1 2 1
2 3 1
3 4 1
4 5 1
5 1 -5
1
Output
There is a negative weight cycle in the graph
*/
