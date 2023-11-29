#include <bits/stdc++.h>
using namespace std;

int dp[1024];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            int x; cin >> x;
            dp[j] = max(dp[j], dp[j-1]) + x;
        }
    cout << dp[m];
}