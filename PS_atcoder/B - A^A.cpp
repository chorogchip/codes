#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll poww(ll a, ll p) {
    ll res = 1;
    while(p) {
        if (p & 1) res *= a;
        p>>=1; a *= a;
    }
    return res;
}

int main() {
    ll b; cin >> b;
    for (ll a = 1;; a++) {
        ll r = poww(a, a);
        if (r > b) break;
        if (r == b) {
            cout << a; exit(0);
        }
    }
    cout << -1;
}