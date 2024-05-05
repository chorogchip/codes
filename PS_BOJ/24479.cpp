#include<bits/stdc++.h>
using namespace std;

vector<int> g[101010];
bool vis[101010];
int cnt = 1;
int ord[101010];

void dfs(int i) {
    ord[i] = cnt++;
    vis[i] = 1;
    for (auto o : g[i]) if (!vis[o]) dfs(o);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, r; cin >> n >> m >> r;
    while(m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) sort(g[i].begin(), g[i].end());
    dfs(r);
    for (int i = 1; i <= n; ++i) cout << ord[i] << '\n';
}