#include<bits/stdc++.h>
using namespace std;

vector<int> g[101010];
bool vis[101010];
int dep[101010], par[101010][32];

void dfs(int i, int d) {
    vis[i] = 1;
    dep[i] = d;
    for (auto o : g[i]) if (!vis[o]) {
        par[o][0] = i;
        dfs(o, d+1);
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    int diff = dep[a] - dep[b];
    for (int i = 0; diff; ++i) {
        if (diff & 1) a = par[a][i];
        diff >>= 1;
    }
    for (int i = 29; i >= 0; --i) if (par[a][i] != par[b][i]) {
        a = par[a][i];
        b = par[b][i];
    }
    return par[a][0];
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
    dfs(1, 0);
    for (int t = 1; t < 30; ++t) {
        for (int i = 1; i <= n; ++i)
            par[i][t] = par[par[i][t-1]][t-1];
    }
    int m; cin >> m;
    while(m--) {
        int r, a, b; cin >> r >> a >> b;
        int l = lca(a, b);
        int la = lca(r, a);
        int lb = lca(r, b);
        if (la == lb) cout << l;
        else if (l == la) cout << lb;
        else cout << la;
        cout << '\n';
    }
}