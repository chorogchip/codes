#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> G[2010];
vector<int> T;
int n;
const int INF = 50101010;
int Ds[2048], Dg[2048], Dh[2048];
bool vis[2048];

void djik(int st, int dist[]) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    priority_queue<pair<int,int>,
        vector<pair<int,int>>, greater<pair<int,int>>> qu;
    qu.push({0, st});
    dist[st] = 0;
    while(!qu.empty()) {
        auto [w, o] = qu.top(); qu.pop();
        vis[o] = 1;
        for (auto oo : G[o]) if (!vis[oo.first]) {
            int cost = w + oo.second;
            if (dist[oo.first] > cost) {
                dist[oo.first] = cost;
                qu.push({cost, oo.first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int m, t; cin >> n >> m >> t;
        int s, g, h; cin >> s >> g >> h;
        for (int i = 1; i <= n; ++i) G[i].clear();
        for (int i = 1; i <= m; ++i) {
            int a, b, d; cin >> a >> b >> d;
            G[a].push_back({b, d});
            G[b].push_back({a, d});
        }
        T.clear();
        for (int i = 1; i <= t; ++i) {
            int x; cin >> x; T.push_back(x);
        }
        djik(s, Ds); djik(g, Dg); djik(h, Dh);
        vector<int> ans;
        int wei;
        for (auto o : G[g]) if (o.first == h) {
            wei = o.second;
            break;
        }
        for (auto o : T) {
            int dist = Ds[o];
            int ddist = min(Ds[g] + Dh[o], Ds[h] + Dg[o]) + wei;
            if (dist == ddist) ans.push_back(o);
        }
        sort(ans.begin(), ans.end());
        for(auto o : ans) cout << o << ' '; cout << '\n';
    }
}