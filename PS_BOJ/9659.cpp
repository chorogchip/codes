

#include<bits/stdc++.h>
using namespace std;

int dp[1024];

int main() {
    long long n; cin >> n;
    if (n > 1024LL) n %= 1024LL;
    dp[1] = dp[3] = 1;
    for (int i = 5; i <= n; ++i)
        dp[i] = 1 ^ (dp[i-1] & dp[i-3]);
    cout << (dp[n] ? "SK" : "CY");
}