#include<bits/stdc++.h>
using namespace std;

int d[1024][1024];
int ans[1024][1024];

int cnt(int x, int y) {
    if (d[y][x] != 0) return 0;
    d[y][x] = 2;
    int res = 1;
    res += cnt(x+1, y);
    res += cnt(x-1, y);
    res += cnt(x, y+1);
    res += cnt(x, y-1);
    return res;
}

void filll(int v, int x, int y, int cnt) {
    if (d[y][x] != 2) {
        if (d[y][x] < 0 && d[y][x] != cnt) {
            d[y][x] = cnt;
            ans[y][x] += v;
        }
        return;
    }
    d[y][x] = 3;
    filll(v, x+1, y, cnt);
    filll(v, x-1, y, cnt);
    filll(v, x, y+1, cnt);
    filll(v, x, y-1, cnt);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int y = 0; y <= n + 1; ++y) d[y][0] = d[y][m+1] = 1;
    for (int x = 0; x <= m + 1; ++x) d[0][x] = d[n+1][x] = 1;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            char c; cin >> c;
            d[y][x] = c - '0';
            ans[y][x] = d[y][x];
            d[y][x] *= -1;
        }
    }
    int k = -2;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            if (d[y][x] == 0) {
                filll(cnt(x, y), x, y, k--);
            }
        }
    }
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            cout << ans[y][x] % 10;
        }
        cout << '\n';
    }
}