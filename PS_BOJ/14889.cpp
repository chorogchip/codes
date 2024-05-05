#include<bits/stdc++.h>
using namespace std;

int d[32][32];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int res = 1'000'000;
    for (int y = 0; y < n; ++y) for (int x = 0; x < n; ++x) cin >> d[y][x];
    for (int i = 0; i < 1 << n; ++i) {
        if (__builtin_popcount(i) != n >> 1) continue;
        int sum = 0;
        for (int j = 0; j < n; ++j) if (i & 1 << j)
        for (int k = 0; k < n; ++k) if (i & 1 << k) sum += d[j][k];
        for (int j = 0; j < n; ++j) if (!(i & 1 << j))
        for (int k = 0; k < n; ++k) if (!(i & 1 << k)) sum -= d[j][k];
        res = min(res, abs(sum));
    }
    cout << res;
}