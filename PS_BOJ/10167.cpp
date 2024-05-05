#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;

struct {
    ll val;
    ll mx;
} seg[16384];

ll add(int i, int s, int e, int l, int r, int w) {
    if (e < l || r < s) return seg[i].mx;
    int md = s + e >> 1;
    if (l <= s && e <= r) {
        seg[i].val += w;
        seg[i].mx = max(seg[i<<1].mx, seg[(i<<1)+1].mx) + seg[i].val;
    }
    return max(add(i<<1, s, md, l, r, w), add((i<<1)+1, md+1, e, l, r, w));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    const int nn = 1 << 32 - __builtin_clz(n-1);
    vector<pair<pi,int>> v(n);
    for (auto& o : v) cin >> o.first.first >> o.first.second >> o.second;
    sort(v.begin(), v.end());
    v[0].first.first = 1;
    for (int i = 1, j = 1; i < n; ++i) {
        if (v[i].first.first != v[i-1].first.first) ++j;
        v[i].first.first = j;
    }
    sort(v.begin(), v.end(), [](const auto& a, const auto& b)->bool{
        if (a.first.second != b.first.second)
            return a.first.second < b.first.second;
        if (a.first.first != b.first.first)
            return a.first.first < b.first.first;
        return a.second < b.second;
    });
    ll res = 0;
    for (int gap = 0; gap <= n; ++gap) {
        memset(seg, 0, sizeof(seg));
        for (int i = 0; i < n; ++i) {
            auto [pos, w] = v[i];
            auto [x, y] = pos;
            ll mx = add(1, 0, nn-1, x, x+gap, w);
            if (i == n-1 || y != v[i+1].first.second) res = max(res, mx);
        }
    }
    cout << res;
}