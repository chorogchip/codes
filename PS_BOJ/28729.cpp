#include<bits/stdc++.h>
using namespace std;
#include <sys/stat.h>
#include <sys/mman.h>
using ll = long long;

static struct stat st;
static const char* p;
static inline int getu(){int x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}
static inline ll getll(){ll x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}

pair<int,int> d[101010];

int main() {
    fstat(0, &st);
    p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    int n = getu(), m = getu(); ll k = getll();
    for (int i = 0; i < n; ++i) d[i].second = getu();
    for (int i = 0; i < m; ++i) d[getu()-1].first++, d[getu()].first--;
    for (int i = 1; i < n; ++i) d[i].first += d[i-1].first;
    sort(d, d + n, greater{});
    ll sum = 0;
    int i = 0;
    for (; i < n; ++i) {
        ll peo = d[i].second;
        if (k >= peo) k -= peo;
        else { sum += (ll)d[i].first * (peo - k); ++i; break; }
    }
    for (; i < n; ++i) sum += (ll)d[i].first * (ll)d[i].second;
    printf("%lld", sum);
}