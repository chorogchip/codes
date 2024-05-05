#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n); for (auto& o : v) cin >> o;
        sort(v.begin(), v.end());
        int m; cin >> m;
        while(m--) {
            int x; cin >> x;
            auto it = lower_bound(v.begin(), v.end(), x);
            cout << (it != v.end() && *it == x) << '\n';
        }
    }   
}