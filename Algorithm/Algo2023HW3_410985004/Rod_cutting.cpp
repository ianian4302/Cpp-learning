#include <iostream>
#include <vector>
using namespace std;

void print_sticks(int max_price, int k, vector<int> &price_of_sticks, vector<vector<int>> &sticks)
{
    cout << max_price << endl;
    cout << sticks[k].size() << endl;
    for (int i = 0; i < sticks[k].size(); i++)
    {
        cout << sticks[k][i];
        if (i != sticks[k].size() - 1)
            cout << "+";
    }
    cout << "=" << k << endl;
};

void print_vector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
};

int main()
{
    // note that k <= 100;
    int k;

    // input field
    cin >> k;
    vector<int> price_of_sticks(k, 0);
    price_of_sticks[0] = 0;
    for (int i = 0; i < k; i++)
        cin >> price_of_sticks[i];

    // Rod Cutting Problem
    vector<int> max_price(k + 1, 0);
    vector<vector<int>> sticks(k + 1);
    for (int i = 1; i <= k; i++)
    {

        int max = 0;
        for (int j = 1; j <= i; j++)
        {
            vector<int> temp;
            if (max < price_of_sticks[j - 1] + max_price[i - j])
            {
                max = price_of_sticks[j - 1] + max_price[i - j];
                if (j == i)
                {
                    temp.push_back(j);
                    sticks[i] = temp;
                }
                else
                {
                    temp = sticks[i - j];
                    temp.push_back(j);
                    sticks[i] = temp;
                }
            }
        }
        max_price[i] = max;
    }
    print_sticks(max_price[k], k, price_of_sticks, sticks);

    // print all sticks
    //  for (int i = 0; i < sticks.size(); i++){
    //      cout << "sticks[" << i << "] = ";
    //      print_vector(sticks[i]);
    //  }
}

// test case
/*
10
1 5 8 9 10 17 17 20 24 30
*/
