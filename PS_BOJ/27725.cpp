#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int p[201010];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i];
    ll k; cin >> k;
    ll r = 0LL;
    for (int i = 0; i < n; ++i) {
        ll kk = k;
        while (kk) {
            kk /= p[i];
            r += kk;
        }
    }
    cout << r;
}