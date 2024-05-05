#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int nn;
vector<pair<int,int>> g[250101*8];
vector<int> tmp_out, tmp_in;
ll dist[250101*8];
const ll INF = 1'000'000'000'000'000'000LL;

void get_ver_out(int i, int s, int e, int l, int r) {
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        tmp_out.push_back(i + nn*2);
        return;
    }
    int md = s + e >> 1;
    get_ver_out(i<<1, s, md, l, r);
    get_ver_out((i<<1)+1, md+1, e, l, r);
}
void get_ver_in(int i, int s, int e, int l, int r) {
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        tmp_in.push_back(i);
        return;
    }
    int md = s + e >> 1;
    get_ver_in(i<<1, s, md, l, r);
    get_ver_in((i<<1)+1, md+1, e, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    nn = 1 << 32 - __builtin_clz(n-1);
    for (int i = 1; i < nn; ++i) {
        g[i].push_back({i<<1, 0});
        g[i].push_back({(i<<1)+1, 0});
    }
    for (int i = 0; i < nn; ++i)
        g[i+nn].push_back({i+nn*3, 0});
    for (int i = 1; i < nn; ++i) {
        g[(i<<1)+nn*2].push_back({i+nn*2, 0});
        g[(i<<1)+1+nn*2].push_back({i+nn*2, 0});
    }
    for (int mm = nn*4; mm < m + nn*4; ++mm) {
        int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
        get_ver_out(1, 0, nn-1, b-1, c-1);
        get_ver_in(1, 0, nn-1, d-1, e-1);
        for (auto oo : tmp_out) g[oo].push_back({mm, a});
        for (auto oi : tmp_in) g[mm].push_back({oi, 0});
        tmp_out.clear();
        tmp_in.clear();
    }

    for (int i = 1; i < nn*4+m; ++i) dist[i] = INF;
    priority_queue<pair<ll,int>> pq;
    pq.push({0, k + nn - 1});
    dist[k+nn-1] = 0;
    while (!pq.empty()) {
        const auto [w, i] = pq.top(); pq.pop();
        if (-w > dist[i]) continue;
        for (auto [b, cost] : g[i]) {
            if (dist[b] > -w + cost) {
                dist[b] = -w + cost;
                pq.push({-dist[b], b});
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << (dist[i+nn-1] == INF ? -1 : dist[i+nn-1]) << ' ';
}