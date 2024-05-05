#include<bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll,ll> v[201010];
ll s[201010];
ll c[201010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> v[i].second >> v[i].first;
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; ++i)
        s[i] = s[i-1] + v[i].first * v[i].second,
        c[i] = c[i-1] + v[i].second;
    while(q--) {
        ll x; cin >> x;
        ll cnt = lower_bound(v + 1, v + 1 + n, make_pair(x, -1LL)) - (v + 1);
        cout << s[n] - 2 * s[cnt] + x * (c[cnt] - (c[n] - c[cnt])) << '\n';
    }
}