#include<bits/stdc++.h>
using namespace std;
#include <sys/stat.h>
#include <sys/mman.h>

static struct stat st;
static const char* p;
static inline int getu(){int x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}
static inline int geti(){bool e=*p=='-';p+=e;return(e?-1:1)*getu();}

int dp[64];

int main() {
    fstat(0, &st);
    p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    int n = getu();
    for (int i = 1; i <= n; ++i) {
        int t = getu(), p = getu();
        dp[i+1&63] = max(dp[i+1&63], dp[i&63]);
        dp[i+t&63] = max(dp[i+t&63], dp[i&63]+p);
    }
    printf("%d", dp[n+1&63]);
}