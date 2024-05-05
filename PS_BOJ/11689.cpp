#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> soinsu;
    ll nn = n;
    for (ll i = 2; i * i <= n; ++i) if (nn % i == 0) {
        do nn /= i; while (nn % i == 0);
        soinsu.push_back(i);
    }
    if (nn != 1) soinsu.push_back(nn);
    int sz = soinsu.size();
    ll res = 0;
    for (int i = 1; i < 1<<sz; ++i) {
        ll num = 1;
        for (int j = 0; j < sz; ++j) if (i & 1<<j) num *= soinsu[j];
        ll cnt = n / num;
        if (__builtin_popcount(i) & 1) res += cnt;
        else res -= cnt;
    }
    cout << n - res;
}