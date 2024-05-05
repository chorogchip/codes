#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll    d[1010101];
ll conv[1010101];
ll   a[101010];
ll ans[101010];

vector<ll> asd(vector<ll>& v) {
    vector<ll> ret;
    ret.push_back(1);
    for (auto o : v) {
        int sz = ret.size();
        for (int i = 0; i < sz; ++i) ret.push_back(ret[i] * o);
    }
    sort(ret.begin(), ret.end());
    vector<ll> rret;
    rret.push_back(ret[0]);
    for (auto o : ret) {
        if (rret.back() != o) rret.push_back(o); 
    }
    return rret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        conv[a[i]] = i;
    }
    sort(a + 1, a + 1 + n);
    ll mx = a[n];
    for (ll i = 4; i <= mx; i += 2) d[i] = 2;
    for (ll i = 3; i <= mx; i += 2) if(!d[i]) {
        for (ll j = i * i; j <= mx; j += i + i) d[j] = i;
    }
    for (int i = 1; i <= n; ++i) {
        ll ii = a[i];
        vector<ll> v;
        while (d[ii]) { v.push_back(d[ii]); ii /= d[ii]; }
        v.push_back(ii);
        auto vv = asd(v);
        for (auto o : vv) if(conv[o]) {
            ans[conv[o]]++;
            ans[conv[a[i]]]--;
        }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}