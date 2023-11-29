#include<bits/stdc++.h>
using namespace std;

int l[32], j[32];
int dp[128];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> l[i];
    for (int i = 1; i <= n; ++i) cin >> j[i];
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k <= 99 - l[i]; ++k)
            dp[k] = max(dp[k], dp[k+l[i]]+j[i]);
    }
    int res = 0;
    for (int i = 0; i <= 99; ++i) res = max(res, dp[i]);
    cout << res;
}