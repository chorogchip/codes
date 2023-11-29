#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1010101];

int main() {
    int t; cin >> t;
    vector<int> x(t);
    for (int i = 0; i < t; ++i) cin >> x[i];
    int maxx = x[0];
    for (auto o : x) maxx = max(maxx, o);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= maxx; ++i)
        dp[i] = (dp[i-3] + dp[i-2] + dp[i-1]) % 1000000009LL;
    for (auto o : x) cout << dp[o] << '\n';
}