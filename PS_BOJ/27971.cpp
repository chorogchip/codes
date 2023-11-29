#include<bits/stdc++.h>
using namespace std;

int dp[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, a, b; cin >> n >> m >> a >> b;
    vector<pair<int,int>> v(m);
    for (int i = 0; i < m; ++i)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    vector<pair<int,int>> v2;
    v2.push_back({v.front().second, v.front().first});
    for (int i = 1; i < m; ++i) {
        if (v[i].first <= v[i-1].second)
            v2.back().first =
                max(v2.back().first, v[i].second);
        else v2.push_back({v[i].second, v[i].first});
    }
    const int INF = 1'0000'0000;
    for (int i = 1; i <= n; ++i) {
        dp[i] = INF;
        auto o = lower_bound(v2.begin(), v2.end(), make_pair(i, 0));
        if (o != v2.end() && o->second <= i) continue;
        if (i - a >= 0 && dp[i-a] != INF)
            dp[i] = min(dp[i], dp[i-a]+1);
        if (i - b >= 0 && dp[i-b] != INF)
            dp[i] = min(dp[i], dp[i-b]+1);
    }
    if (dp[n] == INF) dp[n] = -1;
    cout << dp[n];
}