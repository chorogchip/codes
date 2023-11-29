#include<bits/stdc++.h>
using namespace std;

int n;
int w[16][16];
int dp[1<<16];

const int INF = 10'0000'0000;

int getget(int i, int bit) {
    int min_cost = INF;
    bit &= ~(1<<i);
    for (int j = 0; j < n; ++j) if (bit & 1<<j)
        min_cost = min(min_cost, w[j][i]);
    return min_cost;
}

int get(int bit) {
    if (dp[bit] != INF+1) return dp[bit];
    int res = INF;
    for (int i = 0; i < n; ++i) if (bit & 1<<i) {
        res = min(res, get(bit & ~(1<<i)) + getget(i, bit));
    }
    return dp[bit] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> w[i][j];
    string str; cin >> str;
    int k; cin >> k;
    int init = 0;
    for(int i = 0; i < n; ++i)
        if (str[i] == 'Y') init |= 1<<i;
    if ( __builtin_popcount(init) >= k) {
        cout << 0;
        exit(0);
    }
    for (int i = 0; i < 1<<n; ++i) dp[i] = INF+1;
    dp[init] = 0;
    int res = INF;
    for (int i = 0; i < 1<<n; ++i)
        if (__builtin_popcount(i) == k)
            res = min(res, get(i));
    if (res == INF) cout << -1;
    else cout << res;

}