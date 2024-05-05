#include<bits/stdc++.h>
using namespace std;

bool dp[2][80102];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    const int ofs = 40101;
    int n; cin >> n; int s = 0; dp[0][ofs] = 1;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        auto& dest = dp[i&1]; auto& src = dp[i&1^1];
        memcpy(dest, src, sizeof(dest));
        for (int j = -s; j <= s; ++j) if (src[j+ofs]) {
            dest[j+x+ofs] |= 1;
            dest[j-x+ofs] |= 1;
        }
        s += x;
    }
    int m; cin >> m;
    const auto& dest = dp[n&1];
    while(m--) {
        int x; cin >> x;
        cout << (dest[x+ofs] ? "Y " : "N ");
    }
}