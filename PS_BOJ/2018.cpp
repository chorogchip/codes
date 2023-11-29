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

typedef long long ll;
ll N, R = 1;

int main() { FAST
    cin >> N;
    for (ll i = 1; i * i + i >> 1 <= N; ++i) {
        ll lo = 1, md, hi = N >> 1;
        while (lo < hi) {
            md = lo + hi >> 1;
            ll hh = md-- + i;
            ll x = hh * hh + hh - md * md - md >> 1;
            if (N > x) lo = md + 2;
            else hi = md + 1;
        }
        ll hh = lo-- + i;
        if (hh * hh + hh - lo * lo - lo >> 1 == N) ++R;
    }
    cout << R;
}
