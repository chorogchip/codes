#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

using ll = long long;
using pii = pair<ll, ll>;

ll cross(const pii &p1, const pii &p2, const pii &p3) {
    return (ll)(p2.x - p1.x) * (p3.y - p1.y) - (ll)(p3.x - p1.x) * (p2.y - p1.y);
}
int CCW(const pii &p1, const pii &p2, const pii &p3) {
    ll z = cross(p1, p2, p3);
    return (z > 0) - (z < 0);
}

bool Cross(pii a, pii b, pii c, pii d) {
    int ab = CCW(a, b, c) * CCW(a, b, d);
    int cd = CCW(c, d, a) * CCW(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return ab <= 0 && cd <= 0;
}

int p[3010];
int s[3010];
pair<pii,pii> d[3010];

int par(int i) {
    if (p[i] == i) return i;
    else return par(p[i]);
}

void merge(int a, int b) {
    int aa = par(a);
    int bb = par(b);
    if (aa == bb) return;
    if (s[aa] > s[bb]) swap(aa, bb);
    p[aa] = bb;
    s[bb] += s[aa];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        s[i] = 1;
        cin >> d[i].x.x >> d[i].x.y >> d[i].y.x >> d[i].y.y;
        for (int j = 1; j < i; ++j)
            if (Cross(d[i].x, d[i].y, d[j].x, d[j].y))
                merge(i, j);
    }
    int sz = 0;
    int g = 0;
    for (int i = 1; i <= n; ++i) if (p[i] == i) {
        sz = max(sz, s[i]);
        ++g;
    }
    cout << g << '\n' << sz;
}

