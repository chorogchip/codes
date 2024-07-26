#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b; cin >> a >> b;
    if (a < b) {
        cout << -1; exit(0);
    }
    int c = a+b, d = a-b;
    if ((c&1) || (d&1)){
        cout << -1; exit(0);
    }
    c/=2; d/=2;
    cout << c << ' ' << d;
}