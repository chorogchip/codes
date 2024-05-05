#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int ggcd; cin >> ggcd;
    while(--n) {
        int x; cin >> x;
        ggcd = gcd(ggcd, x);
    }
    vector<int> v;
    int i;
    for (i = 1; i * i < ggcd; ++i) if (ggcd % i == 0) v.push_back(i), v.push_back(ggcd/i);
    if (i * i == ggcd) v.push_back(i);
    sort(v.begin(), v.end());
    for (auto o : v) cout << o << '\n';
}