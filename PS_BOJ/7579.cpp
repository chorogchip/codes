#include<bits/stdc++.h>
using namespace std;

int ms[128], cs[128], dp[128 * 128];

int main() {
    int n, m; cin >> n >> m;
    int dpsz = n * 128;
    for (int i = 1; i <= n; ++i) cin >> ms[i];
    for (int i = 1; i <= n; ++i) cin >> cs[i];
    for (int i = 1; i <= n; ++i) {
        for (int cc = dpsz - cs[i]; cc >= 0; --cc) {
            dp[cc + cs[i]] = max(dp[cc + cs[i]],
                dp[cc] + ms[i]);
        }
    }
    for (int i = 0; i < dpsz; ++i)
        if (dp[i] >= m) {
            cout << i;
            exit(0);
        }
}