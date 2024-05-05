#include<bits/stdc++.h>
using namespace std;

int n, m;
char d[1024][1024];
int px, py;

int asd(int x, int y) {
    if (d[y][x] == 'O' || d[y][x] == 'I' || d[y][x] == 'P') {
        int res = (d[y][x] == 'P');
        d[y][x] = 'V';
        return res + asd(x+1, y) + asd(x-1, y) + asd(x, y+1) + asd(x, y-1);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int x = 0; x <= m + 1; ++x) d[0][x] = d[n+1][x] = 'X';
    for (int y = 0; y <= n + 1; ++y) d[y][0] = d[y][m+1] = 'X';
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            cin >> d[y][x];
            if (d[y][x] == 'I') px=x, py=y;
        }
    }
    int res = asd(px, py);
    if (res == 0) cout << "TT";
    else cout << res;
}