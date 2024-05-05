#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[512];
vector<int> from[512];
int cost[512];
bool mask[512];
const int INF = 1'0000'0000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(true) {
        int n, m; cin >> n >> m;
        if (n == 0) exit(0);
        int s, d; cin >> s >> d;
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            from[i].clear();
            cost[i] = INF;
            mask[i] = false;
        }
        while(m--) {
            int u, v, p; cin >> u >> v >> p;
            g[u].push_back({v, p});
        }
        priority_queue<pair<int,int>> pqu;
        cost[s] = 0; pqu.push({0, s});
        while(!pqu.empty()) {
            auto o = pqu.top(); pqu.pop();
            int cur = -o.first; int v = o.second;
            if (mask[v]) continue; mask[v] = true;
            for (auto oo : g[v]) {
                int new_cost = cur + oo.second;
                if (cost[oo.first] > new_cost) {
                    cost[oo.first] = new_cost;
                    from[oo.first].clear();
                    from[oo.first].push_back(v);
                    pqu.push({-new_cost, oo.first});
                } else if (cost[oo.first] == new_cost) {
                    from[oo.first].push_back(v);
                }
            }
        }
        if (cost[d] == INF) {
            cout << -1 << '\n';
            continue;
        }
        
        vector<int> rem; rem.push_back(d);
        while(!rem.empty()) {
            auto o = rem.back(); rem.pop_back();
            for (auto oo : from[o]) {
                for (int ii = 0; ii < g[oo].size(); ++ii)
                    if (g[oo][ii].first == o) {
                        g[oo][ii] = g[oo].back();
                        g[oo].pop_back();
                        break;
                    }
                rem.push_back(oo);
            }
            from[o].clear();
        }
        for (int i = 0; i < n; ++i) {
            cost[i] = INF;
            mask[i] = false;
        }
        
        cost[s] = 0; pqu.push({0, s});
        while(!pqu.empty()) {
            auto o = pqu.top(); pqu.pop();
            int cur = -o.first; int v = o.second;
            if (mask[v]) continue; mask[v] = true;
            for (auto oo : g[v]) {
                int new_cost = cur + oo.second;
                if (cost[oo.first] > new_cost) {
                    cost[oo.first] = new_cost;
                    if (!mask[oo.first]) pqu.push({-new_cost, oo.first});
                }
            }
        }
        cout << (cost[d] == INF ? -1 : cost[d]) << '\n';
    }
}