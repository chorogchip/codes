#include <bits/stdc++.h>
using namespace std;

int dp[2][1010];

int main() {
    int n, s, m; cin >> n >> s >> m;
    dp[0][s] = 1;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        memset(&dp[i&1][0], 0, sizeof(dp[0]));
        for (int j = m; j >= x; --j) dp[i&1][j] |= dp[i&1^1][j-x];
        for (int j = 0; j <= m - x; ++j) dp[i&1][j] |= dp[i&1^1][j+x];
    }
    for (int i = m; i >= 0; --i) if (dp[n&1][i]) {
        cout << i;
        exit(0);
    }
    cout << -1;
}