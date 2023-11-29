#include<bits/stdc++.h>
using namespace std;

int a[40101];

int main() {
    int n; cin >> n;
    vector<int> l;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0 || l.back() < a[i]) l.push_back(a[i]);
        else {
            int idx = lower_bound(l.begin(), l.end(), a[i]) - l.begin();
            l[idx] = a[i];
        }
    }
    cout << l.size();
}