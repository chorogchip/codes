#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        int a[3]; cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        int cost;
        if (a[0] == a[1] && a[1] == a[2]) cost = 10'000 + a[0] * 1000;
        else if (a[0] == a[1] || a[1] == a[2]) cost = 1000 + a[1] * 100;
        else cost = a[2] * 100;
        ans = max(ans, cost);
    }
    cout << ans;
}