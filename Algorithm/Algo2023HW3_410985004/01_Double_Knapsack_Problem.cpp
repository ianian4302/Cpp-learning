#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void get_cargo_data(int n, vector<int> &weight, vector<int> &volume, vector<int> &value)
{
    for (int i = 0; i < n; i++)
        cin >> value[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    for (int i = 0; i < n; i++)
        cin >> volume[i];
}
int main()
{
    // note that n <= 100, w <= 1000, v <= 1000
    int n, w, v;
    cin >> n >> w >> v;
    vector<int> weight(n, 0);
    vector<int> volume(n, 0);
    vector<int> value(n, 0);
    get_cargo_data(n, weight, volume, value);
    // Double Knapsack Problem
    vector<vector<int>> max_value(w + 1, vector<int>(v + 1, 0));
    vector<vector<vector<int>>> cargo(w + 1, vector<vector<int>>(v + 1));
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            int max = 0;
            for (int k = 1; k <= n; k++)
            {
                vector<int> temp;
                // check if the cargo can be put into the knapsack
                if (i >= weight[k - 1] && j >= volume[k - 1])
                {
                    if (max < value[k - 1] + max_value[i - weight[k - 1]][j - volume[k - 1]])
                    {
                        max = value[k - 1] + max_value[i - weight[k - 1]][j - volume[k - 1]];
                        if (i == weight[k - 1] && j == volume[k - 1])
                        {
                            temp.push_back(k);
                            cargo[i][j] = temp;
                        }
                        else
                        {
                            temp = cargo[i - weight[k - 1]][j - volume[k - 1]];
                            temp.push_back(k);
                            cargo[i][j] = temp;
                        }
                    }
                }
            }
            max_value[i][j] = max;
        }
    }
    cout << max_value[w][v] << endl;
    cout << cargo[w][v].size() << endl;
    //sort the cargo

    sort(cargo[w][v].begin(), cargo[w][v].end());

    cout << "(";
    for (int i = 0; i < cargo[w][v].size(); i++)
    {
        cout << cargo[w][v][i];
        if (i != cargo[w][v].size() - 1)
            cout << ",";
    }
    cout << ")" << endl;
}

/*
test case
4
16
10
20  30  50  10
2   5   10  5
6   7   4   8
----------------
input
4
16              capasity of weight
10              capasity of volume
20  30  50  10  value
2   5   10  5   weight
6   7   4   8   volume
-----------------
Output
70
2
(1,3)
-----------------
*/