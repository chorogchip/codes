#include<bits/stdc++.h>
using namespace std;

int dp[2][20101];
int a[32];

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        cin >> m;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) dp[i&1][j] = 0;
            for (int j = 0; j <= m; ++j) {
                for (int k = j; k <= m; k += a[i]) {
                    dp[i&1][k] += dp[i&1^1][j];
                }
            }
        }
        cout << dp[n&1][m] << '\n';
    }
}