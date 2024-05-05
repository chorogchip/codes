#include<bits/stdc++.h>
using namespace std;

int n;
int d[101010];
int seg[401010];

struct {
private:
    const int nn = 131072;
    int t, x;
    int add(int i, int s, int e) {
        if (t < s || e < t) return seg[i];
        if (s == e) return seg[i] += x;
        const int md = s + e >> 1;
        return seg[i] = max(
            add(i<<1, s, md), add((i<<1)+1, md+1, e));
    }
public:
    inline void clear() { memset(seg, 0, nn*2*4); }
    inline void inc(int xx) {
        seg[nn + xx]++;
        for (int i = 0; i < 17; ++i)

        int lo = 1, hi = nn;
        while (lo < hi) {
            int md = lo + hi >> 1;
        }
        t=xx,x=1; add(1, 1, nn);
    }
    inline void dec(int xx) { t=xx,x=-1; add(1, 1, nn); }
    inline int get_max() const { return seg[0]; }
} seg_tree;

struct {
private:
    int l, r;
public:
    void init(int s, int e) {
        seg_tree.clear();
        seg_tree.inc(d[s]);
        l = r = s;
        for (int i = s+1; i <= e; ++i) expand_r();
    }
    inline void expand_r() { r++; seg_tree.inc(d[r]); }
    inline void expand_l() { l--; seg_tree.inc(d[l]); }
    inline void narrow_l() { seg_tree.dec(d[l]); l++; }
    inline int get_l() const { return l; }
    inline int get_r() const { return r; }
    inline int get_cnt() const { return seg_tree.get_max(); }
} intv;

struct {
    void apply() {
        vector<tuple<int,int,int,int>> v; v.reserve(n);
        int nn = (int)sqrt(n) + 1; int m; cin >> m;
        for (int i = 0; i < m; ++i) {
            int l, r; cin >> l >> r;
            v.push_back({l, r, l/nn, i});
        }
        sort(v.begin(), v.end(), [](const auto&a, const auto&b)->bool{
            auto [al, ar, ab, ai] = a;
            auto [bl, br, bb, bi] = b;
            if (ab != bb) return ab < bb;
            if (ar != br) return ar < br;
            return al > bl;
        });
        vector<pair<int,int>> res; res.reserve(m);
        int pv = -1;
        for (auto [l, r, b, i] : v) {
            if (pv != b) {
                intv.init(l, r);
                pv = b;
            } else {
                while (intv.get_r() < r) intv.expand_r();
                while (l < intv.get_l()) intv.expand_l();
                while (intv.get_l() < l) intv.narrow_l();
            }
            res.push_back({i, intv.get_cnt()});
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
    qry.apply();
}