#include<bits/stdc++.h>
using namespace std;

vector<int> g[10101];
int mask[10101];
int cnt, msk;

void dfs(int i) {
    mask[i] = msk; ++cnt;
    for (auto o : g[i]) if (mask[o] != msk) dfs(o);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        g[b].push_back(a);
    }
    int mx = 0; vector<int> res; res.push_back(0);
    for (int i = 1; i <= n; ++i) {
        msk = i; cnt = 0;
        dfs(i);
        if (cnt > mx) {
            mx = cnt; res.clear(); res.push_back(i);
        } else if (cnt == mx) res.push_back(i);
    }
    sort(res.begin(), res.end());
    for (auto o : res) cout << o << ' ';
}