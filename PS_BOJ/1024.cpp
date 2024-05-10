#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, l; cin >> n >> l;
    for (ll len = l; len <= 100; ++len) {
        ll tar = n - (len * (len-1) >> 1);
        if (tar >= 0 && tar % len == 0) {
            ll t = tar / len;
            for (ll i = t; i <= t + len - 1; ++i) cout << i << ' ';
            exit(0);
        }
    }
    cout << -1;
}