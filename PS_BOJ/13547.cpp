#include<bits/stdc++.h>
using namespace std;

int n;
int d[101010];
vector<int> has[1010101];

struct {
    void init() {
        for (int i = 1; i <= n; ++i) {
            has[d[i]].push_back(i);
        }
    }
    bool find(int x, int l, int r) {
        auto o = lower_bound(has[x].begin(), has[x].end(), l);
        return o != has[x].end() && *o <= r;
    }
} cnts;

struct {
    int l, r;
    int cnt = 0;
    void init(int s, int e) {
        cnt = 1; l = r = s;
        for (int i = s+1; i <= e; ++i) expand_r();
    }
    void expand_r() {
        if (!cnts.find(d[r+1], l, r)) ++cnt;
        r++;
    }
    void expand_l() {
        if (!cnts.find(d[l-1], l, r)) ++cnt;
        l--;
    }
    void narrow_l() {
        if (!cnts.find(d[l], l+1, r)) --cnt;
        l++;
    }
    int get_l() const { return l; }
    int get_r() const { return r; }
    int get_cnt() const { return cnt; }
} intv;

struct {
    int nn;
    int m;
    vector<tuple<int,int,int,int>> v;
    void init() {
        nn = max(1, (int)sqrt(n));
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int l, r; cin >> l >> r;
            v.push_back({l, r, l/nn, i});
        }
        sort(v.begin(), v.end(), [](const auto&a, const auto&b)->bool{
            auto [al, ar, ab, ai] = a;
            auto [bl, br, bb, bi] = b;
            if (ab == bb) return ar < br;
            else return ab < bb;
        });
    }
    void apply() {
        int pv = -1;
        vector<pair<int,int>> res;
        for (auto [l, r, b, i] : v) {
            if (pv != b) {
                intv.init(l, r); pv = b;
            } else {
                while (intv.get_r() < r) intv.expand_r();
                while (l < intv.get_l()) intv.expand_l();
                while (l > intv.get_l()) intv.narrow_l();
            }
            int cnt = intv.get_cnt();
            res.push_back({i, cnt});
        }
        sort(res.begin(), res.end());
        for (auto [i, c] : res) cout << c << '\n';
    }
} qry;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    cnts.init();
    qry.init();
    qry.apply();
}