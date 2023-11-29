#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, k; cin >> n >> k;
    ll res = 0;
    ll tens = 1;
    for (ll i = n; i >= 1; --i) {
        res += tens * i % k;
        res %= k;
        ll ii = i;
        do (tens *= 10) %= k; while (ii /= 10);
    }
    cout << res;
}