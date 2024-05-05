#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1'000'000'007;
int d[301010];

ll ppooww(int n) {
    ll res = 1;
    ll p = 2;
    while(n) {
        if (n & 1) res *= p, res %= M;
        p *= p; p %= M;
        n >>= 1;
    }
    return (res + M - 1) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> d[i];
    sort(d, d + n);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += ppooww(i) * d[i]; res %= M;
        res -= ppooww(n-i-1) * d[i]; res += M; res %= M;
    }
    cout << res;
}