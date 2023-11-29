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

constexpr inline int g0(int n) {
    int i = 5, r = 0;
    do r += n /= i; while (n);
    return r;
}

int main() { FAST
    int n; cin >> n;
    int lo = max(0, (n>>2)-1), md, hi = n*5;
    while (lo < hi) {
        md = lo + hi >> 1;
        if (n > g0(md)) lo = md + 1;
        else hi = md;
    }
    if (n == g0(lo)) cout << lo << endl;
    else cout << -1 << endl;
}
