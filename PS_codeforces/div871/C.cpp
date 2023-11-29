#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        const int INF = 1010101010;
        int min_1 = INF;
        int min_2 = INF;
        int min_3 = INF;
        for (int i = 0; i < n; ++i) {
            int m; string st; cin >> m >> st;
            if (st == "01") min_1 = min(min_1, m);
            if (st == "10") min_2 = min(min_2, m);
            if (st == "11") min_3 = min(min_3, m);
        }
        int res = min_3;
        res = min(res, min_1 + min_2);
        if (res == INF) cout << -1 << '\n';
        else cout << res << '\n';
    }
}
