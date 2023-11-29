#include<bits/stdc++.h>
using namespace std;

int heap[380000];

int main() {
    int N, T, P, S = 0, sz = 0;
    char *p = (char*)heap + 200002;
    scanf("%d%d%d", &N, &T, &P);
    fread((char*)heap + 200001, 1, sizeof(heap) - 200001, stdin);
    for (int i = 0; T > 0 && i < N; ++i, T -= P) {
        int X = 0, v_min, v_nx;
        do X = X * 10 + *p++ - '0'; while (*p >= '0'); ++p;
        if (X <= T - S) {
            ++sz;
            S += X;
            heap[sz] = X;
            for (int i = sz; i > 1; i >>= 1)
                if (heap[i] > heap[i>>1]) swap(heap[i], heap[i>>1]);
                else break;
            continue;
        } else if (heap[1] > X) {
            S -= heap[1];
            S += X;
            heap[1] = X;
            for (int i = 1, ch = 2; ch <= sz; ) {
                if (ch + 1 <= sz && heap[ch + 1] > heap[ch]) ++ch;
                if (heap[ch] > heap[i]) swap(heap[ch], heap[i]), i = ch, ch += ch;
                else break;
            }
        }
    }
    printf("%d", sz);
}
