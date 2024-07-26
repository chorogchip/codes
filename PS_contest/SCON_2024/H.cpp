#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
ll d[501010];
ll acc[501010];

ll get_sum(int l, int r) {
    ll ret = 0;
    if (r > n) ret += acc[n];
    else if (r >= 0) ret += acc[r];
    l--;
    if (l > n) ret -= acc[n];
    else if (l >= 0) ret -= acc[l];
    return ret;
}

ll dp[501010][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    const ll INF = 1LL<<62LL;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        acc[i] = acc[i-1] + d[i];
    }
    ll res = -INF;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = max(dp[i-1][1] + d[i], dp[max(i-k, 0)][0] + get_sum(i-k+1, i));
        res = max(res, max(dp[i][0], dp[i][1]));
    }
    for (int i = n+1; i < n+k; ++i) {
        res = max(res, dp[i-k][0] + get_sum(i-k+1, i));
    }
    cout << res;
}