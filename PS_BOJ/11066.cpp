#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[512];
ll s[512];
ll dp[512][512];

ll solve(int l, int r) {
    if (dp[l][r]) return dp[l][r];
    if (l == r) return 0;
    ll res = 1'0000'0000'0000'0000;
    for (int k = 0; k < r - l; ++k)
        res = min(res, solve(l, l + k) + solve(l + k + 1, r) +
            s[r] - s[l-1]);
    return dp[l][r] = res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        int k; cin >> k;
        for (int i = 1; i <= k; ++i) cin >> a[i], s[i] = s[i-1] + a[i];
        cout << solve(1, k) << '\n';
    }
}