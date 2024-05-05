#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pt = int (*)[128][128];

int n;
int a[128][128], b[128][128], c[128][128];
const ll M = 1'000'000'007LL;

void mult(pt __restrict__  a, pt __restrict__  b, pt __restrict__ c) {
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
        ll sum[4] = {0, };
        int k = 0;
        for (; k + 3 < n; k += 4) {
            sum[0] += (ll)(*a)[i][k] * (ll)(*b)[k][j] % M;
            sum[1] += (ll)(*a)[i][k+1] * (ll)(*b)[k+1][j] % M;
            sum[2] += (ll)(*a)[i][k+2] * (ll)(*b)[k+2][j] % M;
            sum[3] += (ll)(*a)[i][k+3] * (ll)(*b)[k+3][j] % M;
        }
        for (; k < n; ++k)
            sum[0] += (ll)(*a)[i][k] * (ll)(*b)[k][j] % M;
        (*c)[i][j] = (sum[0] + sum[1] + sum[2] + sum[3]) % M;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k; cin >> n >> k;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
        if (i == j) b[i][j] = 1;
    }
    pt x = &a, r = &b, t = &c;
    while(k) {
        if (k & 1) {
            mult(r, x, t);
            swap(t, r);
        }
        mult(x, x, t);
        swap(t, x);
        k >>= 1;
    }
    ll res = 0;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) res += (*r)[i][j];
    cout << res % M;
}