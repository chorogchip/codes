#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> v(n); for (auto& o : v) cin >> o;
    sort(v.begin(), v.end());
    int a = 0, b = n-1;
    int res = 0;
    while (a < b) {
        int s = v[a] + v[b];
        if (s < m) ++a;
        else if (s == m) ++a, --b, ++res;
        else --b;
    }
    cout << res;
}