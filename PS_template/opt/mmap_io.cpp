#include<bits/stdc++.h>
using namespace std;
#include <sys/stat.h>
#include <sys/mman.h>

static struct stat st;
static const char* p;
static inline unsigned getu(){unsigned x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}
static inline int geti(){bool e=*p=='-';p+=e;return(e?-1:1)*getu();}

int main() {
    fstat(0, &st);
    p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    printf("%d", getu() + getu());
}