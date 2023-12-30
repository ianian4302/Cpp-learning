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
bool is_in(vector<int> cargo_list, int target)
{
    for (int i = 0; i < cargo_list.size(); i++)
        if (target == cargo_list[i])
            return true;
    return false;
}
int main()
{
    int n, w, v;
    cin >> n >> w >> v;
    vector<int> weight(n, 0);
    vector<int> volume(n, 0);
    vector<int> value(n, 0);
    get_cargo_data(n, weight, volume, value);

    vector<vector<vector<int>>> cargo(w + 1, vector<vector<int>>(v + 1));
    vector<vector<int>> max_value(w + 1, vector<int>(v + 1, 0));

    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            int max = 0;
            for (int k = 0; k < n; k++)
            {
                if (i >= weight[k] && j >= volume[k])
                {
                    if (max < value[k] + max_value[i - weight[k]][j - volume[k]])
                    {
                        if (is_in(cargo[i - weight[k]][j - volume[k]], k + 1))
                            continue;
                        max = value[k] + max_value[i - weight[k]][j - volume[k]];
                        vector<int> temp;
                        if (i != weight[k] && j != volume[k])
                        {
                            temp = cargo[i - weight[k]][j - volume[k]];
                        }
                        temp.push_back(k + 1);
                        cargo[i][j] = temp;
                    }
                }
            }
            max_value[i][j] = max;
        }
    }

    cout << max_value[w][v] << endl;
    cout << cargo[w][v].size() << endl;
    sort(cargo[w][v].begin(), cargo[w][v].end());
    for (auto x : cargo[w][v])
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void get_cargo_data(int n, vector<int> &weight, vector<int> &volume, vector<int> &value)
// {
//     for (int i = 0; i < n; i++)
//         cin >> value[i];
//     for (int i = 0; i < n; i++)
//         cin >> weight[i];
//     for (int i = 0; i < n; i++)
//         cin >> volume[i];
// }

// bool is_in(int n, vector<int> &cargo)
// {
//     for (int i = 0; i < cargo.size(); i++)
//     {
//         if (n == cargo[i])
//             return true;
//     }
//     return false;
// }

// int main()
// {
//     // note that n <= 100, w <= 1000, v <= 1000
//     int n, w, v;
//     cin >> n;
//     cin >> w >> v;
//     vector<int> weight(n, 0);
//     vector<int> volume(n, 0);
//     vector<int> value(n, 0);
//     get_cargo_data(n, weight, volume, value);
//     // Double Knapsack Problem
//     vector<vector<int>> max_value(w + 1, vector<int>(v + 1, 0));
//     vector<vector<vector<int>>> cargo(w + 1, vector<vector<int>>(v + 1));
//     for (int i = 1; i <= w; i++)
//     {
//         for (int j = 1; j <= v; j++)
//         {
//             int max = 0;
//             for (int k = 1; k <= n; k++)
//             {
//                 vector<int> temp;
//                 // check if the cargo can be put into the knapsack
//                 if (i >= weight[k - 1] && j >= volume[k - 1])
//                 {
//                     if (max < value[k - 1] + max_value[i - weight[k - 1]][j - volume[k - 1]])
//                     {
//                         if (is_in(k, cargo[i - weight[k - 1]][j - volume[k - 1]]))
//                             continue;
//                         max = value[k - 1] + max_value[i - weight[k - 1]][j - volume[k - 1]];
//                         if (i == weight[k - 1] && j == volume[k - 1])
//                         {
//                             temp.push_back(k);
//                             cargo[i][j] = temp;
//                         }
//                         else
//                         {
//                             temp = cargo[i - weight[k - 1]][j - volume[k - 1]];
//                             temp.push_back(k);
//                             cargo[i][j] = temp;
//                         }
//                     }
//                 }
//             }
//             max_value[i][j] = max;
//         }
//     }
//     cout << max_value[w][v] << endl;
//     cout << cargo[w][v].size() << endl;
//     // sort the cargo

//     sort(cargo[w][v].begin(), cargo[w][v].end());

//     cout << "(";
//     for (int i = 0; i < cargo[w][v].size(); i++)
//     {
//         cout << cargo[w][v][i];
//         if (i != cargo[w][v].size() - 1)
//             cout << ",";
//     }
//     cout << ")" << endl;
// }

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