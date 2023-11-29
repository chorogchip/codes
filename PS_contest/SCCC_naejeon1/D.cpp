#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll s; cin >> s;
    if (s == 0) {
        cout << "0";
        return 0;
    }
    ll lo = 1, md, hi = 1'0000'0000'0;
    while(lo < hi) {
        md = lo + hi >> 1;
        if (md * md < s) lo = md + 1;
        else hi = md;
    }
    if (lo * (lo - 1) >= s) cout << lo * 2 - 1;
    else cout << lo * 2;
}