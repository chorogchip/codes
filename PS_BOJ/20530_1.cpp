#include<bits/stdc++.h>
using namespace std;
#include <sys/stat.h>
#include <sys/mman.h>

static struct stat st;
static const char* p;
static inline int getu(){int x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}
static inline int geti(){bool e=*p=='-';p+=e;return(e?-1:1)*getu();}

static char res[401010];

static vector<int> g[201010];
static int cnt[201010];
static int un[201010];
static vector<int> un_st;

static int par(int i) {
    while(un[i] != i) un_st.push_back(i), i = un[i];
    for (auto o : un_st) un[o] = i;
    un_st.clear();
    return i;
}

int main() {
    fstat(0, &st);
    p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    int n = getu(), q = getu();
    for (int i = 0; i < n; ++i) {
        int a = getu(), b = getu();
        g[a].push_back(b);
        g[b].push_back(a);
        ++cnt[a]; ++cnt[b];
    }
    vector<int> v; v.reserve(n);
    un_st.reserve(n);
    for (int i = 1; i <= n; ++i) {
        un[i] = i;
        if(cnt[i] == 1) v.push_back(i);
    }
    while(!v.empty()) {
        auto o = v.back(); v.pop_back();
        for (auto oo : g[o]) {
            un[par(o)] = par(oo);
            if (--cnt[oo] == 1) v.push_back(oo);
        }
    }
    short* pres = (short*)res;
    while(q--) *pres++ = '\n' << 8 | ('1' + (par(getu()) != par(getu())));
    fwrite(res, 1, (char*)pres-res, stdout);
}