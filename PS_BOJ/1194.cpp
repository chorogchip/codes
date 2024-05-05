#include<bits/stdc++.h>
using namespace std;

char d[64][64];
bool dp[64][64][64];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    queue<tuple<int,int,int>> qu;
    int n, m; cin >> n >> m;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            cin >> d[y][x];
            if (d[y][x] == '0') qu.push({y, x, 0});
        }
    }
    for (int y = 0; y <= n + 1; ++y) d[y][0] = d[y][m+1] = '#';
    for (int x = 0; x <= m + 1; ++x) d[0][x] = d[n+1][x] = '#';
    int step = 1;
    while (!qu.empty()) {
        int sz = qu.size();
        for (int i = 0; i < sz; ++i) {
            auto [y, x, flag] = qu.front(); qu.pop();
            if (dp[y][x][flag]) continue;
            dp[y][x][flag] = true;
            static const pair<int,int> adjs[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}} ;
            for (auto [yy, xx] : adjs) {
                int py = yy + y;
                int px = xx + x;
                auto& t_d = d[py][px];
                auto& t_dp = dp[py][px];
                if (t_d == '#');
                else if (t_d == '1') {
                    cout << step; exit(0);
                } else if (t_d == '.' || t_d == '0') {
                    qu.push({py, px, flag});
                } else if (t_d >= 'a') {
                    qu.push({py, px, flag | (1 << (t_d - 'a'))});
                } else {
                    if (flag & (1 << (t_d - 'A'))) qu.push({py, px, flag});
                }
            }
        }
        step++;
    }
    cout << -1;
}