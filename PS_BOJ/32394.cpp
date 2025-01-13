#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool A[1024][1024];
pair<short, short> B[1024];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        B[i] = {u, v};
        A[u][v] = A[v][u] = 1;
    }
    sort(B, B+m);
    ll res = 0;
    for (int i = 0; i < m; ++i) {
        auto [p1, p2] = B[i];
        int j = i+1;
        while(j < m && p1 == B[j].first) ++j;
        for (; j < m; ++j) {
            auto [p3, p4] = B[j];
            res -= p2 == p3;
            res -= p2 == p4;
            res += A[p1][p3] & A[p2][p4];
            res += A[p1][p4] & A[p2][p3];
        }
    }
    cout << (res>>1);
}