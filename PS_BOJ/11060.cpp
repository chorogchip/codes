#include <bits/stdc++.h>
using namespace std;

int dp[1010];

int main() {
    int n; cin >> n;
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) dp[i] = 101010101;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        for (int j = i + 1; j <= min(n, i + x); ++j) dp[j] = min(dp[j], dp[i] + 1);
    }
    cout << (dp[n] == 101010101 ? -1 : dp[n]);
}