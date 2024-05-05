#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v;
    while(n--) {
        int d; cin >> d;
        if (d == 1) {
            int x; cin >> x; v.push_back(x);
        } else if (d == 2) {
            if (v.empty()) cout << -1 << '\n';
            else { cout << v.back() << '\n'; v.pop_back(); }
        } else if (d == 3) {
            cout << v.size() << '\n';
        } else if (d == 4) {
            cout << v.empty() << '\n';
        } else {
            if (v.empty()) cout << -1 << '\n';
            else cout << v.back() << '\n';
        }
    }
}