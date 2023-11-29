#include <bits/stdc++.h>
using namespace std;

pair<int,pair<int,int>> a[10101];
int p[10101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; --x;
        a[x].first = i;
    }
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; --x;
        a[x].second.first = i;
        a[x].second.second = x;
    }
    sort(a, a + n);

    vector<int> l;
    for (int i = 0; i < n; ++i) {
        int x = a[i].second.first;
        if (i == 0 || l.back() < x) p[i] = l.size(), l.push_back(x);
        else {
            int idx = lower_bound(l.begin(), l.end(), x) - l.begin();
            p[i] = idx, l[idx] = x;
        }
    }
    vector<int> res;
    for (int i = n - 1, t = l.size() - 1; i >= 0; --i) {
        if (p[i] == t) res.push_back(a[i].second.second+1), --t;
    }
    cout << l.size() << '\n';
    sort(res.begin(), res.end());
    for (auto o : res) cout << o << ' ';
}