#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, d[101010], t[201010];
const int N = 100'000;

struct {
public:
    int get(int l, int r) {
        r = min(r, N);
        l = min(l, N);
        r = max(r, 0);
        l = max(l-1, 0);
        int s = 0;
        while (r) s += t[r], r -= r&-r;
        while (l) s -= t[l], l -= l&-l;
        return s;
    }
    void push(int x) { while (x <= N) t[x] += 1, x += x&-x; }
    void pop(int x) { while (x <= N) t[x] += -1, x += x&-x; }
} seg_tree;

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
    int n, nn, m;
    vector<QRY> quarrys;
public:
    int qry(int index, int l, int r) {
        return seg_tree.get(d[index] - k, d[index] + k); }
    void init(int elem, int q) { n = elem; nn = sqrt(elem)+1; m = q; }
    void get_input(istream& istr) {
        quarrys.reserve(m);
        for (int i = 0; i < m; ++i) {
            int l, r; istr >> l >> r;
            quarrys.push_back(QRY{l, r, l/nn, i});
        }
        sort(quarrys.begin(), quarrys.end());
    }
    void apply() {
        vector<ll> ans(m);
        int cl = quarrys[0].l, cr = quarrys[0].r;
        ll res = 0;
        seg_tree.push(d[cl]);
        for (int i = cl+1; i <= cr; ++i) {
            res += qry(i, cl, i-1);
            seg_tree.push(d[i]);
        }
        ans[quarrys[0].id] = res;
        for (int i = 1; i < m; ++i) {
            auto [l, r, blk, id] = quarrys[i];
            while (cl > l) res += qry(cl-1, cl, cr), --cl, seg_tree.push(d[cl]);
            while (cr < r) res += qry(cr+1, cl, cr), ++cr, seg_tree.push(d[cr]);
            while (cr > r) seg_tree.pop(d[cr]), res -= qry(cr, cl, cr-1), --cr;
            while (cl < l) seg_tree.pop(d[cl]), res -= qry(cl, cl+1, cr), ++cl;
            ans[id] = res;
        }
        for (auto o : ans) cout << o << '\n';
    }

} mos;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    int m; cin >> m;
    mos.init(n, m);
    mos.get_input(cin);
    mos.apply();
}