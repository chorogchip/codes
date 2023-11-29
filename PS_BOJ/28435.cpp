#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt[101010];
ll asdf[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    const ll M = 1'000'000'007;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        cnt[x % k]++;
    }
    asdf[0] = 1;
    for (int i = 1; i < 101010; ++i) 
        asdf[i] = asdf[i-1] * 2 % M;
    ll res = 1LL;
    for (int i = 1; i * 2 < k; ++i) {
        res *= (asdf[cnt[i]] + asdf[cnt[k-i]] - 1 + M) % M;
        res %= M;
    }
    if (!(k & 1)) {
        res *= 1LL + cnt[k >> 1];
        res %= M;
    }
    res *= 1LL + cnt[0];
    res %= M;
    cout << (res - 1LL - n + M) % M;
}