#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using Point = pii;
#define x first
#define y second

//  반시계인지
ll cross(const pii &p1, const pii &p2, const pii &p3) {
    return (ll)(p2.x - p1.x) * (p3.y - p1.y) - (ll)(p3.x - p1.x) * (p2.y - p1.y);
}
int CCW(const pii &p1, const pii &p2, const pii &p3) {
    ll z = cross(p1, p2, p3);
    return (z > 0) - (z < 0);
}

// 선분 ab, cd 교차
bool Cross(Point a, Point b, Point c, Point d) {
    int ab = CCW(a, b, c) * CCW(a, b, d);
    int cd = CCW(c, d, a) * CCW(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a < d && c < b;
    }
    return ab <= 0 && cd <= 0;
}

// 다각형 내부에 있는지
bool Check(const vector<pii> &v, pii p1) {
    constexpr ll MAX_COORD = 1e9;
    int n = v.size() - 1, cnt = 0;
    Point p2(MAX_COORD + 1, p1.y + 1);
    for (int i = 0; i < n; ++i)
        cnt += Cross(v[i], v[i + 1], p1, p2);
    cnt += Cross(v[n - 1], v[0], p1, p2);
    return cnt & 1;
}

int main() {
    Point a, b, c, d;
    while (
        scanf("%d%d%d%d%d%d%d%d",
            &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y) &&
        printf("%d\n", (int)Cross(a, b, c, d))
    );
}