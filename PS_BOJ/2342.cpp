#include<bits/stdc++.h>
using namespace std;

/*
1 3 2 4 1 2 0
14
*/
int dd[8][8];
int d[2][8][8];

int INF = 1'0000'0000;

inline int cst(int from, int to) {
    if (from == to) return 1;
    else if (from == 0) return 2;
    else if (abs(from - to) == 1 || abs(from - to) == 3) return 3;
    else return 4;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int i;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            dd[i][j] = INF;
    memcpy(d[0], dd, sizeof(dd));
    d[0][0][0] = 0;
    for (i = 0;;++i) {
        int x; cin >> x;
        if (x == 0) break;
        auto& src = d[i&1];
        auto& dest = d[i+1&1];
        memcpy(dest, dd, sizeof(dd));

        for (int l = 0; l <= 4; ++l) {
            for (int r = 0; r <= 4; ++r) {
                dest[l][x] = min(dest[l][x], src[l][r] + cst(r, x));
                dest[x][r] = min(dest[x][r], src[l][r] + cst(l, x));
            }
        }
        for (int j = 1; j <= 4; ++j) dest[j][j] = INF;
    }
    int ans = INF;
    for (int l = 0; l <= 4; ++l)
    for (int r = 0; r <= 4; ++r)
        ans = min(ans, d[i&1][l][r]);
    cout << ans;
}