#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int r, e, c; cin >> r >> e >> c;
        if (r == e - c) cout << "does not matter\n";
        else if (r < e - c) cout << "advertise\n";
        else cout << "do not advertise\n";
    }
}