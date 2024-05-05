#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        while (!v.empty() && v.back().second <= x) v.pop_back();
        cout << (v.empty() ? 0 : v.back().first) << ' ';
        v.push_back({i, x});
    }
}