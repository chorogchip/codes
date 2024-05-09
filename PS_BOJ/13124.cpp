#include<bits/stdc++.h>
using namespace std;

int d[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    int m; cin >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        swap(d[a], d[b]);
        cout << (
            d[1] == n-1 && d[n-1] == n && d[n] == n-2 ||
            d[n-2] == n && d[n-1] == 1 && d[n] == n-1 ||
            d[1] == 3 && d[2] == 1 && d[n] == 2 ||
            d[1] == 2 && d[2] == n && d[3] == 1
        ? "YES\n" : "NO\n");
    }
}