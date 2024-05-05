#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a += (x + 30) / 30 * 10;
        b += (x + 60) / 60 * 15;
    }
    if (a < b) {
        cout << "Y " << a;
    } else if (a > b) {
        cout << "M " << b;
    } else {
        cout << "Y M " << a;
    }
}