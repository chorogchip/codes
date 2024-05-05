#include<bits/stdc++.h>
using namespace std;

int kk;
int d[101010];

struct {
private:
    int n, ns, nn, nh, nm;
    int t[4101010];
    void init_(int i, int s, int e) {
        if (s == e) return;
        int cnt = e - s + 1;
        int md = s + e >> 1;
        init_(i+nn, s, md);
        init_(i+nn+(cnt>>1), md+1, e);
        merge(t+i+nn, t+i+nn+(cnt>>1), t+i+nn+(cnt>>1), t+i+nn+cnt, t+i);
    }
public:
    void init(int num) {
        n = num;
        ns = 32-__builtin_clz(n-1);
        nn = 1<<ns;
        nh = nn>>1;
        nm = nn*ns;
        for (int i = 0; i < nn; ++i) t[i+nm] = d[i+1];
        init_(0, 0, nn-1);
    }
    int get_cnt_above(int i, int s, int e, int l, int r, int k) {
        if (r < s || e < l) return 0;
        int cnt = e - s + 1;
        if (s <= l && r <= e) return (t+i+cnt) - lower_bound(t+i, t+i+cnt, k);
        int md = s + e >> 1;
        return get_cnt_above(i+nn, s, md, l, r, k)
            + get_cnt_above(i+nn+nh, md+1, e, l, r, k);
    }
    int get_cnt_below(int i, int s, int e, int l, int r, int k) {
        if (r < s || e < l) return 0;
        int cnt = e - s + 1;
        if (s <= l && r <= e) return upper_bound(t+i, t+i+cnt, k) - (t+i);
        int md = s + e >> 1;
        return get_cnt_below(i+nn, s, md, l, r, k)
            + get_cnt_below(i+nn+nh, md+1, e, l, r, k);
    }
    int get_nn() const { return nn; }
} ms_tree;

struct {
private:
    struct QRY {
        int l, r, blk, id;
        const bool operator<(const QRY& o) const {
            if (blk != o.blk) return blk < o.blk;
            if (blk & 1) return r > o.r;
            return r < o.r;
        }
    };
    int n, nn, m, tn;
    vector<QRY> quarrys;
    int qry(int l, int r, int std) {
        int upper = ms_tree.get_cnt_above(0, 0, tn-1, l-1, r-1, std + kk + 1);
        int lower = ms_tree.get_cnt_below(0, 0, tn-1, l-1, r-1, std - kk - 1);
        int res = r - l + 1 - (upper + lower);
        return res;
    }
public:
    void init(int elem, int q) {
        n = elem; nn = sqrt(elem)+1; m = q; tn = ms_tree.get_nn();
    }
    void get_input(istream& istr) {
        quarrys.reserve(m);
        for (int i = 0; i < m; ++i) {
            int l, r; istr >> l >> r;
            quarrys.push_back(QRY{l, r, l/nn, i});
        }
        sort(quarrys.begin(), quarrys.end());
    }
    void apply() {
        vector<int> ans(m);
        int cl = quarrys[0].l, cr = quarrys[0].r;
        int res = 0;
        for (int i = cl+1; i <= cr; ++i) {
            res += qry(cl, i-1, d[i]);
        }
        ans[quarrys[0].id] = res;
        for (int i = 1; i < m; ++i) {
            auto [l, r, blk, id] = quarrys[i];
            while (cl < l) { res -= qry(cl, cr, d[cl]); --cl; }
            while (cl > l) { ++cl; res += qry(cl, cr, d[cl]); }
            while (cr < r) { ++cr; res += qry(cl, cr, d[cr]); }
            while (cr > r) { res -= qry(cl, cr, d[cr]); --cr; }
            ans[id] = res;
        }
        for (auto o : ans) cout << o << '\n';
    }
} mos;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int n; cin >> n >> kk;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    ms_tree.init(n);
    int m; cin >> m;
    mos.init(n, m);
    mos.get_input(cin);
    mos.apply();
}