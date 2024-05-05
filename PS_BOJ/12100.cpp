#include<bits/stdc++.h>
using namespace std;

int n;

int ans(int k, signed char (&d)[21][21], const int mx) {
#if 0
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= n; ++x) {
            cout << (int)d[y][x] << ' ';
        }
        cout << '\n';
    }cout << '\n';
#endif
    if (k == 0) return mx;
    signed char nd[21][21];
    int res = mx;
    int nmx;

    // up
    nmx = mx;
    memcpy(nd, d, sizeof(d));
    for (int y = 1; y <= n; ++y)
    for (int x = 1; x <= n; ++x) if (nd[y][x]) {
        int val = nd[y][x];
        nd[y][x] = 0;
        int yy = y;
        while (yy > 1 && nd[yy-1][x] == 0) --yy;
        if (nd[yy-1][x] == val) nd[yy-1][x]++, nmx = max(nmx, val +1);
        else nd[yy][x] = val;
    }
    res = max(res, ans(k-1, nd, nmx));
    
    // down
    nmx = mx;
    memcpy(nd, d, sizeof(d));
    for (int y = n; y >= 1; --y)
    for (int x = 1; x <= n; ++x) if (nd[y][x]) {
        int val = nd[y][x];
        nd[y][x] = 0;
        int yy = y;
        while (yy < n && nd[yy+1][x] == 0) ++yy;
        if (nd[yy+1][x] == val) nd[yy+1][x]++, nmx = max(nmx, val +1);
        else nd[yy][x] = val;
    }
    res = max(res, ans(k-1, nd, nmx));

    // left
    nmx = mx;
    memcpy(nd, d, sizeof(d));
    for (int x = 1; x <= n; ++x)
    for (int y = 1; y <= n; ++y) if (nd[y][x]) {
        int val = nd[y][x];
        nd[y][x] = 0;
        int xx = x;
        while (xx > 1 && nd[y][xx-1] == 0) --xx;
        if (nd[y][xx-1] == val) nd[y][xx-1]++, nmx = max(nmx, val +1);
        else nd[y][xx] = val;
    }
    res = max(res, ans(k-1, nd, nmx));
    
    // right
    nmx = mx;
    memcpy(nd, d, sizeof(d));
    for (int x = n; x >= 1; --x)
    for (int y = 1; y <= n; ++y) if (nd[y][x]) {
        int val = nd[y][x];
        nd[y][x] = 0;
        int xx = x;
        while (xx < n && nd[y][xx+1] == 0) ++xx;
        if (nd[y][xx+1] == val) nd[y][xx+1]++, nmx = max(nmx, val +1);
        else nd[y][xx] = val;
    }
    res = max(res, ans(k-1, nd, nmx));

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    signed char d[21][21];
    for (int y = 0; y <= n+1; ++y) d[0][y] = d[n+1][y] = d[y][0] = d[y][n+1] = -1;
    int mx = 0;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= n; ++x) {
            int asd; cin >> asd;
            if (asd == 0) d[y][x] = 0;
            else d[y][x] = 31 - __builtin_clz(asd);
            mx = max(mx, (int)d[y][x]);
        }
    }
    cout << ((1 << ans(5, d, mx)) & ~1);
}