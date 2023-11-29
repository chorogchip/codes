#include<bits/stdc++.h>
using namespace std;

int a[101010], b[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[x-1] = i;
    }
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b[i] = a[x-1];
    }
    vector<int> l;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || l.back() < b[i]) l.push_back(b[i]);
        else l[lower_bound(l.begin(), l.end(), b[i]) - l.begin()] = b[i];
    }
    cout << l.size();
}