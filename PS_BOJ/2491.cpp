#include <bits/stdc++.h>
using namespace std;;

int main() {
    int n; cin >> n;
    int res = 0;
    int preva = 0;
    int prevd = 9;
    int prevalen = 0;
    int prevdlen = 0;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        if (x >= preva) preva = x, res = max(res, ++prevalen);
        else preva = x, prevalen = 1;
        if (x <= prevd) prevd = x, res = max(res, ++prevdlen);
        else prevd = x, prevdlen = 1;
    }
    cout << res;
}