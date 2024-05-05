#include<bits/stdc++.h>
using namespace std;
#include <sys/stat.h>
#include <sys/mman.h>

static struct stat st;
static const char* p;
static inline unsigned getu(){unsigned x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}

vector<short> g[2010];
bool mask[2010];

int main() {
    fstat(0, &st);
    p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    unsigned n = getu(), m = getu();
    while(m--) {
        unsigned a = getu(), b = getu();
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i1 = 0; i1 < n; ++i1) {
        mask[i1] = 1; for (auto i2 : g[i1]) {
        mask[i2] = 1; for (auto i3 : g[i2]) if (i3 != i1) {
        mask[i3] = 1; for (auto i4 : g[i3]) if (!mask[i4]) {
                      for (auto i5 : g[i4]) if (!mask[i5]) {
            fwrite("1", 1, 1, stdout); return 0;
        }} mask[i3] = 0; } mask[i2] = 0; } mask[i1] = 0;
    }
    fwrite("0", 1, 1, stdout);
}