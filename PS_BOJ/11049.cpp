#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int a[512];
ll dp[512][512];

ll solve(int l, int r) {
    if (dp[l][r]) return dp[l][r];
    if (l == r) return 0;
    ll res = 201010101;
    for (int k = 0; k < r - l; ++k)
        res = min(res, solve(l, l+k) + solve(l+k+1, r) +
            a[l] * a[l+k+1] * a[r+1]);
    return dp[l][r] = res;
}

int main() {
    int n; cin >> n; int x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cin >> x;
    }
    a[n] = x;
    cout << solve(0, n-1);
}