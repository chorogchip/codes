#include<bits/stdc++.h>
using namespace std;
#include <sys/stat.h>
#include <sys/mman.h>
using ll = long long;

static struct stat st;
static const char* p;
static inline int getu(){int x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}

int main() {
    fstat(0, &st);
    p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    int n = getu();
    ll st0 = 0, cnt0 = 0, st1 = 0, cnt1 = 0;
    while(n--) {
        char c;
        while(*p >= '0') c = *p++; p++;
        if (c & 1) ++st0, cnt1 += st1;
        else ++st1, cnt0 += st0;
    }
    printf("%lld", min(cnt0, cnt1));
}