
#include<iostream>
#include<immintrin.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define x first
#define y second

alignas(16) int a[201010], b[201010];


__attribute__((target("avx2")))
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        a[n]=a[n+1]=a[n+2]=a[n+3]=-1;
        b[n]=b[n+1]=b[n+2]=b[n+3]=1;
        n += 4;
        a[n]=a[n+1]=a[n+2]=a[n+3]=-1;
        b[n]=b[n+1]=b[n+2]=b[n+3]=1;
        n -= 4;
        int rres = 0;
        auto s1 = _mm256_setzero_si256();
        auto s2 = _mm256_setzero_si256();
        for (int i = 0; i < n; ++i) {
            auto aa = _mm256_set1_epi32(a[i]);
            auto bb = _mm256_set1_epi32(b[i]);
            for (int j = i + 1; j < n; j += 8) {
                auto a1 = _mm256_mullo_epi32(aa, _mm256_loadu_si256((__m256i*)&a[j]));
                auto b1 = _mm256_add_epi32(bb, _mm256_loadu_si256((__m256i*)&b[j]));
                auto c1 = _mm256_cmpeq_epi32(a1, b1);
                s1 = _mm256_add_epi32(s1, c1);
                j += 8;
                auto a2 = _mm256_mullo_epi32(aa, _mm256_loadu_si256((__m256i*)&a[j]));
                auto b2 = _mm256_add_epi32(bb, _mm256_loadu_si256((__m256i*)&b[j]));
                auto c2 = _mm256_cmpeq_epi32(a2, b2);
                s2 = _mm256_add_epi32(s2, c2);
            }
        }
        s1 = _mm256_add_epi32(s1, s2);
        __m256i arr;
        _mm256_storeu_si256(&arr, s1);
        #define arr ((int*)&arr)
        int res = ((arr[0] + arr[1]) + (arr[2] + arr[3])) + ((arr[4] + arr[5]) + (arr[6] + arr[7]));
        cout << -res << '\n';
    }
}
