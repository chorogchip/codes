#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

//  반시계인지
ll ccw(const pii &p1, const pii &p2, const pii &p3) {
    return (ll)(p2.x - p1.x) * (p3.y - p1.y) - (ll)(p3.x - p1.x) * (p2.y - p1.y);
}

int main(void) {
    while (true)
    {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        cout << ccw({a, b}, {c, d}, {e, f}) << endl;
    }
}