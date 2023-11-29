#include<bits/stdc++.h>
using namespace std;

int d[512][512];
int dp[512][512];

int n, m;

int get(int x, int y) {
    if (x == n && y == m) return 1;
    if (dp[x][y] != -1) return dp[x][y];
    int res = 0;
    if (d[x-1][y] < d[x][y]) res += get(x-1,y);
    if (d[x+1][y] < d[x][y]) res += get(x+1,y);
    if (d[x][y-1] < d[x][y]) res += get(x,y-1);
    if (d[x][y+1] < d[x][y]) res += get(x,y+1);
    return dp[x][y] = res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    const int INF = 201010101;
    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= m; ++y) cin >> d[x][y];
    for (int x = 0; x <= n + 1; ++x) d[x][0] = d[x][m+1] = INF;
    for (int y = 0; y <= m + 1; ++y) d[0][y] = d[n+1][y] = INF;
    cout << get(1, 1);
}