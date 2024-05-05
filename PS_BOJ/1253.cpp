#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (auto& o : v) cin >> o;
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) if (j != i) {
        int target = v[i] - v[j];
        int ind = lower_bound(v.begin(), v.end(), target) - v.begin();
        if (ind == i || ind == j) ++ind;
        if (ind == i || ind == j) ++ind;
        if (ind < n && v[ind] == target) {++cnt; break;}
    }
    cout << cnt;
}