#include<bits/stdc++.h>
using namespace std;

int p[501010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> l, res;
    vector<pair<int,int>> input(n);
    for (int i = 0; i < n; ++i) cin >> input[i].first >> input[i].second;
    sort(input.begin(), input.end());
    for (int i = 0; i < n; ++i) {
        int x = input[i].second;
        if (i == 0 || l.back() < x) p[i] = l.size(), l.push_back(x);
        else {
            int idx = lower_bound(l.begin(), l.end(), x) - l.begin();
            p[i] = idx; l[idx] = x;
        }
    }
    cout << n - l.size() << '\n';
    for (int i = n - 1, t = l.size() - 1; i >= 0; --i) {
        if (p[i] == t) res.push_back(input[i].first), --t;
    }
    int i = res.size() - 1;
    for (auto o : input) {
        if (o.first == res[i]) --i;
        else cout << o.first << '\n';
    }

}