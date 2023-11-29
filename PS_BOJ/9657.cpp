

#include<bits/stdc++.h>
using namespace std;

int dp[1024];

int main() {
    int n; cin >> n;
    dp[1] = dp[3] = dp[4] = 1;
    for (int i = 5; i <= n; ++i)
        dp[i] = 1 ^ (dp[i-1] & dp[i-3] & dp[i-4]);
    cout << (dp[n] ? "SK" : "CY");
}