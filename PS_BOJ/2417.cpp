#include<cstdio>
#include<cmath>
#include<limits>

unsigned long long my_min(unsigned long long a, unsigned long long b) {
    return a < b ? a : b;
}

unsigned long long getSqrt(unsigned long long num) {
    unsigned long long lo = 0L, hi = my_min(num, (1LLU << 32) - 1LLU), md;
    while (lo + 1LLU < hi) {
        md = (lo + hi) >> 1LLU;
        if (num > md * md) {
            lo = md + 1LLU;
        } else {
            hi = md;
        }
    }
    if (lo * lo >= num) {
        return lo;
    } else {
        return hi;
    }
}

int main() {
    unsigned long long l;
    scanf("%llu", &l);
    printf("%llu\n", getSqrt(l));
    return 0;
}
