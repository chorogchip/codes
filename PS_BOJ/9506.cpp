#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(1) {
        ll x; cin >> x;
        if (x == -1) exit(0);
        ll sum = 0;
        vector<ll> v;
        for (ll i = 1; i < x; ++i) if (x % i == 0)
            v.push_back(i), sum += i;
        if (sum != x) cout << x << " is NOT perfect.\n";
        else {
            cout << x << " = ";
            for (int i = 0; i < v.size() - 1; ++i) cout << v[i] << " + ";
            cout << v.back() << '\n';
        }
    }
}