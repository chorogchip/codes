#include<bits/stdc++.h>
using namespace std;

int n, m, s, e;
vector<int> g[201010];
vector<pair<int,int>> input;
int c[201010], dist[201010], from[201010];

int main() {
    cin >> n >> m >> s >> e;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        input.push_back({a, b});
    }
    const int INF = 1'0000'0000;
    for (int i = 0; i <= n; ++i) dist[i] = INF;
    dist[s] = 1;
    c[s] = 1;
    queue<int> qu;
    qu.push(s);
    while (!qu.empty()) {
        auto ver = qu.front(); qu.pop();
        for (auto o : g[ver]) if (!c[o]) {
            c[o] = 1;
            dist[o] = dist[ver] + 1;
            from[o] = ver;
            qu.push(o);
        }
    }

    if (dist[e] == INF) {
        cout << -1;
        return 0;
    }

    vector<int> roads;
    for (int o = e; o != s; o = from[o]) {
        roads.push_back(o);
    }
    roads.push_back(s);
    memset(c, 0, 4 * (n + 3));
    for (int i = 0; i <= n; ++i) dist[i] = INF;
    for (int i = 0; i < (int)roads.size(); ++i) {
        auto o = roads[i];
        dist[o] = 1;
        qu.push(o);
        c[o] = i + 2;
    }
    while (!qu.empty()) {
        auto ver = qu.front(); qu.pop();
        for (auto o : g[ver]) if (!c[o]) {
            c[o] = 1;
            dist[o] = dist[ver] + 1;
            qu.push(o);
        }
    }

    for (auto o : input) {
        auto [a, b] = o;
        if (c[a] > 1 && c[b] > 1) {
            cout << (c[a] <= c[b]) << ' ';
        } else {
            cout << (dist[a] < dist[b]) << ' ';
        }
    }


}