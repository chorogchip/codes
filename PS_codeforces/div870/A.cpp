#include<bits/stdc++.h>
using namespace std;

int D[128];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        memset(D, 0, sizeof(D));
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            D[x]++;
        }
        for (int li = 0; li <= n; ++li) {
            int liars = 0;
            for (int i = n; i >= 0; --i) {
                if (i > li) liars += D[i];
            }
            if (liars == li) {
                cout << liars << '\n';
                goto END;
            }
        }
        cout << -1 << '\n';
        END:;
    }
}