#include<bits/stdc++.h>
using namespace std;

int d[512][512];
int dp[512][512];

int solve(int x, int y) {
    if (dp[y][x]) return dp[y][x];
    int res = 0;
    if (d[y-1][x] > d[y][x]) res = max(res, solve(x, y-1));
    if (d[y+1][x] > d[y][x]) res = max(res, solve(x, y+1));
    if (d[y][x-1] > d[y][x]) res = max(res, solve(x-1, y));
    if (d[y][x+1] > d[y][x]) res = max(res, solve(x+1, y));
    return dp[y][x] = res + 1;
}

int main() {
    int n; cin >> n;
    for (int y = 1; y <= n; ++y)
        for (int x = 1; x <= n; ++x)
            cin >> d[y][x];
    int res = 0;
    for (int y = 1; y <= n; ++y)
        for (int x = 1; x <= n; ++x)
            res = max(res, solve(x, y));
    cout << res;
}