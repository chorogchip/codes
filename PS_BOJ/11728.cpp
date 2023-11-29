#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")

#include <stdio.h>
#include <stdbool.h>

constexpr int SZ = 1<<19;
char buf[23000000], bbuf[SZ + 100];
signed char A[1000001];

int main() {
    int a = 0, b = 0;
    char *p;
    p = buf + fread(buf, 1, sizeof(buf), stdin);
    *(p - 1) = ' ';
    *(long long*)p = 0x3939393939393939L;
    *(long long*)(p + 8) = 0x3939393939393939L;
    *(p + 9) = ' ';
    p = buf;
    do a = a * 10 + *p++ - '0'; while (*p >= '0'); ++p;
    do b = b * 10 + *p++ - '0'; while (*p >= '0'); ++p;
    char *buf_ap = p;
    {
        int i = 0;
        for (; i < a; ++i) {
            if (*p != '-') break;
            signed char cnt = 0;
            do --cnt, ++p; while (*p >= '0');
            --cnt, ++p;
            A[i] = cnt;
        }
        signed char cnt_go = 1;
        for (; i < a; ++i) {
            signed char cnt = cnt_go;
            p += cnt_go;
            while (*p >= '0') ++cnt, ++p;
            cnt_go = cnt;
            ++cnt, ++p;
            A[i] = cnt;
        }
    }
    *(p - 1) = ' ';

    A[a] = 100;
    signed char bpv;
    {
        bpv = 0;
        bool is_min = *p == '-';
        do ++bpv, ++p; while (*p >= '0');
        ++bpv, ++p;
        p -= bpv;
        if (is_min) bpv = -bpv;
    }
    signed char *ap = A;
    char *pp = bbuf;
    for (int i = a + b; i > 0; --i) {
        if (pp > bbuf + SZ)
            fwrite(bbuf, sizeof(char), pp - bbuf, stdout), pp = bbuf;
        if (*ap < bpv) {
            AA:
            signed char cnt = *ap++;
            if (cnt < 0) cnt = -cnt;
            long long ll1 = *(long long*)buf_ap;
            long long ll2 = *(long long*)(buf_ap+8);
            *(long long*)pp = ll1;
            *(long long*)(pp+8) = ll2;
            buf_ap += cnt;
            pp += cnt;
        } else if (*ap > bpv) {
            BB:
            if (bpv < 0) bpv = -bpv;
            long long ll1 = *(long long*)p;
            long long ll2 = *(long long*)(p+8);
            *(long long*)pp = ll1;
            *(long long*)(pp+8) = ll2;
            p += bpv;
            pp += bpv;
            {
                bpv = 0;
                bool is_min = *p == '-';
                do ++bpv, ++p; while (*p >= '0');
                ++bpv, ++p;
                p -= bpv;
                if (is_min) bpv = -bpv;
            }
        } else {
            int j;
            if (bpv < 0) { j = 1;
                do if (buf_ap[j] > p[j]) goto AA;
                else if (buf_ap[j] < p[j]) goto BB;
                while (p[++j] >= '0');
            } else { j = 0;
                do if (buf_ap[j] < p[j]) goto AA;
                else if (buf_ap[j] > p[j]) goto BB;
                while (p[++j] >= '0');
            }
            ++ap;
            if (bpv < 0) bpv = -bpv;
            long long ll1 = *(long long*)p;
            long long ll2 = *(long long*)(p+8);
            *(long long*)pp = ll1;
            *(long long*)(pp+8) = ll2;
            pp += bpv;
            *(long long*)pp = ll1;
            *(long long*)(pp+8) = ll2;
            p += bpv;
            buf_ap += bpv;
            pp += bpv;
            --i;
            {
                bpv = 0;
                bool is_min = *p == '-';
                do ++bpv, ++p; while (*p >= '0');
                ++bpv, ++p;
                p -= bpv;
                if (is_min) bpv = -bpv;
            }
        }
    }
    fwrite(bbuf, sizeof(char), pp - bbuf, stdout);
    return 0;
}