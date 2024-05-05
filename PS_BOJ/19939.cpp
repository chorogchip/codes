#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int kk = k * (k + 1) / 2;
    if (n < kk) goto E;
    {int ans = k - 1;
    if ((n - kk) % k != 0) ++ans;
    cout << ans; return 0;}
    E: cout << -1;
}