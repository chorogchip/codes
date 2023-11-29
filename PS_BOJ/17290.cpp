#include <bits/stdc++.h>
using namespace std;
int d[1010101], st[1010101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, sz = 0; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    for (int i = n; i > 0; --i) {
        while (sz && st[sz-1] <= d[i]) --sz;
        int res = sz ? st[sz-1] : -1;
        st[sz++] = d[i];
        d[i] = res;
    }
    for (int i = 1; i <= n; ++i) cout << d[i] << ' ';
}