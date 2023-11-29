#include <bits/stdc++.h>
using namespace std;

int dp[2048][2048];
int a[101010];
int n;

int calc(int s, int e) {
    if (dp[s][e]) return dp[s][e];
    if (s == e) return 3;
    if (s + 1 == e) return (a[s] == a[e]) | 2;
    return dp[s][e] = calc(s+1, e-1) & ((a[s] == a[e]) | 2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int m; cin >> m;
    for (int i = 1; i <= m; ++i) {
        int s, e; cin >> s >> e;
        cout << (calc(s, e) & 1) << '\n';
    }
}