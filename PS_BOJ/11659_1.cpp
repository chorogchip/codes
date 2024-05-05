#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

static struct stat st;
static const char* p;
static inline unsigned getu(){unsigned x=0;do x=x*10+*p-'0';while(*++p>='0');++p;return x;}
static char buf[1210101], *pp = buf;
static unsigned s[101010];

__libc_start_main() {
    fstat(0, &st);
    p = (char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    unsigned n = getu(), m = getu();
    unsigned sum = 0;
    for (int i = 1; i <= n; ++i) s[i] = (sum += getu());
    char buff[16]; buff[15] = '\n';
    while(m--) {
        char *pb = buff+14;
        unsigned a = getu();
        unsigned res = s[getu()] - s[a-1];
        do *pb-- = res%10U+'0'; while(res/=10U);
        unsigned sz = buff + 15 - pb;
        memcpy(pp, pb+1, sz);
        pp += sz;
    }
    syscall(1, 1, buf, pp-buf);
    _exit(0);
} main;