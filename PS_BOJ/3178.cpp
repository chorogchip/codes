#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q; cin >> q;
    vector<int> v;
    while(q--) {
        int d; cin >> d;
        if (d == 1) {
            int x; cin >> x; v.push_back(x);
        } else {
            int sz = v.size();
            int s0 = 0, s1 = 0, i = 0;
            for (; i < sz/2; ++i) s0 += v[i];
            for (; i < sz; ++i) s1 += v[i];
            if (s0 <= s1) v.erase(v.begin(), v.begin() + sz/2);
            else v.erase(v.begin() + sz/2, v.end());
            cout << min(s0, s1) << '\n';
        }
    }
    for (auto o : v) cout << o << ' ';
}