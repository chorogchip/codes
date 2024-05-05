#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int sieve[1010101];
ll sum[1010101];

ll pppow(ll x, ll p) {
    ll res = 1;
    while(p) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    const int MX = 1'000'000;
    for (int i = 2; i <= MX; i += 2) sieve[i] = 2;
    for (int i = 3; i <= MX; i += 2) if (!sieve[i])
        for (ll j = (ll)i; j <= MX; j += i + i)
            if (!sieve[j]) sieve[j] = i;
    for (int i = 1; i <= MX; ++i) {
        vector<pair<int,int>> vec;
        int ii = i;
        while(sieve[ii]) {
            int cnt = 0, num = sieve[ii];
            do ii /= num, ++cnt; while (sieve[ii] == num);
            vec.push_back({num, cnt});
        }
        ll s = 1;
        for (auto [n, c] : vec) {
            ll asd = pppow(n, c + 1);
            s *= (asd - 1) / (n - 1);
        }
        sum[i] = sum[i-1] + s;
    }

    while(t--) {
        int n; cin >> n;
        cout << sum[n] << '\n';
    }
}