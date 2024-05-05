#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll s; cin >> s;
    ll ans = 0;
    for (ll i = 1; s - i >= 0; ++i, ++ans) s -= i;
    cout << ans;
}