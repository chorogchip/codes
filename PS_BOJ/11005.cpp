#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n, b; cin >> n >> b;
    vector<ll> ret;
    do ret.push_back(n%b); while (n/=b);
    for (int i = ret.size()-1; i >= 0; --i) {
        ll r = ret[i];
        if (r < 10) cout << (char)('0'+r);
        else cout << (char)('A'+r-10);
    }
}