#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_V = 50101;
const int MAX_E = 201010;
const ll INF = 1LL<<40LL;

int n, m;

struct {
    const bool DBG = false;
    void init() {if(!DBG){ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);}}
    void prt(const char* s) { if (!DBG) return; cout<< s << '\n'; }
} dbg;

void fail() {
    cout << -1; exit(0);
}
pair<int,int> mx2(int a, int b, int c, int d) {
    int arr[4] = {a, b, c, d};
    int ret0 = max(a, max(b, max(c, d)));
    int ret1 = -1;
    for (int i = 0; i < 4; ++i)
        if (arr[i] > ret1 && arr[i] != ret0) ret1 = arr[i];
    return {ret0, ret1};
}

struct {
    vector<pair<int, pair<int,int>>> edges;
} graph;

struct {
    int u[MAX_V];

    void init(int n) { for (int i = 1; i <= n; ++i) u[i] = i; }
    int par(int i) { if (u[i] == i) return i; else return u[i] = par(u[i]); }
    void un(int a, int b) { int aa = par(a); int bb = par(b); u[aa] = bb; }
} ufind;

struct {
    ll sum = 0;
    vector<pair<int,int>> g[MAX_V];
    int par[MAX_V];
    int wei[MAX_V];
    int dep[MAX_V];

    void calc_graph() {
        ufind.init(n);
        int connedted_cnt = 0;
        for (const auto [w, p] : graph.edges) {
            const auto [a, b] = p;
            const int aa = ufind.par(a);
            const int bb = ufind.par(b);
            if (aa != bb) {
                g[a].push_back({b, w});
                g[b].push_back({a, w});
                sum += w;
                ufind.un(aa, bb);
                ++connedted_cnt;
            }
        }
        if (connedted_cnt < n-1) fail();
    }
    void calc_tree() { dfs(1, 1, 0, 0); }
private:
    void dfs(int i, int prev, int prev_wei, int depth) {
        par[i] = prev;
        wei[i] = prev_wei;
        dep[i] = depth;
        for (auto [o, w] : g[i]) if (o != prev) dfs(o, i, w, depth+1);
    }
} spanning_tree;

struct {
    int par[MAX_V][16];
    int mxe0[MAX_V][16], mxe1[MAX_V][16];

    void init() {
        for (int i = 1; i <= n; ++i) {
            par[i][0] = spanning_tree.par[i];
            mxe0[i][0] = spanning_tree.wei[i];
            mxe1[i][0] = -1;
        }
        for (int gap = 1; gap < 16; ++gap) {
            for (int i = 1; i <= n; ++i) {
                const int ppar = par[i][gap-1];
                auto mx = mx2(
                    mxe0[i][gap-1], mxe0[ppar][gap-1],
                    mxe1[i][gap-1], mxe1[ppar][gap-1]);
                mxe0[i][gap] = mx.first;
                mxe1[i][gap] = mx.second;
                par[i][gap] = par[ppar][gap-1];
            }
        }
    }
    int get_par(int a, int x) {
        for (int gap = 15; gap >= 0; --gap)
            if (x & 1<<gap) a = par[a][gap];
        return a;
    }
    pair<int,int> get_mxe(int a, int x) {
        pair<int,int> res = {-1, -1};
        for (int gap = 15; gap >= 0; --gap) {
            if (x & 1<<gap) {
                res = mx2(mxe0[a][gap], mxe1[a][gap], res.first, res.second);
                a = par[a][gap];
            }
        }
        return res;
    }
    pair<int,int> lca_cnt(int a, int b) {
        pair<int,int> ret {0, 0};
        const int ad = spanning_tree.dep[a];
        const int bd = spanning_tree.dep[b];
        if (ad < bd) ret.second += bd - ad, b = get_par(b, bd - ad);
        else if (ad > bd) ret.first += ad - bd, a = get_par(a, ad - bd);
        if (a == b) return ret;
        for (int gap = 15; gap >= 0; --gap)
            if (par[a][gap] != par[b][gap]) {
                a = par[a][gap], b = par[b][gap];
                ret.first += 1<<gap;
                ret.second += 1<<gap;
            }
        if (a != b) {
            ++ret.first; ++ret.second;
            a = b = par[a][0];
        }
        return ret;
    }
    pair<int,int> mxe_onpath(int a, int b) {
        auto o = lca_cnt(a, b);
        auto ret0 = get_mxe(a, o.first);
        auto ret1 = get_mxe(b, o.second);
        return mx2(ret0.first, ret0.second, ret1.first, ret1.second);
    }
} sparse_table;

struct {
    int calc() {
        ll res = INF;
        ufind.init(n);
        for (const auto [w, p] : graph.edges) {
            const auto [a, b] = p;
            const int aa = ufind.par(a);
            const int bb = ufind.par(b);
            if (aa != bb) ufind.un(aa, bb);
            else {
                auto sec = sparse_table.mxe_onpath(a, b);
                if (sec.first == w) sec.first = sec.second;
                if (sec.first != -1) res = min(res, (ll)w - sec.first);
                //cout << a << ' ' << b << ' ' << w << ' ' << sec.first << ' ' << sec.second << '\n';
            }
        }
        if (res == INF) fail();
        return spanning_tree.sum + res;
    }
} ans;

int main() {
    dbg.init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, w; cin >> a >> b >> w;
        graph.edges.push_back({w, {a, b}});
    }
    sort(graph.edges.begin(), graph.edges.end());
    spanning_tree.calc_graph();
    spanning_tree.calc_tree();
    sparse_table.init();
    cout << ans.calc();
}