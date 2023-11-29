#include<bits/stdc++.h>
using namespace std;

int a[1010101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> l, p(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0 || l.back() < a[i]) {
            p[i] = l.size();
            l.push_back(a[i]);
        } else {
            int idx = lower_bound(l.begin(), l.end(), a[i]) - l.begin();
            l[idx] = a[i], p[i] = idx;
        }
    }
    vector<int> res;
    for (int i = n - 1, t = l.size() - 1; i >= 0; --i) {
        if (p[i] == t) res.push_back(a[i]), --t;
    }
    cout << l.size() << '\n';
    for (int i = res.size() - 1; i >= 0; --i) cout << res[i] << ' ';

}