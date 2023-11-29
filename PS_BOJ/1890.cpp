#include <bits/stdc++.h>
using namespace std;

unsigned long long dp[128][128];

int main() {
    int n; cin >> n;
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int x; cin >> x;
            if (x == 0) continue;
            if (j + x <= n) dp[i][j + x] += dp[i][j];
            if (i + x <= n) dp[i + x][j] += dp[i][j];
        }
    cout << dp[n][n];
}