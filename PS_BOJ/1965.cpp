#include<bits/stdc++.h>
using namespace std;

int a[1010];
int dp[1010];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[1] = 1;
    int res = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = 1;
        for (int j = 1; j < i; ++j) if (a[j] < a[i])
            dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    cout << res;
}