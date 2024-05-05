#include<bits/stdc++.h>
using namespace std;

int dist[128];
vector<int> g[128];

void asd(int i, int v) {
    if (dist[i]) return;
    dist[i] = v;
    for (auto o : g[i]) asd(o, v+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a, b, m; cin >> n >> a >> b >> m;
    while(m--) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    asd(a, 1);
    cout << dist[b] - 1;
}