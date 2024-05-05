#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, g, f, e; cin >> n >> f >> e;
    e -= f;
    g = e;
    for (int i = 2; i < n; ++i) {
        cin >> e; e -= f;
        g = gcd(g, e);
    }
    cout << e / g + 1 - n;
}