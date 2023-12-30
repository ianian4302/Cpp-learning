#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
        return a[2] < b[2];
    return a[1] < b[1];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> activity(n, vector<int>(3, 0));
    // 0->index
    // 1->start time
    // 2->end time
    int index = 0;
    int start = 1;
    int end = 2;
    for (int i = 0; i < n; i++)
        activity[i][0] = i + 1;
    for (int i = 0; i < n; i++)
        cin >> activity[i][1];
    for (int i = 0; i < n; i++)
        cin >> activity[i][2];
    sort(activity.begin(), activity.end(), cmp);
    vector<int> ans;
    int time = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (activity[i][end] <= time)
        {
            time = activity[i][start];
            ans.push_back(activity[i][index]);
        }
    }

    for (auto x : activity)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << endl;
    for (auto x : ans)
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

// bool compare(vector<int> &a, vector<int> &b)
// {
//     if (a[0] == b[0])
//         return a[1] < b[1];
//     return a[0] > b[0];
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<vector<int>> activity(n, vector<int>(3, 0));
//     vector<int> ans;
//     for (int i = 0; i < n; i++)
//         cin >> activity[i][0];
//     for (int i = 0; i < n; i++)
//         cin >> activity[i][1];
//     for (int i = 0; i < n; i++)
//         activity[i][2] = i + 1;
//     sort(activity.begin(), activity.end());
//     //cout activity
//     // for (int i = 0; i < n; i++)
//     // {
//     //     cout << activity[i][0] << " " << activity[i][1] << " " << activity[i][2] << endl;
//     // }

//     int time = INT_MAX;
//     for (int i = activity.size() - 1; i >= 0; i--)
//     {
//         if (activity[i][1] <= time)
//         {
//             time = activity[i][0];
//             ans.push_back(activity[i][2]);
//         }
//     }
//     sort(ans.begin(), ans.end());
//     cout << ans.size() << endl;

//     cout << "(";
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i];
//         if (i != ans.size() - 1)
//             cout << ",";
//     }
//     cout << ")" << endl;

//     return 0;
// }

// /*
// test case
// 11
// 1   3   0   5   3   5   6   8   8   9   12
// 4   5   6   7   8   9   10  11  12  13  14

// ----------------
// Input
// 11
// 1   2   3   4   5   6   7   8   9   10  11
// ----------------------------------------------
// 1   3   0   5   3   5   6   8   8   9   12
// 4   5   6   7   8   9   10  11  12  13  14
// Output
// 4
// (2,4,9,11)
// */
