#include<bits/stdc++.h>
using namespace std;
#include <sys/stat.h>
#include <sys/mman.h>

static struct stat st;
static const char* p;
static inline unsigned getu(){unsigned x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}
static inline int geti(){bool e=*p=='-';p+=e;return(e?-1:1)*getu();}

vector<int> g[20101];
unsigned char mask[20101];

bool fs(int i, int color) {
    if (!mask[i]) mask[i] = color;
    else return mask[i] == color;
    for (auto o : g[i]) if (!fs(o, color ^ 1)) return false;
    return true;
}

int main() {
    fstat(0, &st);
    p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    unsigned t = getu();
    while(t--) {
        unsigned n = getu(), m = getu();
        memset(mask+1, 0, n);
        for (int i = 1; i <= n; ++i) g[i].clear();
        while(m--) {
            unsigned a = getu(), b = getu();
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for (int i = 1; i <= n; ++i) if (!mask[i] && !fs(i, 2)) goto E;
        puts("YES"); continue;
        E: puts("NO");
    }
}