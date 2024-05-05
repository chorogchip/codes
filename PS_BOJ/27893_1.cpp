#include<bits/stdc++.h>
using namespace std;
#include <sys/stat.h>
#include <sys/mman.h>

static struct stat st;
static const char* p;
static inline int getu(){int x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}
static inline int geti(){bool e=*p=='-';p+=e;return(e?-1:1)*getu();}

int main() {
    fstat(0, &st);
    p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    int n = getu(), m = getu();
    const char* str = p;
    int dcnt = 0; for (int i = 0; i < n; ++i) if (str[i] == '.') ++dcnt;
    m = min(m, dcnt);
    int cnt = 0, rem = 0;
    vector<int> v;
    int i = 0;
    while (i < n && str[i] == '.') ++i;
    rem += i;
    if (i == n) { cout << min(n, n - m + 2); exit(0); }
    while (i < n) {
        if (str[i] == '.') ++cnt, ++i;
        else {
            if (cnt) v.push_back(cnt); cnt = 0;
            while(i < n && str[i] == 'X') ++i;
        }
    }
    rem += cnt;
    sort(v.begin(), v.end());
    int res = 2 + rem;
    for (auto o : v) {
        if (m >= o) m -= o;
        else res += o + 2;
    }
    res -= m;
    printf("%d", res);
}