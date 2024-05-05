#include<bits/stdc++.h>
using namespace std;

int c[30101];
int sz[30101];
int u[30101];

int par(int i) {
    if (u[i] == i) return i;
    else return u[i] = par(u[i]);
}

void un(int a, int b) {
    int aa = par(a);
    int bb = par(b);
    if (aa != bb) {
        u[aa] = bb;
        c[bb] += c[aa];
        sz[bb] += sz[aa];
    }
}

pair<int,int> get(int i) {
    int aa = par(1);
    int ii = par(i);
    if (aa == ii) return {0, 0};
    u[ii] = aa;
    c[aa] += c[ii];
    sz[aa] += sz[ii];
    return {sz[ii], c[ii]};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> c[i], u[i] = i, sz[i] = 1;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        un(a, b);
    }
    vector<pair<int,int>> d;
    d.push_back({sz[par(1)], c[par(1)]});
    for (int i = 2; i <= n; ++i) {
        auto o = get(i);
        if (o.first) d.push_back(o);
    }
    vector<int> dp(k);
    for (auto o : d) {
        auto [sz, cost] = o;
        for (int i = k - sz - 1; i >= 0; --i)
            dp[i+sz] = max(dp[i+sz], dp[i] + cost);
    }
    cout << dp[k-1];
}