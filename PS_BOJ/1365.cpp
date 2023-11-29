#include<bits/stdc++.h>
using namespace std;

int a[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> l;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (i == 0 || l.back() < x) l.push_back(x);
        else {
            int idx = lower_bound(l.begin(), l.end(), x) - l.begin();
            l[idx] = x;
        }
    }
    cout << n - l.size();
}