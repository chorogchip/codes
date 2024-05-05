#include<bits/stdc++.h>
using namespace std;

constexpr char INV = 'O' ^ '#';
constexpr int INF = 1'000'000;
char d[16][16];
char dd[16][16];

int calc() {
    int num = 0;
    for (int y = 1; y <= 9; ++y) {
        for (int x = 1; x <= 10; ++x) {
            if (dd[y][x] == 'O') {
                dd[y][x] ^= INV;
                dd[y+1][x-1] ^= INV;
                dd[y+1][x] ^= INV;
                dd[y+1][x+1] ^= INV;
                dd[y+2][x] ^= INV;
                ++num;
            }
        }
    }
    for (int x = 1; x <= 10; ++x) if (dd[10][x] == 'O') return INF;
    return num;
}

int main() {
    for (int y = 1; y <= 10; ++y)
        for (int x = 1; x <= 10; ++x) cin >> d[y][x];
    int res = INF;
    for (int i = 0; i < 1<<10; ++i) {
        memcpy(dd, d, sizeof(d));
        int cnt = 0;
        for (int j = 1; j <= 10; ++j) if (i & (1<<j-1)) {
            ++cnt;
            dd[1][j-1] ^= INV;
            dd[1][j] ^= INV;
            dd[1][j+1] ^= INV;
            dd[2][j] ^= INV;
        }
        res = min(res, cnt + calc());
    }
    if (res == INF) res = -1;
    cout << res;
}