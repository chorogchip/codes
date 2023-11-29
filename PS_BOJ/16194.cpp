#include<bits/stdc++.h>
using namespace std;

int dp[1010];

int main() {
    int n; cin >> n;
    int x; cin >> x;
    for (int i = 1; i <= n; ++i) dp[i] = x * i;
    for (int i = 2; i <= n; ++i) {
        int x; cin >> x;
        for (int j = i; j <= n; ++j)
                dp[j] = min(dp[j], dp[j-i] + x);
    }
    cout << dp[n];
}