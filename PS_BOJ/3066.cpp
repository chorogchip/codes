#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> l;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (i == 0 || l.back() < x) l.push_back(x);
            l[lower_bound(l.begin(), l.end(), x) - l.begin()] = x;
        }
        cout << l.size() << '\n';
    }
}