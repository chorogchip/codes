#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

int a[201010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        ll m1 = 0, m2 = 0;
        for (int i = 0; i < n;) {
            if (i == n) break;
            if (a[i] > 0) m1 += a[i];
            i++;
            if (i == n) break;
            if (a[i] > 0) m2 += a[i];
            i++;
        }
        ll res = max(m1, m2);
        if (res > 0) cout << res << '\n';
        else {
            int rres = a[0];
            for (int i = 1; i < n; ++i) rres = max(rres, a[i]);
            cout << rres << '\n';
        }
    }
}
