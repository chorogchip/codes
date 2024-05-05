#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

ll ccw(const pii &p1, const pii &p2, const pii &p3) {
    return (ll)(p2.x - p1.x) * (p3.y - p1.y) - (ll)(p3.x - p1.x) * (p2.y - p1.y);
}

int ccwn(const pii &p1, const pii &p2, const pii &p3) {
    ll res = (ll)(p2.x - p1.x) * (p3.y - p1.y) - (ll)(p3.x - p1.x) * (p2.y - p1.y);
    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}

bool intersect(pii a, pii b, pii c, pii d) {
    int ab = ccwn(a, b, c) * ccwn(a, b, d);
    int cd = ccwn(c, d, a) * ccwn(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

void sort_angle(pii origin, int n, pii* d) {  // order: 4 1 2 3
    sort(d, d + n, [&](pii a, pii b){
        if((a>origin)^(b>origin)) return a>b;
        if (ll t=ccw(origin,a,b)) return t>0;
        return abs(a.x-origin.x)<abs(b.x-origin.x);
    });
}

vector<pii> convex_hull(int n, pii* d) {
    vector<pii> res;

    int yi = 0;
    for (int i = 0; i < n; ++i)
        if (d[i].y < d[yi].y || d[i].y == d[yi].y && d[i].x < d[yi].x)
            yi = i;
    swap(d[yi], d[n-1]);
    pii o = d[n-1];
    sort_angle(o, n-1, d);
    res.push_back(o); res.push_back(d[0]);
    for (int i = 1; i < n; ++i) {
        while (res.size() >= 2 && ccw(res[res.size()-2],res[res.size()-1],d[i])<=0)
            res.pop_back();
        res.push_back(d[i]);
    }
    res.pop_back();

    return res;
}

pair<pii, double> rotating_calipers(int n, pii* cvx) {
    double res = 0.0;
    pii resp;
    int a = 0, b = 1, c = 0, d = 1;
    while(1) {
        int dx = cvx[a].x-cvx[c].x;
        int dy = cvx[a].y-cvx[c].y;
        double dist = (double)dx*dx+(double)dy*dy;
        if (dist > res) res = dist, resp = {a, c}; 
        if (ccw(cvx[a],cvx[b],{cvx[d].x-cvx[c].x+cvx[a].x,cvx[d].y-cvx[c].y+cvx[a].y})>0) {
            c = ++c % n;
            d = ++d % n;
        } else {
            b = ++b % n;
            a = ++a % n;
            if (a==0) break;
        }
    }
    return {resp, sqrt(res)};
}

int main() {

}