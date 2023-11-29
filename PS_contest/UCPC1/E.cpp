#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

#include<math.h>

typedef long double ld;
int N;
ld S1 = 0.0L, S2 = 0.0L;
struct T {
    int Y, M, D, h, m, s, dif;
} TT[1010];

const ld M2019[] = { 0.0L, 31.0L, 28.0L, 31.0L, 30.0L, 31.0L, 30.0L, 31.0L, 31.0L, 30.0L, 31.0L, 30.0L, 31.0L };
const ld M2020[] = { 0.0L, 31.0L, 29.0L, 31.0L, 30.0L, 31.0L, 30.0L, 31.0L, 31.0L, 30.0L, 31.0L, 30.0L, 31.0L };
ld sum2019 = 0.0L;

ld getASDF(const T& t) {
    ld SS = 0.0L;
    switch(t.Y) {
        case 2019: break;
        case 2020: SS += sum2019; break;
        case 2021: SS += sum2019 * 2.0L + 1.0L; break;
        case 2022: SS += sum2019 * 3.0L + 1.0L; break;
    }
    if (t.Y == 2020)
        for  (int i = 1; i < t.M; ++i) SS += M2020[i];
    else 
        for  (int i = 1; i < t.M; ++i) SS += M2019[i];
    SS += t.D - 1.0;
    
    SS *= 24.0L;
    SS += t.h;
    SS *= 60.0L;
    SS += t.m;
    SS *= 60.0L;
    SS += t.s;
    return SS;
}

constexpr ld MMM = 365LL * 24LL * 60LL * 60LL;
ld MM = 0.0L;

int main() {
    cin >> N;
    for (int i = 1; i <= 12; ++i) sum2019 += M2019[i];
    if (N == 0) {
        putchar('0');
        return 0;
    }
    for (int i = 1; i <= N; ++i)
        scanf("%d/%d/%d %d:%d:%d %d",
        &TT[i].Y, &TT[i].M, &TT[i].D, &TT[i].h, &TT[i].m, &TT[i].s, &TT[i].dif);
    MM = getASDF(TT[N]);
    for (int i = 1; i <= N; ++i) {
        ld p = max(powl(0.5L, (MM - getASDF(TT[i])) / MMM), powl(0.9L, N - i));
        S2 += p;
        S1 += p * TT[i].dif;
    }
    printf("%d", (long long)floor(S1 / S2 + 0.5L));
}
