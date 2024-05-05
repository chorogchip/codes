#include<bits/stdc++.h>
using namespace std;

vector<int> g[1010101];

pair<int, bool> calc(int v, int prev) {
    bool need_ea = false;
    int ret = 0;
    for (auto o : g[v]) if (o != prev) {
        auto [cnt, asd] = calc(o, v);
        ret += cnt;
        need_ea |= !asd;
    }
    if (need_ea) return {ret+1, true};
    else return {ret, false};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << calc(1, -1).first;
}