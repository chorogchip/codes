#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll a, b, k; cin >> a >> b >> k;
    ll s = a + b;
    vector<ll>v;
    for(ll i = 1; i * i <= s; ++i) if (s % i == 0) {
        ll m = s / i;
        v.push_back(i);
        ll arem = a % m;
        ll brem = b % m;
        if (min(arem, brem) > k) continue;
        cout << m;
        return 0;
    }
    for (int i = v.size() - 1; i >= 0; --i) {
        ll m = v[i];
        ll arem = a % m;
        ll brem = b % m;
        if (min(arem, brem) > k) continue;
        cout << m;
        return 0;
    }
    cout << 1;
}