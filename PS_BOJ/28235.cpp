#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ll sum = 0; int prev = 0;
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        ll x; cin >> x;
        if (x) { sum += x; v.push_back(prev); prev = 0; }
        else ++prev;
    }
    if (v.empty()) {
        cout << prev/2; exit(0);
    }
    v[0] += prev;
    for (auto o : v) sum += o + 1 >> 1;
    cout << sum;
}