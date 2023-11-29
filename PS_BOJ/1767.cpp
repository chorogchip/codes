#include<bits/stdc++.h>
using namespace std;

bool vis[40101];
int par[40101][32], dep[40101], wei[40101][32];
vector<pair<int,int>> g[40101];

void dfs(int i, int d) {
    vis[i] = 1;
    dep[i] = d;
    for (auto o : g[i]) if (!vis[o.first]) {
        par[o.first][0] = i;
        wei[o.first][0] = o.second;
        dfs(o.first, d+1); 
    }
}

int lcaw(int a, int b) {
    int res = 0;
    if (dep[a] < dep[b]) swap(a, b);
    int diff = dep[a] - dep[b];
    for (int i = 0; diff; ++i) {
        if (diff & 1) res += wei[a][i], a = par[a][i];
        diff >>= 1;
    }
    for (int i = 29; i >= 0; --i) {
        if (par[a][i] != par[b][i]) {
            res += wei[a][i];
            res += wei[b][i];
            a = par[a][i];
            b = par[b][i];
        }
    }
    if (a != b) res += wei[a][0] + wei[b][0];
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    dfs(1, 0);
    for (int t = 1; t < 30; ++t)
    for (int i = 1; i <= n; ++i) {
        wei[i][t] = wei[par[i][t-1]][t-1] + wei[i][t-1];
        par[i][t] = par[par[i][t-1]][t-1];
        if (par[i][t] == 0) wei[i][t] = 0;
    }
    int m; cin >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        cout << lcaw(a, b) << '\n';
    }
}