#include<bits/stdc++.h>
using namespace std;

bool notgo[128];
int dp[128][128];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    while(m--){int x; cin >> x; notgo[x]=1;}
    int INF = 1'000'000;
    for (int i = 0; i <= n+5; ++i) 
    for (int j = 0; j <= n+3; ++j) dp[i][j] = INF;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (notgo[i]) {
            for (int j = 0; j <= n; ++j) dp[i][j] = min(dp[i][j], dp[i-1][j]);
        } else {
            for (int j = 0; j <= n; ++j)
                dp[i][j] = min(dp[i][j], dp[i-1][j+3]);
            for (int j = 0; j <= n; ++j)
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 10);
            for (int j = 1; j <= n; ++j)
                dp[i+2][j] = min(dp[i+2][j], dp[i-1][j-1] + 25);
            for (int j = 2; j <= n; ++j)
                dp[i+4][j] = min(dp[i+4][j], dp[i-1][j-2] + 37);
        }

        //cout << i << ':' << ' ';
        //for (int j = 0; j < 5; ++j) cout << dp[i][j] << ' '; cout << '\n';
    }
    int res = INF;
    for (int i = n; i <= n + 4; ++i)
    for (int j = 0; j <= n; ++j) res = min(res, dp[i][j]);
    cout << res*1000;
}