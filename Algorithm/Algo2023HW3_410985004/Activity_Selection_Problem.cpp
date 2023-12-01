#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;

    vector<int> s(n, 0);
    vector<int> f(n, 0);

    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        cin >> f[i];
    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        v.push_back({s[i], f[i], i+1});
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    int prev=v[v.size()-1][0];
        ans.push_back(v[v.size()-1][2]);
        for(int i=v.size()-1;i>=0;i--)
        {
            if(prev>=v[i][1]){
                prev=v[i][0];
                ans.push_back(v[i][2]);
            }
        }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    cout << "(";
    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
        if(i < ans.size()-1)
            cout <<",";
    }
    cout << ")";
    return 0;
}
