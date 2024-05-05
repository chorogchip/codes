#pragma GCC target("lzcnt")
#include <bits/stdc++.h>
#include <bit>
#include <bitset>
#include <immintrin.h>
#include <chrono>

// upper_bound(log2(x)) = N - LDZ(x - 1) (1 <= x <= 2^N - 1)
// lower_bound(log2(x)) = N - 1 - LDZ(x) (1 <= x <= 2^N - 1)
// SRA(x, l) = SRL(x + 2^(N-1), l) - 2^(N-1-l). (0 <= l <= N-1)
// MULUH(x, y) = MULSH(x, y) + AND(x, XSIGN(y)) + AND(y, XSIGN(x)) (XGISN(x) = -1 if x < 0 else 0)

struct RECIP {
    unsigned sh1, sh2, m_;
};

constexpr RECIP get_reciprocal(unsigned d) {
    RECIP result{};
    constexpr unsigned N = sizeof(unsigned) * 8;
    int l = N - std::countl_zero(d - 1);
    result.m_ = ((1ULL<<l) - d << N) / d + 1ULL;
    result.sh1 = std::min(l, 1);
    result.sh2 = std::max(l - 1, 0);
    return result;
}

constexpr inline unsigned divide(unsigned n, RECIP const &rcp) {
    constexpr unsigned N = sizeof(unsigned) * 8;
    unsigned t1 = (unsigned long)rcp.m_ * (unsigned long)n >> N;
    unsigned q = t1 + (n - t1 >> rcp.sh1) >> rcp.sh2;
    return q;
}

unsigned my_atou(const char *p) {
    unsigned result = 0;
    do result = result * 10 + *p++ - '0'; while (*p >= '0');
    return result;
}

#pragma GCC target("avx2")
char *u_to_str(char *dest, unsigned d) {
    char arr[12];
    arr[11] = '\0';
    char *p = arr + 10;
    do {
        unsigned t1 = d * 2576980378ULL >> 32ULL;
        unsigned q = t1 + (d - t1 >> 1);
        *p-- = d - q - (q >> 2) + 48;
        d = q >> 3;
    } while (d);
    _mm_storeu_si128((__m128i*)dest, _mm_loadu_si128((__m128i*)(p + 1)));
    return dest - p + arr + 10;
}
char *u_to_str2(char *dest, unsigned d) {
    char arr[12];
    arr[11] = '\0';
    char *p = arr + 10;
    do {
        *p-- = d % 10 + 48;
    } while (d /= 10);
    _mm_storeu_si128((__m128i*)dest, _mm_loadu_si128((__m128i*)(p + 1)));
    return dest - p + arr + 10;
}
char *u_to_str3(char *dest, unsigned d) {
    char arr[12];
    arr[11] = '\0';
    char *p = arr + 10;
    do {
        *p-- = d % 10 + 48;
    } while (d /= 10);
    memcpy(dest, p + 1, 12);
    return dest - p + arr + 10;
}
char *u_to_str4(char *dest, unsigned d) {
    char arr[12];
    arr[11] = '\0';
    char *p = arr + 10;
    do {
        *p-- = d % 10 + 48;
    } while (d /= 10);
    memcpy(dest, p + 1, 16);
    return dest - p + arr + 10;
}

long long more_than_l3cache[256 * 1024 * 1024 * 2 / 64];
unsigned data[1000000];
char dest1[sizeof(data)*12], dest2[sizeof(data)*12];

int main() {
    while (true) {
    #if 1
        unsigned d;
        scanf("%u", &d);
        RECIP rcp = get_reciprocal(d);
        printf("rcp: %u %u %u\n", rcp.sh1, rcp.sh2, rcp.m_);
        for (int i = 0, tmp; tmp = rand(), i < 10; ++i)
            printf("%u / %u = %u\n", tmp, d, divide(tmp, rcp));
    #elif 0
        char buf1[256], buf2[256], *p1 = buf1, *p2 = buf2;
        for (int i = 0; i < 10; ++i) {
            unsigned d = rand();
            p1 = u_to_str(p1, d); *p1++ = ' ';
            p2 += sprintf(p2, "%u", d); *p2++ = ' ';
        }
        *p1 = *p2 = '\0';
        printf("%s\n%s\n", buf1, buf2);
        getchar();
    #elif 0
        decltype(std::chrono::high_resolution_clock::now()) begin, end;
        decltype(std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()) f1_time = 0, f2_time = 0;
        for (int k = 0; k < 10; ++k) {
            for (int i = 0; i < sizeof(data)/sizeof(data[0]); ++i) data[i] = rand();
            char *p1 = dest1, *p2 = dest2;
            
            for (int i = 0; i < sizeof(more_than_l3cache)/sizeof(more_than_l3cache[0]); ++i) more_than_l3cache[i]++;
            begin = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < sizeof(data)/sizeof(data[0]); ++i) p1 = u_to_str3(p1, data[i]);
            end = std::chrono::high_resolution_clock::now();
            f1_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
            
            for (int i = 0; i < sizeof(more_than_l3cache)/sizeof(more_than_l3cache[0]); ++i) more_than_l3cache[i]++;
            begin = std::chrono::high_resolution_clock::now();
            //for (int i = 0; i < sizeof(data)/sizeof(data[0]); ++i) p2 += sprintf(dest2, "%u", data[i]);
            for (int i = 0; i < sizeof(data)/sizeof(data[0]); ++i) p1 = u_to_str4(p1, data[i]);
            end = std::chrono::high_resolution_clock::now();
            f2_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        }
        printf("%ld %ld\n", f1_time, f2_time);
    #elif 0
        auto o = get_reciprocal(900528);
        std::cout << o.m_ << ' ' << o.sh1 << ' ' << o.sh2;
        break;
    #endif
    }
}



