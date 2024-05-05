#include<bits/stdc++.h>
using namespace std;

vector<int> g[10101], gp[10101];
bool vis[10101];
vector<int> order;
vector<int> SCC[10101];
int scc_ptr[10101];

void dfs(int i) {
    if (vis[i]) return;
    vis[i] = 1;
    for (auto o : g[i]) dfs(o);
    order.push_back(i);
}
void dfs_rev(int i, int scc) {
    if (vis[i]) return;
    vis[i] = 1;
    SCC[scc].push_back(i);
    scc_ptr[i] = scc;
    for (auto o : gp[i]) dfs_rev(o, scc);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int v, e; cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        gp[b].push_back(a);
    }
    for (int i = 1; i <= v; ++i) if (!vis[i]) dfs(i);
    reverse(order.begin(), order.end());
    memset(vis, 0, sizeof(vis));
    int scc = 0;
    for (auto o : order) if (!vis[o]) dfs_rev(o, ++scc);
    cout << scc << '\n';
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= v; ++i) {
        int scc = scc_ptr[i];
        if (vis[scc]) continue;
        vis[scc] = 1;
        sort(SCC[scc].begin(), SCC[scc].end());
        for (auto o : SCC[scc]) cout << o << ' ';
        cout << -1 << '\n';
        
    }
}