#include<bits/stdc++.h>
using namespace std;

char d[1024][1024];
int sd[1024][1024];
int sr[1024][1024];
int dp[1024][1024];
int n, m; 

int solve(int y, int x) {
    if (dp[y][x]) return dp[y][x];
    if (!d[y][x]) return 0;
    if (y == n || x == m) return dp[y][x] = 1;
    return dp[y][x] = min(solve(y+1, x+1), min(sd[y][x]-1, sr[y][x]-1)) + 1;
}

int main() {
    cin >> n >> m;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            cin >> d[y][x];
            d[y][x] -= '0';
        }
    }
    
    for (int y = n; y > 0; --y) {
        for (int x = m; x > 0; --x) {
            if (d[y][x]) {
                sd[y][x] = sd[y+1][x] + d[y][x];
                sr[y][x] = sr[y][x+1] + d[y][x];
            } else {
                sd[y][x] = sr[y][x] = 0;
            }
        }
    }

    int res = 0;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            int ans = solve(y, x);
            res = max(res, ans);
        }
    }
    cout << res * res;

}