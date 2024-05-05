#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int sieve[1010101];
unsigned char cnt[1010101];
ll val[1010101];
ll sum[1010101];

inline ll pppow(ll x, int p) {
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
    for (int i = 2; i <= MX; i += 2) sieve[i] = 2, cnt[i] = cnt[i>>1]+1;
    for (int i = 3; i <= MX; i += 2) if (!sieve[i]) {
        for (ll j = (ll)i; j <= MX; j += i + i)
            if (!sieve[j]) {
                sieve[j] = i;
                if (j / i % i == 0) cnt[j] = cnt[j / i] + 1;
                else cnt[j] = 1;
            }
    }
    val[1] = sum[1] = 1;
    for (int i = 2; i <= MX; ++i) {
        ll s = 1;
        int soinsu = sieve[i];
        int ccnt = cnt[i];
        ll asd = pppow(soinsu, ccnt);
        s = val[i/soinsu] * (asd * soinsu - 1) / (asd - 1);
        val[i] = s;
        sum[i] = sum[i-1] + s;
    }
    while(t--) {
        int n; cin >> n;
        cout << sum[n] << '\n';
    }
}