#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, p; cin >> n >> p;
    int prev = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x - prev != 0 && x - prev != 1) goto NO;
        if (x < i/p+1) goto NO;
        if (x > (n+p-1)/p) goto NO;
        prev = x;
    }
    cout << "YES"; exit(0);
    NO: cout << "NO";
}