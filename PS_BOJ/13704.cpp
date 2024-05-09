#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int k;
int a[101010];
int d[101010];
vector<int> arr[2010101];

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
        const int target = k ^ d[index - (index<l)];
        auto& v = arr[target];
        return upper_bound(v.begin(), v.end(), r) -
        lower_bound(v.begin(), v.end(), l-1);
    }
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
        ll res = a[cl] == k;
        for (int i = cl+1; i <= cr; ++i) {
            res += qry(i, cl, i-1);
        }
        ans[quarrys[0].id] = res;
        for (int i = 1; i < m; ++i) {
            auto [l, r, blk, id] = quarrys[i];
            while (cl > l) res += qry(cl-1, cl, cr), --cl;
            while (cr < r) res += qry(cr+1, cl, cr), ++cr;
            while (cr > r) res -= qry(cr, cl, cr-1), --cr;
            while (cl < l) res -= qry(cl, cl+1, cr), ++cl;
            ans[id] = res;
        }
        for (auto o : ans) cout << o << '\n';
    }
} mos;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n >> k;
    int prev = 0;
    arr[0].push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; prev ^= a[i];
        d[i] = prev;
        arr[prev].push_back(i);
    }
    int m; cin >> m;
    mos.init(n, m);
    mos.get_input(cin);
    mos.apply();
}