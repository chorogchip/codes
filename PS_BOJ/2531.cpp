#include<bits/stdc++.h>
using namespace std;

int a[30101];
int mask[3010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, d, k, c; cin >> n >> d >> k >> c;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int cnt = 0;
    for (int i = n-k; i < n; ++i)
        if (mask[a[i]]++ == 0) ++cnt;
    int res = cnt + !mask[c];
    for (int i = 0; i < n-1; ++i) {
        if (mask[a[i]]++ == 0) ++cnt;
        if (--mask[a[(i-k+n)%n]] == 0) --cnt;
        res = max(res, cnt + !mask[c]);
    }
    cout << res;
}