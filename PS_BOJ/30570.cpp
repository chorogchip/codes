#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b, c; cin >> a >> b >> c;
    int res = a * 2;
    if (c >= 2) c -= 2, res += b * 2 + 3;
    res += c/2*3;
    cout << res;
}