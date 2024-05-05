#include<bits/stdc++.h>
using namespace std;
#include <sys/stat.h>
#include <sys/mman.h>
using ll = long long;

static struct stat st;
static const char* p;
static inline int getu(){int x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}
static inline int geti(){bool e=*p=='-';p+=e;return(e?-1:1)*getu();}

int main() {
    fstat(0, &st);
    p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    int n = getu(), d = getu();
    deque<pair<int,ll>> dq;
    const ll INF = 1'000'000'000;
    ll res = -INF;
    for (int i = 1; i <= n; ++i) {
        while (!dq.empty() && i - dq.front().first > d) dq.pop_front();
        ll x = geti();
        if (!dq.empty()) x += dq.front().second;
        res = max(res, x);
        while (!dq.empty() && dq.back().second <= x) dq.pop_back();
        if (x > 0) dq.push_back({i, x});
    }
    printf("%lld", res);
}