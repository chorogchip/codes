#include<bits/stdc++.h>
using namespace std;

int d[10101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (n - i == 3) {
            
            continue;
        }
        int a = min(d[i], min(d[i+1], d[i+2]));
        res += a * 7;
        d[i] -= a;
        d[i+1] -= a;
        d[i+2] -= a;
        int b = min(d[i], d[i+1]);
        res += b * 5;
        d[i] -= b;
        d[i+1] -= b;
        int c = d[i];
        res += c * 3;
        d[i] -= c;
    }
    cout << res;
}