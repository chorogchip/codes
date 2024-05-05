#include<bits/stdc++.h>
using namespace std;

int d[128][128];
bool b[128][128];
int n;

void ss(int y, int x) {
    if (y == 0 || y == n+1 || x == 0 || x == n+1) return;
    b[y][x] = 1;
    if (!b[y-1][x]) ss(y-1, x);
    if (!b[y+1][x]) ss(y+1, x);
    if (!b[y][x-1]) ss(y, x-1);
    if (!b[y][x+1]) ss(y, x+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int y = 1; y <= n; ++y)
    for (int x = 1; x <= n; ++x) cin >> d[y][x];
    int res = 1;
    for (int l = 1; l <= 100; ++l) {
        memset(b, 0, sizeof(b));
        for (int y = 1; y <= n; ++y)
        for (int x = 1; x <= n; ++x)
            if (d[y][x] <= l) b[y][x] = 1;
        int s = 0;
        for (int y = 1; y <= n; ++y)
        for (int x = 1; x <= n; ++x) if (!b[y][x]) {
            ++s, ss(y, x);
        }
        res = max(res, s);
    }
    cout << res;
}