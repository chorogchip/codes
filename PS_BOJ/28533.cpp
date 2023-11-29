#include<bits/stdc++.h>
using namespace std;

int a[8192];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int lo = 1, hi = n, res = 0;
    sort(a + 1, a + n + 1);
    while (lo < hi) {
        if (a[lo] + a[hi] <= k) ++res, ++lo, --hi;
        else --hi;
    }
    cout << res;

}