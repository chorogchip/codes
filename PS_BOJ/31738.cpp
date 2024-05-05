#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcdl(ll a, ll b) {
    if (b == 0) return a;
    return gcdl(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    if (n >= m) { cout << 0; exit(0); }
    ll res = 1;
    for (ll i = 1; i <= n; ++i) {
        res *= i;
        res %= m;
    }
    cout << res;
}