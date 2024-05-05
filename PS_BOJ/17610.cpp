#include<bits/stdc++.h>
using namespace std;

bool arr[13*201010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k; cin >> k;
    int s = 0;
    vector<int> v;
    v.push_back(0);
    for (int i = 0; i < k; ++i) {
        int x; cin >> x; s += x;
        int sz = v.size();
        for (int j = 0; j < sz; ++j) v.push_back(v[j]+x), v.push_back(v[j]-x);
    }
    int res = s;
    for (auto o : v) if (0 < o && o <= s && !arr[o]) arr[o] = 1, --res;
    cout << res;
}