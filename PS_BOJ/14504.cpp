#include<bits/stdc++.h>
using namespace std;

int d[101010];
int s[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int nn = sqrt(n);
    for (int i = 0; i < n; ++i) cin >> d[i], s[i] = d[i];
    for (int i = 0; i < n; i += nn) sort(s+i, s+i+nn);
    int m; cin >> m;
    while(m--) {
        int a; cin >> a;
        if (a == 1) {
            int i, j, k; cin >> i >> j >> k; i--; j--;
            int cnt = 0;
            int ii = i/nn; ii *= nn;
            int jj = j/nn; jj *= nn;
            if (ii == jj) {
                for (int l = i; l <= j; ++l) if (d[l] > k) ++cnt;
                goto E;
            }
            for (int l = i; l < ii+nn; ++l) if (d[l] > k) ++cnt;
            for (int l = jj; l <= j; ++l) if (d[l] > k) ++cnt;
            for (int l = ii+nn; l < jj; l += nn)
                cnt += (s+l+nn) - upper_bound(s+l, s+l+nn, k);
            E:;
            cout << cnt << '\n';
        } else {
            int i, k; cin >> i >> k; i--;
            int prev = d[i]; d[i] = k;
            int div = i/nn; div *= nn;
            if (k > prev) {
                int* it = upper_bound(s+div, s+div+nn, prev)-1;
                for (int i = it-s; i < div+nn-1; ++i) {
                    if (s[i+1] >= k) { s[i] = k; goto E1; }
                    s[i] = s[i+1];
                }
                s[div+nn-1] = k;
                E1:;
            } else if (k < prev) {
                int* it = lower_bound(s+div, s+div+nn, prev);
                for (int i = it-s; i > div; --i) {
                    if (s[i-1] <= k) { s[i] = k; goto E2; }
                    s[i] = s[i-1];
                }
                s[div] = k;
                E2:;
            }
        }
    }
}