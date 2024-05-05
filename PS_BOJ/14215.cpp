#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b, c; cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    c = min(c, a + b - 1);
    cout << a + b + c;
}