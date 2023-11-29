#include <bits/stdc++.h>
using namespace std;

char buf[1<<21], *p = buf;

int main() {
    fread(buf, 1, sizeof(buf), stdin);
    int dd[1002], *d = dd + 1, rs[1001], rssz = 0;
    rs[0] = -1;
    while (true) {
        int n = 0, m = 0, mm = 0;
        do n = n * 10 + *p++ - '0'; while (*p >= '0'); ++p;
        do m = m * 10 + *p++ - '0'; while (*p >= '0'); ++p;
        if (n == 0) break;
        if (p >= buf + sizeof(buf) + 10 - n * m * 2) {
            int sz = buf + sizeof(buf) - p;
            memcpy(buf, p, sz);
            fread(buf + sz, 1, sizeof(buf) - sz, stdin);
            p = buf;
        }
        memset(dd, 0, sizeof(dd));
        for (int y = 0; y < n; ++y) {
            rssz = 0;
            for (int x = 0; x < m; ++x) {
                int data = '0' - p[(y * m + x) << 1];
                d[x] = (d[x] & data) - data;
                while (d[rs[rssz]] > d[x]) {
                    int xx = rs[rssz];
                    rssz--;
                    int sqsz = d[xx] * (x - rs[rssz] - 1);
                    if (mm < sqsz) mm = sqsz;
                }
                rs[++rssz] = x;
            }
            for (int x = 1, sz = rssz, prvxx = -1; x <= sz; ++x) {
                int xx = rs[x];
                int sqsz = d[xx] * (m - prvxx - 1);
                prvxx = xx;
                if (mm < sqsz) mm = sqsz;
            }
        }
        p += m * n << 1;
        printf("%d\n", mm);
    }
}