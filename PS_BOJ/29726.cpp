#include<bits/stdc++.h>
using namespace std;

int a[201010];
int fr[201010];
int bk[201010];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) fr[i] = max(fr[i-1], a[1] - a[i+1]);
    for (int i = 1; i <= m; ++i) bk[i] = max(bk[i-1], a[n-i] - a[n]);
    int res = 0;
    for (int i = 0; i <= m; ++i) res = max(res, fr[i] + bk[m-i]);
    cout << res + a[n] - a[1];
}