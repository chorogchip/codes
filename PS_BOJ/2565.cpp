#include<bits/stdc++.h>
using namespace std;

int dp[128];

int main() {
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) if (v[j].second < v[i].second)
            dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    cout << n - res;
}