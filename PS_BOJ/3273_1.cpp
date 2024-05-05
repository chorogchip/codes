#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n); for (auto& o : v) cin >> o;
    sort(v.begin(), v.end());
    int x; cin >> x;
    ll res = 0;
    for (int i = 0; i < n; ++i)
        res += upper_bound(v.begin()+i+1, v.end(), x-v[i])
             - lower_bound(v.begin()+i+1, v.end(), x-v[i]);
    cout << res;
}