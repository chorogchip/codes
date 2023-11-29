#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[101010][3];

int main() {
    int t; cin >> t;
    vector<int> xs(t);
    int maxx = -1;
    for (int i = 0; i < t; ++i) cin >> xs[i], maxx = max(maxx, xs[i]);
    dp[1][0] = 1; dp[1][1] = dp[1][2] = 0;
    dp[2][0] = 0; dp[2][1] = 1; dp[2][2] = 0;
    dp[3][0] = 1; dp[3][1] = 1; dp[3][2] = 1;
    const ll M = 1000000009LL;
    for (int i = 4; i <= maxx; ++i) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % M;
        dp[i][1] = (dp[i-2][0] + dp[i-2][2]) % M;
        dp[i][2] = (dp[i-3][0] + dp[i-3][1]) % M;
    }
    for (auto o : xs) {
        cout << (dp[o][0] + dp[o][1] + dp[o][2]) % M << '\n';
    }
}