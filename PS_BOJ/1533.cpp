#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll r[16][16], x[16][16], tmp[16][16];
const ll M = 1'000'003LL;

void mult(const ll (&a)[16][16], const ll (&b)[16][16]) {
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
        tmp[i][j] = 0;
        for (int k = 0; k < n; ++k) {
            tmp[i][j] += a[i][k] * b[k][j] % M;
            tmp[i][j] %= M;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int s, e; ll t; cin >> n >> s >> e >> t;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char c; cin >> c;
            x[i][j] = c - '0';
        }
        r[i][i] = 1;
    }
    while(t) {
        if (t & 1) {
            mult(r, x);
            memcpy(r, tmp, sizeof(tmp));
        }
        mult(x, x);
        memcpy(x, tmp, sizeof(tmp));
        t >>= 1;
    }
    ll res = 0;
    cout << r[s][e];
}