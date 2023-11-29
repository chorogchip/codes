#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
ll a[16];
ll cnt[16];
ll dp[1<<16][128];

ll getdif(ll num, ll bit, ll k) {
    ll exp = 0;
    for (ll i = 0LL; i < n; ++i) if (bit & 1LL<<i)
        exp += cnt[i];
    ll res = num % k;
    for (ll i = 0LL; i < exp; ++i) {
        res *= 10LL;
        res = res % k;
    }
    return res;
}

ll dpdp(ll bit, ll kk, ll k) {
    if (dp[bit][kk] != -1LL) return dp[bit][kk];
    if (bit == 0LL) return (ll)(kk == 0LL);
    ll res = 0LL;
    for (ll i = 0LL; i < n; ++i) if (bit & 1LL<<i) {
        ll dif = getdif(a[i], bit & ~(1LL<<i), k);
        ll new_kk = (kk + k - dif) % k;
        res += dpdp(bit & ~(1LL<<i), new_kk, k);
    }
    return dp[bit][kk] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (ll i = 0LL; i < n; ++i) {
        cin >> a[i];
        ll x = a[i];
        do ++cnt[i]; while (x /= 10LL);
    }
    ll k; cin >> k;
    memset(dp, -1, (1<<16) * 128 * sizeof(ll));
    ll res = dpdp((1LL<<n)-1LL, 0LL, k);
    ll fac = 1;
    for (ll i = 2LL; i <= n; ++i) fac *= i;

    if (res == 0LL) cout << "0/1";
    else if (res == fac) cout << "1/1";
    else {
        ll gc = std::gcd(res, fac);
        cout << res/gc << '/' << fac/gc;
    }
}