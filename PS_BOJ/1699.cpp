#include <bits/stdc++.h>
using namespace std;

int dp[101010];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i-1] + 1;
        for (int j = 2; i - j * j >= 0; ++j)
            dp[i] = min(dp[i], dp[i-j*j]+1);
    }
    cout << dp[n];
}