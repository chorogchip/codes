#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> l;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (i == 0 || l.back() < x) l.push_back(x);
            else {
                int idx = lower_bound(l.begin(), l.end(), x) - l.begin();
                l[idx] = x;
            }
        }
        cout << "Case #" << tt << '\n' << (k <= l.size()) << '\n';
    }
}