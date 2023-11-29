#include <bits/stdc++.h>
using namespace std;

int d[301010], lmax[301010], rmax[301010], lmin[301010], rmin[301010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    stack<pair<int,int>> lsmax, rsmax, lsmin, rsmin;
    for (int i = 1; i <= n; ++i) {
        while (!lsmax.empty() && lsmax.top().second < d[i]) lsmax.pop();
        lmax[i] = lsmax.empty() ? i : i - lsmax.top().first;
        lsmax.push({i, d[i]});

        while (!lsmin.empty() && lsmin.top().second > d[i]) lsmin.pop();
        lmin[i] = lsmin.empty() ? i : i - lsmin.top().first;
        lsmin.push({i, d[i]});
    }
    for (int i = n; i > 0; --i) {
        while (!rsmax.empty() && rsmax.top().second <= d[i]) rsmax.pop();
        rmax[i] = rsmax.empty() ? n + 1 - i : rsmax.top().first - i;
        rsmax.push({i, d[i]});

        while (!rsmin.empty() && rsmin.top().second >= d[i]) rsmin.pop();
        rmin[i] = rsmin.empty() ? n + 1 - i : rsmin.top().first - i;
        rsmin.push({i, d[i]});
    }
    long long sum = 0LL;
    for (int i = 1; i <= n; ++i) {
        sum += (long long)lmax[i] * rmax[i] * d[i];
        sum -= (long long)lmin[i] * rmin[i] * d[i];
    }
    cout << sum;
}