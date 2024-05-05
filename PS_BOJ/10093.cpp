#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    cout << max(0LL, b - a - 1) << '\n';
    for (ll i = a + 1; i < b; ++i) cout << i << ' ';
}