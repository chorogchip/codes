#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (true) {
        long long x; cin >> x;
        if (x == 0) break;
        cout << x * (x+1) / 2 << '\n';
    }
}