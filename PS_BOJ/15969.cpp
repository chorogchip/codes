#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m = 1'000'000, M =-1;
    while(n--) {
        int x; cin >> x;
        m = min(m, x);
        M = max(M, x);
    }
    cout << M - m;
}