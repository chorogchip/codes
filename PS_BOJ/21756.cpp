#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 1; i <= n; ++i) v[i-1] = i;
    while (v.size() != 1) {
        vector<int> v2;
        for (int i = 1; i < v.size(); i += 2) v2.push_back(v[i]);
        v = v2;
    }
    cout << v[0];
}