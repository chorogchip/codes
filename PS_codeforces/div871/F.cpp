#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int c[256];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n, m; cin >> n >> m;
        memset(c, 0, sizeof(c));
        for (int i = 0; i < m; ++i) {
            int a, b; cin >> a >> b;
            c[a]++; c[b]++;
        }
        int xx = 0, yy = 0;
        int xc = 0, yc = 0;
        for (int i = 1; i <= n; ++i) {
            if (c[i] == 1) continue;
            if (xc == 0) {
                xx = c[i];
                ++xc;
            } else {
                if (xx == c[i]) ++xc;
                else if (yy == c[i]) ++yc;
                else yy = c[i], ++yc;
            }
        }
        if (yc == 0) cout << xx << ' ' << xx - 1 << '\n';
        else if (xc == 1) cout << xx << ' ' << yy - 1 << '\n';
        else cout << yy << ' ' << xx - 1 << '\n';
        }
}
