#include<bits/stdc++.h>
using namespace std;

int dp[4096];
const int INF = 1'0000'0000;

int main() {
    string s; cin >> s;
    int n = s.size();
    vector<pair<int,int>> v;
    v.reserve(n * n);
    for (int i = 0; i < n; ++i) {
        for (int l = 0; l <= n/2; ++l) {
            int lc = i - l, rc = i + l;
            if (0 <= lc && rc < n && s[lc] == s[rc]) v.push_back({lc, rc + 1});
            else break;
        }
        for (int l = 1; l <= n/2; ++l) {
            int lc = i - l, rc = i + l - 1;
            if (0 <= lc && rc < n && s[lc] == s[rc]) v.push_back({lc, rc + 1});
            else break;
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= n; ++i) dp[i] = INF;
    dp[0] = 0;
    for (auto o : v) {
        auto [lc, rc] = o;
        dp[rc] = min(dp[rc], dp[lc] + 1);
    }
    cout << dp[n];
}