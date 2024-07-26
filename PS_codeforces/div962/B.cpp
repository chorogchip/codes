#include<bits/stdc++.h>
using namespace std;

char g[1024][1024];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> g[i][j];
            }
        }
        for (int i = 1; i <= n; i += k) {
            for (int j = 1; j <= n; j += k) {
                cout << g[i][j];
            }
            cout << '\n';
        }
    }
}