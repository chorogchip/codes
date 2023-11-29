#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        int n, m; cin >> n >> m;
        if (n == 1 || m == 1) goto YES;
        else if (n <= m) goto NO;
        else {
            if (n % m == 0) goto NO;
            for (int j = 2; j * j <= n && j <= m; j++) if (n % j == 0) {
                if ((m - j) * (n/j - 1) >= n % j) goto NO;
            }
            goto YES;
        }
        NO: cout << "NO\n"; continue;
        YES: cout << "YES\n"; continue;
    }
}