#include<bits/stdc++.h>
using namespace std;

int d[1024 * 1024];

int par(int i) {
    if (d[i] == i) return i;
    else return d[i] = par(d[i]);
}

int ans;

void un(int ax, int ay, int bx, int by) {
    int aa = par(ay * 1024 + ax);
    int bb = par(by * 1024 + bx);
    ans += aa != bb;
    d[aa] = bb;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int i = 1;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            d[y * 1024 + x] = y * 1024 + x;
        }
    }
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            char c; cin >> c;
            if (c == 'D') un(x, y, x, y+1);
            if (c == 'U') un(x, y, x, y-1);
            if (c == 'L') un(x, y, x-1, y);
            if (c == 'R') un(x, y, x+1, y);
        }
    }
    cout << n * m - ans;
}