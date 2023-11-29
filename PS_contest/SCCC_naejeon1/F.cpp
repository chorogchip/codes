#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[1010101], s[1010101], x[1010101], v[1010101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    const ll M = 1'000'000'000LL + 7;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        s[i] = (s[i+1] + a[i]) % M;
    }
    for (int i = n; i >= 1; --i) {
        x[i] = (x[i+1] + a[i] * s[i+1] % M) % M;
    }
    for (int i = n; i >= 1; --i) {
        v[i] = (v[i+1] + a[i] * x[i+1] % M) % M;
    }
    cout << v[1];

}