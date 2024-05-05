#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1010101][4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, b, c; cin >> n >> b >> c;
    if (b <= c) {
        ll cost = 0;
        for (ll i = 0; i < n; ++i) { ll x; cin >> x; cost += b * x;}
        cout << cost; exit(0);
    }
    ll cost = 0;
    for (ll i = 2; i <= n+1; ++i) {
        ll a; cin >> a;
        ll cnt_3 = min(a, dp[i-1][2]);
        dp[i-1][2] -= cnt_3; dp[i][3] += cnt_3; a -= cnt_3;
        cost += c * cnt_3;
        ll cnt_23 = min(a, min(dp[i-1][3], dp[i-2][1]));
        dp[i-1][3] -= cnt_23; dp[i-2][1] -= cnt_23;
        dp[i-1][2] += cnt_23; dp[i][3] += cnt_23; a -= cnt_23;
        cost += c * cnt_23;
        ll cnt_2 = min(a, dp[i-1][1]);
        dp[i-1][1] -= cnt_2; dp[i][2] += cnt_2; a -= cnt_2;
        cost += c * cnt_2;
        dp[i][1] += a;
        cost += b * a;
    }
    cout << cost;
}