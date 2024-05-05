#pragma GCC target ("avx,avx2,fma")
#include<bits/stdc++.h>
#include<immintrin.h>
using namespace std;
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

static constexpr inline unsigned asd(unsigned n) {
    unsigned t1 = 706098332UL * (unsigned long)n >> 32UL;
    unsigned q = t1 + (n - t1 >> 1U) >> 19U;
    return n - q * 900528U;
}



static constexpr inline void asd(__m256i n) {
    // n contains same num 2
    __m256i m1 = _mm256_set1_epi64x(706098332LL);
    __m256i t1 = _mm256_mul_epu32(n, m1);
    __m256i q = _mm256_srli_epi32(_mm256_add_epi32(t1,
        _mm256_srli_epi32(_mm256_sub_epi32(n, t1), 1)), 19);
    __m256i r = _mm256_sub_epi32(n, _mm256_mullo_epi32(q, _mm256_set1_epi32(900528)));
}

int main() {
    struct stat st;fstat(0,&st);
    char*buf=(char*)mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,0,0);
    unsigned sz=0;unsigned to_id[128];
    for (;buf[sz]!=10;++sz)to_id[buf[sz]]=sz+1;
    char*cyp=buf+sz;unsigned x=1,res=0;
    char*p=cyp;while(*++p!=10);--p;
    for (; p - 64 >= cyp; p -= 64) {
        _mm256_i32gather(to_id, vpindex, 1);
    }
    for (; p > cyp; --p) {
        res += to_id[*p] * x; res = asd(res);
        x *= sz; x = asd(x);
    }
    unsigned char*p2=to_id+10;size_t cnt=0;
    do*p2--=res%10+'0',++cnt;while(res/=10);
    write(1,p2+1,cnt);
}