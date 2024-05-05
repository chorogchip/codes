#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1'000'000'000;

ll dp[128][16][16][16];

inline void asd(ll& a, ll& b) {
    a += b;
    a %= M;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= 9; ++i) dp[0][i][i][i] = 1;
    for (int i = 1; i < n; ++i) {
        for (int st = 0; st <= 9; ++st) {
            for (int fn = 0; fn <= 9; ++fn) {
                for (int num = 0; num <= 9; ++num) {
                    if (num > 0) asd(dp[i][min(st,num-1)][fn][num-1], dp[i-1][st][fn][num]);
                    if (num < 9) asd(dp[i][st][max(fn,num+1)][num+1], dp[i-1][st][fn][num]);
                }
            }
        }
    }
    ll sum = 0;
    for (int i = 0; i <= 9; ++i) sum += dp[n-1][0][9][i], sum %= M;
    cout << sum;
}