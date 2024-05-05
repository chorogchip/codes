#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    int a = 0, b = 0, c = 0;
    while(t - 300 >= 0) t -= 300, ++a;
    while(t - 60 >= 0) t -= 60, ++b;
    while(t - 10 >= 0) t -= 10, ++c;
    if (t != 0) {
        cout << -1; exit(0);
    }
    cout << a << ' ' << b << ' ' << c;
}