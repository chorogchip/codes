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
ll N, K;

int main() { FAST
    cin >> N >> K;
    ll lo = 1, md, hi = N * N, s;
    while (lo < hi) {
        md = lo + hi >> 1;
        s = 0;
        for (ll i = 1; i <= N; ++i) s += min(N, md / i);
        if (K > s) lo = md + 1;
        else hi = md;
    }
    cout << lo;
}
