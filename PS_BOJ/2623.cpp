#include<bits/stdc++.h>
using namespace std;

vector<int> g[1024];
int c[1024];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int mm = 0; mm < m; ++mm) {
        int cnt, prev; cin >> cnt;
        if (cnt == 0) continue;
        cin >> prev;
        for (int cc = 1; cc < cnt; ++cc) {
            int x; cin >> x;
            g[prev].push_back(x);
            c[x]++;
            prev = x;
        }
    }
    vector<int> res;
    res.reserve(n);
    queue<int> qu;
    for (int i = 1; i <= n; ++i) if (c[i] == 0) qu.push(i);
    while(!qu.empty()) {
        auto o = qu.front(); qu.pop();
        res.push_back(o);
        for (auto oo : g[o]) if (--c[oo] == 0) qu.push(oo);
    }
    if (res.size() != n) cout << 0;
    else {
        for (auto o : res) cout << o << '\n';
    }
}