#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[10];
int n, m, k;

int asd(int mask, int con) {
    int mink = k * 2;
    for (int i = 1; i <= n; ++i) if (mask >> i & 1) {
        for (int j = 1; j <= n; ++j) if (con >> j & 1) {
            //mink = min(mink, () % k);
        }
    }
    return mink;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i= 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    cout << asd(0b1111'1111'0, 2);
}