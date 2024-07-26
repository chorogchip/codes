#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    ll s = 0;
    ll res = 0;
    for (int i=  1; i <= n; ++i) {
        ll x; cin >> x;
        s += x;
        s = max(0LL, s);
        if (s >= k) ++res;
    }
    cout << res;
}