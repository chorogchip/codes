#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        int n; cin >> n;
        int res = 0;
        vector<int> l[512];
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            for (int j = 0; j <= i; ++j) {
                if (j == i || l[j].back() < x) l[j].push_back(x);
                else l[j][lower_bound(l[j].begin(), l[j].end(), x) - l[j].begin()] = x;
                res += l[j].size();
            }
        }
        cout << "Case #" << tt << ": " << res << '\n';
    }
}