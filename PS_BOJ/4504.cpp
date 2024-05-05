#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while(true) {
        int x; cin >> x;
        if (x == 0) break;
        if (x % n == 0) cout << x << " is a multiple of " << n << ".\n";
        if (x % n != 0) cout << x << " is NOT a multiple of " << n << ".\n";
    }
}