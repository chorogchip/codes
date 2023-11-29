#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Point = pair<ll, ll>;
#define x first
#define y second

//  반시계인지
int CCW(const Point &p1, const Point &p2, const Point &p3) {
    ll z = p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
    return (z > 0) - (z < 0);
}

int main(void) {
    while (true)
    {
        ll a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        cout << CCW({a, b}, {c, d}, {e, f}) << endl;
    }
}