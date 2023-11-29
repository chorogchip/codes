#include<bits/stdc++.h>
using namespace std;
using ll = long long;

set<pair<int,int>> st;

ll query(int x, int y) {
    ll res = 0;
    int height = 0;
    int right = x;
    auto it = st.lower_bound({x+1, 0});
    if (it != st.end()) height = it->second;
    if (height >= y) return 0;
    while (it != st.begin()) {
        auto [a, b] = *--it;
        res += (ll)(y - height) * (ll)(right - a);
        height = b;
        right = a;
        if (height == y && a != x) st.erase(it);
        if (height >= y) break;
        it = st.erase(it);
    }
    if (height < y) res += (ll)(y - height) * (ll)(right);
    if (res) st.insert({x, y});
    return res;
}

int main() {
    int q; cin >> q;
    ll res = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (q--) {
        int x, y; cin >> x >> y;
        res += query(x, y);
        cout << res << '\n';
    }
}