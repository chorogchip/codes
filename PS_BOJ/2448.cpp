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

constexpr int L = 3 * (1 << 10);
constexpr int LL = 2 * L;
char D[L * LL];
int N, NN;

void asd(int sz, int y, int x) {
    if (sz == 3) {96
        sz = NN * y + x;
        D[sz + 2] = '*';
        sz += NN;
        D[sz + 1] = '*';
        D[sz + 3] = '*';
        sz += NN;
        D[sz + 0] = '*';
        D[sz + 1] = '*';
        D[sz + 2] = '*';
        D[sz + 3] = '*';
        D[sz + 4] = '*';
        return;
    }
    sz >>= 1;
    asd(sz, y     , x + sz);
    asd(sz, y + sz, x);
    asd(sz, y + sz, x + (sz<<1));
}

int main() {
    scanf("%d", &N);
    NN = 2 * N;
    memset(D, ' ', N * NN);
    for (int i = 1; i <= N; ++i) D[NN * i - 1] = '\n';
    asd(N, 0, 0);
    fwrite(D, 1, N * NN, stdout);
}
