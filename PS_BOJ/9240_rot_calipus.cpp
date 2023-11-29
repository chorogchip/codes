#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define x first
#define y second
pii D[101010];

int ccw(pii a1, pii a2, pii a3) {
    ll c =
        (ll)a1.x*a2.y-(ll)a1.y*a2.x+
        (ll)a2.x*a3.y-(ll)a2.y*a3.x+
        (ll)a3.x*a1.y-(ll)a3.y*a1.x;
    if (c > 0) return 1;
    if (c < 0) return -1;
    return 0;
}

int main() {
    double res = 0.0;
    int n; cin >> n;
    int lowi = 0;
    for (int i = 0; i < n; ++i) {
        cin >>D[i].x >> D[i].y;
        if (D[i].y < D[lowi].y || D[i].y == D[lowi].y && D[i].x < D[lowi].x)
            lowi = i;
    }
    swap(D[lowi], D[n-1]);
    auto o = D[n-1];
    sort(D, D + n - 1, [&](pii a, pii b) {
        if (int t = ccw(o, a, b)) return t>0;
        return abs(o.x-a.x)<abs(o.x-b.x);
    });
    vector<pii> cvx;
    cvx.push_back(D[n-1]);
    cvx.push_back(D[0]);
    for (int i = 1; i < n; ++i) {
        if (i<n-1||cvx.size()!=2)
        while (cvx.size()>=2&&ccw(cvx[cvx.size()-2],cvx.back(),D[i])<=0) cvx.pop_back();
        cvx.push_back(D[i]);
    }
    cvx.pop_back();
    int a = 0, b = 1, c = 0, d = 1;
    while(1) {
        int dx = cvx[a].x-cvx[c].x;
        int dy = cvx[a].y-cvx[c].y;
        res = max(res, sqrt((double)dx*dx+(double)dy*dy));
        if (ccw(cvx[a],cvx[b],{cvx[d].x-cvx[c].x+cvx[a].x,cvx[d].y-cvx[c].y+cvx[a].y})>0) {
            c = ++c % cvx.size();
            d = ++d % cvx.size();
        } else {
            b = ++b % cvx.size();
            a = ++a % cvx.size();
            if (a==0) break;
        }
    }
    printf("%f", res);
}