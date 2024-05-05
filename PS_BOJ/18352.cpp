#include<bits/stdc++.h>
using namespace std;
#include <sys/stat.h>
#include <sys/mman.h>

static struct stat st;
static const char* p;
static inline unsigned getu(){unsigned x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}

vector<int> g[301010];
bool d[301010];

int main() {
    fstat(0, &st);
    p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    unsigned n = getu(), m = getu(), k = getu(), x = getu();
    while(m--) g[getu()].push_back(getu());
    vector<int> v; v.push_back(x); d[x] = 1;
    for (int dist = 1; dist <= k; ++dist) {
        vector<int> v2;
        for (auto o : v)
            for (auto oo : g[o]) if (!d[oo])
                d[oo] = 1, v2.push_back(oo);
        v = move(v2);    
    }
    if (v.empty()) { puts("-1"); return 0; }
    sort(v.begin(), v.end());
    for (auto o : v) printf("%d\n", o);
}