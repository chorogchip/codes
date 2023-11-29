#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[101010];
bool vis[101010];
int par[101010][32], dep[101010], Mwei[101010][32], mwei[101010][32];
const int INF = 10'0000'0000;

void dfs(int i, int d) {
    vis[i] = 1;
    dep[i] = d;
    for (auto o : g[i]) if (!vis[o.first]) {
        par[o.first][0] = i;
        Mwei[o.first][0] = mwei[o.first][0] = o.second;
        dfs(o.first, d+1);
    }
}

pair<int,int> lcaw(int a, int b) {
    int resM = 0, resm = INF;
    if (dep[a] < dep[b]) swap(a, b);
    int diff = dep[a] - dep[b];
    for (int i = 0; diff; ++i) {
        if (diff & 1) {
            resM = max(resM, Mwei[a][i]);
            resm = min(resm, mwei[a][i]);
            a = par[a][i];
        }
        diff >>= 1;
    }
    for (int i = 16; i >= 0; --i) if (par[a][i] != par[b][i]) {
            resM = max(resM, Mwei[a][i]);
            resm = min(resm, mwei[a][i]);
            a = par[a][i];
            resM = max(resM, Mwei[b][i]);
            resm = min(resm, mwei[b][i]);
            b = par[b][i];
    }
    if (a != b) {
        resM = max(resM, Mwei[a][0]);
        resm = min(resm, mwei[a][0]);
        resM = max(resM, Mwei[b][0]);
        resm = min(resm, mwei[b][0]);
    }
    return {resm, resM};
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
    
    for (int i = 1; i <= n; ++i) if (mwei[i][0] == 0) mwei[i][0] = INF;
    for (int t = 1; t < 17; ++t) {
        for (int i = 1; i <= n; ++i) {
            Mwei[i][t] = max(Mwei[i][t-1], Mwei[par[i][t-1]][t-1]);
            mwei[i][t] = min(mwei[i][t-1], mwei[par[i][t-1]][t-1]);
            par[i][t] = par[par[i][t-1]][t-1];
        }
    }
    int m; cin >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        auto o = lcaw(a, b);
        cout << o.first << ' ' << o.second << '\n';
    }
}