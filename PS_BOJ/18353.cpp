#include<bits/stdc++.h>
using namespace std;

int a[2010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> l;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; x = -x;
        if (i == 0 || l.back() < x) l.push_back(x);
        else {
            int idx = lower_bound(l.begin(), l.end(), x) - l.begin();
            l[idx] = x;
        }
    }
    cout << n - l.size();
}