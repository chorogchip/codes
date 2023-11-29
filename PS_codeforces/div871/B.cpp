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
        int last = 1;
        int zero_cnt = 0;
        int max_zc = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x == 0) {
                last = 0;
                zero_cnt++;
            } else {
                last = 1;
                max_zc = max(max_zc, zero_cnt);
                zero_cnt = 0;
            }
        }
        max_zc = max(max_zc, zero_cnt);
        cout << max_zc << '\n';
    }
}
