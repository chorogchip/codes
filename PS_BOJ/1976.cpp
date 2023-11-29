#include<bits/stdc++.h>
using namespace std;

int par[256];

int find(int i) {
    if (par[i] == i) return i;
    else return par[i] = find(par[i]);
}

void merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    par[aa] = bb;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) par[i] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x; cin >> x;
            if (x) merge(i, j);
        }
    }
    bool res = true;
    int f; cin >> f;
    for (int i = 2; i <= m; ++i) {
        int x; cin >> x;
        res &= find(f) == find(x);
    }
    cout << (res ? "YES" : "NO");
}