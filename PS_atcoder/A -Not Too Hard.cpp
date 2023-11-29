#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        int xx; cin >> xx;
        if (xx <= x) s += xx;
    }
    cout << s;
}