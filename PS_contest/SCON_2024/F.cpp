
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a, b;
    int i = n;
    for (; i >= 3; i -= 3) {
        a.push_back(i);
        b.push_back(i-1);
        b.push_back(i-2);
    }
    if (i == 2) {
        a.push_back(2);
        b.push_back(1);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << a.size() << '\n';
    for (auto o : a) cout << o << ' '; cout << '\n';
    cout << b.size() << '\n';
    for (auto o : b) cout << o << ' '; cout << '\n';
}