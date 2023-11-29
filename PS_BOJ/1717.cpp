#include<bits/stdc++.h>
using namespace std;

int uf[1010101];

int find(int v) {
    if (uf[v] == v) return v;
    else return uf[v] = find(uf[v]);
}

void merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    uf[aa] = bb;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) uf[i] = i;
    while(m--) {
        int x, a, b; cin >> x >> a >> b;
        if (x) cout << (find(a) == find(b) ? "YES\n" : "NO\n");
        else merge(a, b);
    }
}