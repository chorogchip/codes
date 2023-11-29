#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

ll dp[2][64];

int pcnt(int k) {
    int res = 0;
    while (k) res += k&1, k >>= 1;
    return res;
}

int main() {
    const ll M = 1000000007;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n, k; cin >> n >> k;
        memset(dp, 0, sizeof(dp));
        dp[0][63] = 1;
        for (int i = 1; i <= n; ++i) {
            memcpy(dp[i&1], dp[(i+1)&1], sizeof(dp[0]));
            int x; cin >> x;
            for (int j = 0; j < 64; ++j)
                (dp[i&1][j&x] += dp[(i+1)&1][j]) %= M;
        }
        ll res = 0;
        for (int j = 0; j < 64; ++j) {
            int cnt = pcnt(j);
            if (cnt == k) {
                res += dp[n&1][j];
                res %= M;
            }
        }
        if (k == 6) cout << res - 1 << '\n';
        else cout << res << '\n';
    }
}
