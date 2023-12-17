#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> get_graph(int n, int m)
{
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    return graph;
}

int get_min(vector<int> &key, vector<bool> &visited)
{
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < key.size(); i++)
    {
        if (key[i] != -1 && !visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void prim(int start, vector<vector<int>> &graph)
{
    int n = graph.size() - 1;
    vector<int> predecessor(n + 1, -1);
    vector<int> key(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    key[start] = 0;
    predecessor[start] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = get_min(key, visited);
        visited[u] = true;
        for (int v = 0; v <= n; v++)
        {
            if (graph[u][v] != -1 && !visited[v] && graph[u][v] < key[v])
            {
                predecessor[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << predecessor[i] << " ";
    }
    cout << endl;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += key[i];
    }
    cout << sum << endl;

    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph = get_graph(n, m);
    int start;
    cin >> start;
    prim(start, graph);
    return 0;
}

/*
8 10
1 2 15
1 4 7
1 8 10
3 4 9
4 5 12
4 6 5
5 6 6
6 7 14
6 8 8
7 8 3
1
----------------
0 1 4 1 6 4 8 6
53
*/