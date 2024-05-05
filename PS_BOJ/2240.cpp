#include<bits/stdc++.h>
using namespace std;

int dp[32];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t, w; cin >> t >> w;
    while(t--) {
        int x; cin >> x;
        for (int i = x; i <= w+1; i += 2)
            dp[i] = 1 + max(dp[i], dp[i-1]);
    }
    int res = 0;
    for (int i = 1; i <= w+1; ++i) res = max(res, dp[i]);
    cout << res;
}