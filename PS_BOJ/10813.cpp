#include<bits/stdc++.h>
using namespace std;

int d[128];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) d[i] = i;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b ;
        swap(d[a], d[b]);
    }
    for (int i = 1; i <= n; ++i) cout << d[i] << ' ';
}