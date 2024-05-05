#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= n; ++i) if (n % i == 0) v.push_back(i);
    if (v.size() > k-1) cout << v[k-1];
    else cout << 0;
}