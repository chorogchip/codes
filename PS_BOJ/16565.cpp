#include<bits/stdc++.h>
using namespace std;
const int M = 10'007;

static constexpr inline int powi(int x, int p) {
    int res = 1;
    while(p) {
        if (p & 1) res *= x, res %= M;
        x *= x; x %= M;
        p >>= 1;
    }
    return res;
}

static constexpr inline int inverse(int n) {
    return powi(n, M-2);
}

static constexpr inline int comb(int n, int k) {
    if (k < 0) return 0;
    int res = 1;
    for (int i = 1; i <= k; ++i) {
        res *= n - (i - 1);
        res %= M;
        res *= inverse(i);
        res %= M;
    }
    return res;
}

int main() {
    int n; cin >> n;
    int res = 0;
    for (int i = 1; i < 1<<13; ++i) {
        int cnt = __builtin_popcount(i);
        int com = comb(52 - 4*cnt, n - 4*cnt);
        if (cnt & 1) res += com;
        else res -= com;
        res += M;
        res %= M;
    }
    cout << res;
}