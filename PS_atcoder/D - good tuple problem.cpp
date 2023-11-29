#include<bits/stdc++.h>
using namespace std;

vector<int> g[201010]; int c[201010];

bool bfs(int v, int last, int st) {
    c[v] = st;
    for (auto o : g[v]) if (o != last) {
        if (!c[o]) { if (!bfs(o, v, st^3)) return false; }
        else if(c[o] == c[v] ) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    for (int i = 0; i < m; ++i) {
        int aa = a[i];
        int bb = b[i];
        g[aa].push_back(bb);
        g[bb].push_back(aa);
    }
    for (int i = 1; i <= n; ++i) if (!c[i]) {
        if (!bfs(i, 0, 1)) goto NO;
    }
    YES: cout << "Yes"; exit(0);
    NO: cout << "No";
}