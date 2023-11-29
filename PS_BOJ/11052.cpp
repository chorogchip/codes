#include <bits/stdc++.h>
using namespace std;

int dp[1024];

int main() {
    int n; cin >> n;
    int x; cin >> x;
    for (int i = 1; i <= n; ++i) dp[i] = x * i;
    for (int i = 2; i <= n; ++i) {
        int x; cin >> x;
        for (int j = 0; j < n; ++j)
            for (int k = j + i; k <= n; k += i)
                dp[k] = max(dp[k], dp[k - i] + x);
    }
    cout << dp[n];
}