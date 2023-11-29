#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Point = pair<ll, ll>;
#define x first
#define y second

int main(void) {
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll z = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    cout << (z > 0) - (z < 0);
}