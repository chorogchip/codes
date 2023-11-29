#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

#include <utility>
#define x first
#define y second

using ll = long long;
using pll = pair<ll, ll>;

ll ccw(pll a, pll b, pll c) {
    ll ans =  (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
    if (ans > 0) return 1;
    else if (ans < 0) return -1;
    else return 0; 
}
bool check(pll a, pll b, pll c, pll d) {
    ll abc = ccw(a, b, c);
    ll abd = ccw(a, b, d);
    ll cda = ccw(c, d, a);
    ll cdb = ccw(c, d, b);
    if (abc * abd == 0 && cda * cdb == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return abc * abd <= 0 && cda * cdb <= 0; 
}
struct Baegi {
    pll a, b;
    ll w;
} B[3000];
int N;
ll S;
int main() { FAST
    cin >> N;
    fore (i, N) {
        cin >> B[i].a.x >> B[i].a.y >>
        B[i].b.x >> B[i].b.y >> 
        B[i].w;
    }
    sort(B, B + N, [](const Baegi& b1, const Baegi& b2)->bool{
        return b1.w < b2.w;
    });
    for (int i = 0; i < N; ++i) {
        ll m = 1LL;
        for (int j = i + 1; j < N; ++j)
            if (check(B[i].a, B[i].b, B[j].a, B[j].b)) ++m;
        S += m * B[i].w;
    }
    cout << S;
}
