#include <bits/stdc++.h>
#include <bit>
#include <bitset>
using namespace std;

long long d[4010101];

long long sum(int i, int l, int r, int a, int b) {
    if (b < l || r < a) return 0;
    if (a <= l && r <= b) return d[i];
    int md = l + r >> 1;
    return sum(i<<1, l, md, a, b) + sum((i<<1)+1, md+1, r, a, b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, nn, m, k; cin >> n >> m >> k;
    //nn = bit_ceil((unsigned)n);
    for (int i = nn; i < nn + n; ++i) cin >> d[i];
    for (int i = nn - 1; i > 0; --i) d[i] = d[i<<1] + d[(i<<1)+1];
    for (int i = 0; i < m + k; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            b += nn - 1;
            d[b] = c;
            while (b >>= 1) d[b] = d[b<<1] + d[(b<<1)+1];
        } else {
            cout << sum(1, 1, nn, b, c) << '\n';
        }
    }
}