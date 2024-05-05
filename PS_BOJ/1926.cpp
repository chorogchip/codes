#include<bits/stdc++.h>
using namespace std;

int d[512][512];

int asd(int y, int x) {
    if (!d[y][x]) return 0;
    d[y][x] = 0;
    int res = 1;
    return res + asd(y-1,x) + asd(y+1,x) + asd(y,x-1) + asd(y,x+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) cin >> d[y][x];
    }
    int mx = 0, cnt = 0;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) if (d[y][x]) {
            mx = max(mx, asd(y, x));
            ++cnt;
        }
    }
    cout << cnt << '\n' << mx;
}