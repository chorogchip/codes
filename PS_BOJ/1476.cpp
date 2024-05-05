#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int e, s, m; cin >> e >> s >> m;
    int a = 1, b = 1, c = 1, n = 1;
    while(1) {
        if (a == e && b == s && c == m) {
            cout << n; exit(0);
        }
        ++a; ++b; ++c; ++n;
        if (a > 15) a = 1;
        if (b > 28) b = 1;
        if (c > 19) c = 1;
    }
}