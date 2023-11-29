#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

int ccw(pii a1, pii a2, pii a3) {
    ll c =
        (ll)a1.x*a2.y-(ll)a1.y*a2.x+
        (ll)a2.x*a3.y-(ll)a2.y*a3.x+
        (ll)a3.x*a1.y-(ll)a3.y*a1.x; 
    if (c > 0) return 1;
    if (c < 0) return -1;
    return 0;
}

pii D[101010];
vector<pii> res;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int low_y_ind = 0;
    for (int i = 0; i < n; ++i) {
        cin >> D[i].x >> D[i].y;
        if (D[i].y < D[low_y_ind].y || D[i].y == D[low_y_ind].y && D[i].x < D[low_y_ind].x)
            low_y_ind = i;
    }
    swap(D[low_y_ind], D[n-1]);
    pii o = D[n-1];
    sort(D, D + n - 1, [&](pii a, pii b){
        if((a>o)^(b>o)) return a>b;
        if (int t=ccw(o,a,b)) return t>0;
        return abs(a.x-o.x)<abs(b.x-o.x);
    });
    res.push_back(o);
    res.push_back(D[0]);

    for (int i = 1; i < n; ++i) {
        while (res.size() >= 2 && ccw(res[res.size()-2],res[res.size()-1],D[i])<=0)
            res.pop_back();
        res.push_back(D[i]);
    }
    res.pop_back();
    cout << res.size();
}

