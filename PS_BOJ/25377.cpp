#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int res = 10'000;
    while(n--) {
        int a, b; cin >> a >> b;
        if (a <= b) res = min(res, b);
    }
    if (res == 10'000) res = -1;
    cout << res;
}