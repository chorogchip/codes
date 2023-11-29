

#include<bits/stdc++.h>
using namespace std;

int dp[1024];

int main() {
    int n; cin >> n;
    dp[0] = dp[2] = 1;
    for (int i = 4; i <= n; ++i)
        dp[i] = 1 ^ (dp[i-1] & dp[i-3]);
    cout << (dp[n] ? "SK" : "CY");
}