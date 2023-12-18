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

int main()
{
    bool again = 1;
    cout << "Floyd-Warshall Algorithm" << endl;
    while (again)
    {
        cout << "Input: n m (n: number of vertices, m: number of edges)" << endl;
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph = get_graph(n, m);
        vector<vector<int>> distance = graph;
        for (int i = 1; i <= n; i++)
        {
            distance[i][i] = 0;
        }
        for (int k = 1; k <= n; k++)
        {
            for (int u = 1; u <= n; u++)
            {
                for (int v = 1; v <= n; v++)
                {
                    if (distance[u][k] != INT_MAX && distance[k][v] != INT_MAX && distance[u][k] + distance[k][v] < distance[u][v])
                    {
                        distance[u][v] = distance[u][k] + distance[k][v];
                    }
                }
            }
        }
        cout << "Output: distance matrix" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << "    ";
            for (int j = 1; j <= n; j++)
            {
                if (distance[i][j] == INT_MAX)
                {
                    cout << "N ";
                }
                else
                {
                    cout << distance[i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << "Again? (1: Yes, 0: No)" << endl;
        cin >> again;
    }
    return 0;
}

/*
Input
5 5
1 2 1
2 3 1
3 4 1
4 5 1
5 1 1
Output
0 1 2 3 4
4 0 1 2 3
3 4 0 1 2
2 3 4 0 1
1 2 3 4 0
範例2 :
Input
5 5
1 2 1
2 3 1
3 1 1
3 4 1
4 5 1
Output
0 1 2 3 4
2 0 1 2 3
1 2 0 1 2
N N N 0 1
N N N N 0

*/