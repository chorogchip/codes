#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        int a, b, n; cin >> a >> b >> n;
        int nn = n;
        vector<int> soinsu;
        for (int i = 2; nn != 1 && i < min(n, 10'0000LL); ++i) if (nn % i == 0) {
            do nn /= i; while(nn % i == 0);
            soinsu.push_back(i);
        }
        if (nn != 1) soinsu.push_back(nn);
        
        int cnt = soinsu.size();
        int res = b - a + 1;
        for (int i = 1; i < 1 << cnt; ++i) {
            int num = 1;
            for (int j = 0; j < cnt; ++j) if (i & 1 << j) {
                num *= soinsu[j];
            }
            int bb = b / num;
            int aa = (a-1) / num;
            int asd = bb - aa;
            if (__builtin_popcount(i) & 1) res -= asd;
            else res += asd;
        }
        cout << "Case #" << tt << ": " << res << '\n';
    }
}