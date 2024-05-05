#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> g[251010];
int par[251010];
int lev[251010];

int un[251010];
int un_sz[251010];
int qury[251010];

void mk_tree(int v, int prev, int level) {
    lev[v] = level;
    par[v] = prev;
    for (auto o : g[v]) if (o != prev) mk_tree(o, v, level+1);
}

ll calc(ll n) {
    return n * (n-1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    mk_tree(1, 0, 0);
    int q; cin >> q;
    for (int qq = 1; qq <= q; ++qq) {
        int k; cin >> k;
        ll res = 0;
        vector<int> st(k);
        for (auto& o : st) cin >> o;
        for (auto o : st) un[o] = o, un_sz[o] = 1;
        sort(st.begin(), st.end(), [](const int& a, const int& b)->bool{
            return lev[a] < lev[b];
        });
        for (auto o : st) {
            qury[o] = qq;
            if (qury[par[o]] == qq) {
                un[o] = un[par[o]];
                un_sz[un[par[o]]]++;
            }
        }
        for (auto o : st) if (un_sz[o] > 1) res += calc(un_sz[o]);
        cout << res << '\n';
    }
}