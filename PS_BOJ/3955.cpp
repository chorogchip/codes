#include<bits/stdc++.h>
using namespace std;

using ll = long long;
tuple<ll, ll, ll> gcgcgcd(ll a_, ll a, ll b_, ll b, ll c, ll d) {
    ll q = c / d;
    ll r = c % d;
    if (r == 0) return make_tuple(a, b, d);
    return gcgcgcd(a, a_ - q * a, b, b_ - q * b, d, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        ll n, m; cin >> n >> m;
        auto [a, b, d] = gcgcgcd(1, 0, 0, 1, n, m);
        if (d == 1) {
            while(b > 1) b -= n;
            while (b <= 1) b += n;
            if (b > 1'000'000'000) goto IM;
            cout << b << '\n';
        } else {
            IM:
            cout << "IMPOSSIBLE\n";
        }
    }
}