// #include "iostream"
// #include "vector"

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> start_time(n, 0);
//     vector<int> end_time(n, 0);

//     for (int i = 0; i < n; i++)
//         cin >> start_time[i];
//     for (int i = 0; i < n; i++)
//         cin >> end_time[i];

//     vector<int> activity;

//     cout << activity.size() << endl;
//     cout << "(";
//     for (int i = 0; i < activity.size(); i++)
//     {
//         cout << activity[i];
//         if (i != activity.size() - 1)
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