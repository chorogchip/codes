#include<bits/stdc++.h>
using namespace std;

int g[101010], c[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        memset(c + 1, 0, sizeof(int) * n);
        for (int i = 1; i <= n; ++i) {
            cin >> g[i];
            c[g[i]]++;
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int ii = i;
            while(!c[ii]) {
                c[ii] = -1;
                ++res;
                ii = g[ii];
                --c[ii];
            }
        }
        cout << res << '\n';
    }
}