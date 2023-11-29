#pragma GCC target("avx2")
#include <immintrin.h>
#include <bits/stdc++.h>
using namespace std;
#define XM __attribute__ ((aligned(16)))

char buf[1110101];

int main() {

    XM char input_xmm[16];  // 4cnt, 1len, 11char
    input_xmm[0] = '\n';
    for (int i = 1; i < 11; ++i) input_xmm[i] = '|';
    *(int *)&input_xmm[12] = 1;
    __m128i initial_val = _mm_load_si128((__m128i *)input_xmm);
    int N = 0, M = 0;
    int buf_c = 0;
    fread(buf, 1, sizeof(buf), stdin);
    do N = N * 10 + buf[buf_c++] - '0'; while (buf[buf_c] >= '0'); ++buf_c;
    do M = M * 10 + buf[buf_c++] - '0'; while (buf[buf_c] >= '0'); ++buf_c;
    

    for (int i = 0; i < N; ++i) {
        _mm_store_si128((__m128i *)input_xmm, initial_val);
        int prev_buf = buf_c++;
        while (buf[buf_c++] >= 'a');
        int j;
        int size = buf_c - prev_buf - 1;
        input_xmm[11] = size;
        for (j = 1; j <= size; ++j) {
            input_xmm[j] = buf[buf_c - j - 1];
        }

        int k = 15;
        for (; k >= 11; --k) printf("%02x", input_xmm[k]);
        for (; k >= 0; --k) printf("%c", input_xmm[k]);
    }

}