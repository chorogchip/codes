#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int asz, bsz; cin >> asz >> bsz;
        vector<int> a(asz), b(bsz);
        for (auto& o : a) cin >> o;
        for (auto& o : b) cin >> o;
        sort(b.begin(), b.end());
        int res = 0;
        for (auto o : a) {
            res += lower_bound(b.begin(), b.end(), o) - b.begin();
        }
        cout << res << '\n';
    }
}