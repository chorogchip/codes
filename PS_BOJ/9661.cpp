

#include<bits/stdc++.h>
using namespace std;

int dp[1024];

int main() {
    long long n; cin >> n;
    dp[1] = dp[3] = dp[4] = 1;
    for (int i = 5; i < 16; ++i)
        dp[i] = 1 ^ (dp[i-1] & dp[i-4]);
    cout << (dp[n % 5] ? "SK" : "CY");
}