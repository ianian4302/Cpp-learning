#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_input(int n)
{
    vector<int> price;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        price.push_back(p);
    }
    return price;
}
int main()
{
    int n;
    cin >> n;
    vector<int> price = get_input(n);
    vector<int> max_price(n + 1, 0);
    vector<vector<int>> sticks(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int max = 0;
        for (int j = 1; j <= i; j++)
        {

            if (max < price[j - 1] + max_price[i - j])
            {
                max = price[j - 1] + max_price[i - j];
                vector<int> temp;
                if (i != j)
                {
                    temp = sticks[i - j];
                }
                temp.push_back(j);
                sticks[i] = temp;
            }
        }
        max_price[i] = max;
    }
    cout << max_price[n] << endl;
    cout << sticks[n].size() << endl;
    cout << n << "=";
    sort(sticks[n].begin(), sticks[n].end());
    for (auto x : sticks[n])
        cout << x << " ";
    cout << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void print_sticks(int max_price, int k, vector<int> &price_of_sticks, vector<vector<int>> &sticks)
// {
//     cout << max_price << endl;
//     cout << sticks[k].size() << endl;
//     cout << k << "=";
//     for (int i = 0; i < sticks[k].size(); i++)
//     {
//         cout << sticks[k][i];
//         if (i != sticks[k].size() - 1)
//             cout << "+";
//     }
//   cout << endl;
// };

// void print_vector(vector<int> &v)
// {
//     for (int i = 0; i < v.size(); i++)
//         cout << v[i] << " ";
//     cout << endl;
// };

// int main()
// {
//     // note that k <= 100;
//     int k;

//     // input field
//     cin >> k;
//     vector<int> price_of_sticks(k, 0);
//     price_of_sticks[0] = 0;
//     for (int i = 0; i < k; i++)
//         cin >> price_of_sticks[i];

//     // Rod Cutting Problem
//     vector<int> max_price(k + 1, 0);
//     vector<vector<int>> sticks(k + 1);
//     for (int i = 1; i <= k; i++)
//     {
//         int max = 0;
//         for (int j = 1; j <= i; j++)
//         {
//             vector<int> temp;
//             if (max < price_of_sticks[j - 1] + max_price[i - j])
//             {
//                 max = price_of_sticks[j - 1] + max_price[i - j];
//                 if (j == i)
//                 {
//                     temp.push_back(j);
//                     sticks[i] = temp;
//                 }
//                 else
//                 {
//                     temp = sticks[i - j];
//                     temp.push_back(j);
//                     sticks[i] = temp;
//                 }
//             }
//         }
//         max_price[i] = max;
//     }
//   	sort(sticks[k].begin(), sticks[k].end());
//     print_sticks(max_price[k], k, price_of_sticks, sticks);
//   	return 0;
// }
