#include<bits/stdc++.h>
using namespace std;
#include <sys/stat.h>
#include <sys/mman.h>
using ll = long long;

static struct stat st;
static const char* p;
static inline int getu(){unsigned x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}

unsigned m[1001];

struct RECIP {
    unsigned sh1, sh2, m_;
};

constexpr inline RECIP get_reciprocal(unsigned d) {
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

int main() {
    fstat(0, &st);
    p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    unsigned n = getu(), k = getu();
    auto rcp = get_reciprocal(k);
    int xx = 0; ll res = 0; m[0]=1;
    while (n--) {
        xx += getu();
        xx -= divide(xx, rcp) * k;
        res += m[xx]++;
    }
    printf("%lld", res);
}