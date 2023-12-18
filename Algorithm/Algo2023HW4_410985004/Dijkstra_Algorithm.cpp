#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<vector<float>> get_graph(int n, int m)
{
    vector<vector<float>> graph(n + 1, vector<float>(n + 1, -1));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        float w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    return graph;
}

int get_min(vector<bool> &visited, vector<float> distance)
{
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < distance.size(); i++)
    {
        if (distance[i] != -1 && !visited[i] && distance[i] < min)
        {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<float>> graph = get_graph(n, m);
    int start;
    cin >> start;
    vector<int> parent(n + 1, -1);
    vector<float> distance(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    distance[start] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = get_min(visited, distance);
        visited[u] = true;
        for (int v = 0; v <= n; v++)
        {
            if (graph[u][v] != -1 && !visited[v] && graph[u][v] + distance[u] < distance[v])
            {
                parent[v] = u;
                distance[v] = graph[u][v] + distance[u];
            }
        }
    }
    parent[start] = 0;
    for (int i = 1; i < n; i++)
    {
        cout << distance[i] << " ";
    }
    cout << distance[n];
    cout << endl;
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " ";
    }
    cout << parent[n];
    cout << endl;
    return 0;
}

/*
5 9
1 2 10
1 3 3
2 3 1
2 4 2
3 2 4
3 4 8
3 5 2
4 5 7
5 4 9
1
----------------
0 7 3 9 5
0 3 1 2 3
*/