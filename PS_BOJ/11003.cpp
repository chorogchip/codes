#include <bits/stdc++.h>
using namespace std;

pair<int,int> d[5010101];
char buf[1<<19];

int main() {
    int n = 0, l = 0, sz = 0, st = 0;
    fread(buf, 1, sizeof(buf), stdin);
    const char *rp = buf;
    do n = n * 10 + *rp++ - '0'; while (*rp >= '0'); ++rp;
    do l = l * 10 + *rp++ - '0'; while (*rp >= '0'); ++rp;
    for (int i = 1; i <= n; ++i) {
        if (rp >= buf + sizeof(buf) - 100) {
            int remsz = buf + sizeof(buf) - rp;
            memcpy(buf, rp, remsz);
            rp = buf;
            fread(buf, 1, sizeof(buf) - remsz, stdin);
        }
        int x = 0;
        if (*rp != '-') { do x = x * 10 + *rp++ - '0'; while (*rp >= '0'); }
        else { ++rp;      do x = x * 10 - *rp++ + '0'; while (*rp >= '0'); }
        ++rp;
        while (sz && d[st+sz-1].second >= x) --sz;
        d[st+sz] = {i, x}; ++sz;
        if (d[st].first <= i - l) ++st, --sz;
        printf("%d ", d[st].second);
    }
}