#include<bits/stdc++.h>
using namespace std;

int d[12800];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int s = 0, dm = 0, dd = 0;
    for (int i = 0; i < 10; ++i) {
        int x; cin >> x; s += x;
        if (++d[x] > dm) dm = d[x], dd = x;
    }
    cout << s/10 << '\n' << dd;
}