#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<ll> v(n); for (ll& o : v) cin >> o;
    sort(v.begin(), v.end());
    ll res = 20'000'000'000LL;
    for (auto o : v) {
        auto it = lower_bound(v.begin(), v.end(), o + m);
        if (it != v.end()) res = min(res, abs(*it - o));
        it = upper_bound(v.begin(), v.end(), o - m);
        if (it != v.begin()) res = min(res, abs(o - *(it-1)));
    }
    cout << res;
}