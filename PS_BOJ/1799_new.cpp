#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int ans(int sz, ll* v) {
    if (sz == 0) return 0;
    int res = ans(sz - 1, v + 1);
    vector<ll> vec;
    for (int i = 1; i < sz; ++i)
        if ((v[i] & v[0]) == 0) vec.push_back(v[i]);
    res = max(res, ans(vec.size(), &vec[0]) + 1);
    return res;
}

int main() {
    int n = 0;
    vector<ll> vec[2];
    char buf[10*10*2+10], *p = buf;
    fread(buf, 1, sizeof(buf), stdin);
    do { n = n * 10 + *p++ - '0';} while (*p != '\n'); ++p;
    for (int y = 1; y <= n; ++y)
    for (int x = 1; x <= n; ++x) {
        if (*p == '1')
            vec[x+y&1].push_back(1LL<<(ll)(x+y) | 1LL<<(ll)(x-y+30));
        p += 2;
    }
    printf("%d", ans(vec[0].size(), &vec[0][0]) + ans(vec[1].size(), &vec[1][0]));
}