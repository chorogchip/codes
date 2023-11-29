
// 0: 진다, 지는루트로 하나라도 갈수잇으면 이긴다

#include<bits/stdc++.h>
using namespace std;

int dp[1024];

int main() {
    int n; cin >> n;
    dp[1] = dp[3] = 1;
    for (int i = 4; i <= n; ++i)
        dp[i] = 1 ^ (dp[i-1] & dp[i-3]);
    cout << (dp[n] ? "SK" : "CY");
}