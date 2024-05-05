#include<bits/stdc++.h>
using namespace std;
#include <sys/stat.h>
#include <sys/mman.h>
using ll = long long;

static struct stat st;
static const char* p;
static inline int getu(){int x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}
static inline int geti(){bool e=*p=='-';p+=e;return(e?-1:1)*getu();}

signed char d[16];
signed char digit[16];
short digit_s[65536];
signed char offset_k[1024][16];

ll dp[1<<16][128];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    fstat(0, &st);
    p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    const int n = getu();
    const char* pp = p;
    for (int i = 0; i < n; ++i) while (*p++ != '\n');
    const int k = getu();
    int digit_sum = 0;
    for (int i = 0; i < n; ++i) {
        int x=0,cnt=0;do ++cnt,x=(x*10+*pp-'0')%k;while(*++pp>='0');++pp;
        digit[i] = cnt; digit_sum += cnt;
        d[i] = x;
    }
    dp[0][0] = 1;
    for (int j = 0; j < n; ++j) offset_k[0][j] = d[j];
    for (int i = 1; i < digit_sum; ++i)
        for (int j = 0; j < n; ++j)
            offset_k[i][j] = offset_k[i-1][j] * 10 % k;

    for (int mask = 0; mask < 1<<n; ++mask) {
        const int dig = digit_s[mask];
        for (int i = 0; i < n; ++i) {
            if (mask & 1<<i) continue;
            const int new_mask = mask | 1<<i;
            const int k_offset = offset_k[dig][i];
            digit_s[new_mask] = dig + digit[i];
            for (int rem = 0; rem < k-k_offset; ++rem)
                dp[new_mask][rem + k_offset] += dp[mask][rem];
            for (int rem = k-k_offset; rem < k; ++rem)
                dp[new_mask][rem + k_offset - k] += dp[mask][rem];
        }
    }
    ll a = dp[(1<<n)-1][0];
    ll b = 1; for (ll i = 1; i <= n; ++i) b *= i;
    ll gcddd = gcd(a, b);
    printf("%lld/%lld", a/gcddd, b/gcddd);
}