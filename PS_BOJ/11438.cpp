#include<bits/stdc++.h>
using namespace std;

bool vis[101010];
int par[101010][32], dep[101010];
vector<int> g[101010];

void dfs(int v, int d) {
    vis[v] = 1;
    dep[v] = d;
    for (auto o : g[v]) if (!vis[o]) {
        par[o][0] = v;
        dfs(o, d+1);
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    int dif = dep[a] - dep[b];
    for (int i = 0; dif; i++) {
        if (dif & 1) a = par[a][i];
        dif >>= 1;
    }
    if (a == b) return a;
    for (int i = 29; i >= 0; --i) {
        if (par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
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
    for (int t = 1; t < 30; ++t)
    for (int i = 1; i <= n; ++i) par[i][t] = par[par[i][t-1]][t-1];
    int m; cin >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

}