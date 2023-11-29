#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[256][256];

int main() {
    int n,k; cin >> n >> k;
    for (int kk = 0; kk <= k; ++kk)
        dp[0][kk] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j >= 0; --j)
            for (int kk = 0; kk < k; ++kk)
                dp[i][kk+1] += dp[i-j][kk], dp[i][kk+1] %= 1'000'000'000;
    }
    cout << dp[n][k];
}