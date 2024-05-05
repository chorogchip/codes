#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll M = 1'000'000'007LL;

struct MAT{ ll m[8][8]; };

MAT r = {{
    0, 1, 1, 0, 0, 0, 0, 0,
    1, 0, 1, 1, 0, 0, 0, 0,
    1, 1, 0, 1, 1, 0, 0, 0,
    0, 1, 1, 0, 1, 1, 0, 0,
    0, 0, 1, 1, 0, 1, 0, 1,
    0, 0, 0, 1, 1, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 1,
    0, 0, 0, 0, 1, 0, 1, 0,
}};
MAT res = {{
    1, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 1,
}};

MAT matmul(const MAT& a, const MAT& b) {
    MAT res; memset(&res, 0, sizeof(res));
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j) {
            ll sum = 0;
            for (int k = 0; k < 8; ++k) {
                sum += a.m[i][k] * b.m[k][j];
                sum %= M;
            }
            res.m[i][j] = sum;
        }
    return res;
}

int main() {
    int n; cin >> n;
    for (; n; n >>= 1) {
        if (n & 1) res = matmul(res, r);
        r = matmul(r, r);
    }
    cout << res.m[0][0];
}