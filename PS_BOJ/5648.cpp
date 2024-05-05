#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> v(n);
    for (auto& o : v) {
        string str; cin >> str;
        ll x = 0;
        for (int i = str.size() - 1; i >= 0; --i)
            x = x * 10LL + str[i] - '0';
        o = x;
    }
    sort(v.begin(), v.end());
    for (auto o : v) cout << o << '\n';
}