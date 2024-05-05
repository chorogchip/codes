#include<bits/stdc++.h>
using namespace std;

int d[128];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) d[i] = i;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b;
        int gap = b - a + 1;
        for (int j = a; j < a + gap/2; ++j) swap(d[j], d[b - (j - a)]);
    }
    for (int i = 1; i <= n; ++i) cout << d[i] << ' ';
}