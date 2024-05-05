#include<bits/stdc++.h>
using namespace std;

int cnt[1010101], a[1010101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x; a[i] = x; cnt[x]++;
    }
    vector<pair<int,int>> v; v.reserve(n);
    vector<int> ans; ans.reserve(n);
    for (int i = n; i >= 1; --i) {
        int num = a[i];
        int c = cnt[num];
        while (!v.empty() && v.back().first <= c) v.pop_back();
        ans.push_back(v.empty() ? -1 : v.back().second);
        v.push_back({c, num});
    }
    reverse(ans.begin(), ans.end());
    for (auto o : ans) cout << o << ' ';
}