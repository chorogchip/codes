#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<pair<int,int>> v(n);
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second >> v[i].first;
    }
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        s.insert(x);
    }
    sort(v.begin(), v.end());
    ll res = 0;
    for (int i = n - 1; i >= 0; --i) {
        auto [vv, m] = v[i];
        auto it = s.lower_bound(m);
        if (it != s.end()) {
            s.erase(it);
            res += vv;
        }
    }
    cout << res;
}