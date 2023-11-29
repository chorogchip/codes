#include<bits/stdc++.h>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define LL long long
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'


int N, INTRV, INTRV_C = 2;
unsigned int R = -1;
struct Pos { short x, y; } D[100001];
unsigned char INTVS[20001][2501];

// 처음에 2*2개의 구간으로 나눠 점들을 집어넣는다.
// 구간에 이미 데이터가 들어있으면 다음 함수로 간다.
// 다음 함수에서는 4*4, 8*8, ... 10001 * 10001 개의 구간으로 나눠 집어넣기를 반복한다.
// 중복이 없을 경우 필요한 구간 수를 넘겨 연산으로 넘어간다.
// bool에 넣으면 공간이안돼서 char에 넣는다.
int seperate() {
    int x, y;
    do {
        INTRV = 20000 / INTRV_C + 1;
        memset(INTVS, 0, sizeof INTVS);
        for (int i = 0; i != N; ++i) {
            x = D[i].x / INTRV;
            y = D[i].y / INTRV;
            unsigned char& d = INTVS[x][y / 8];
            if (d & 1 << y % 8) goto END;
            else d |= 1 << y % 8;
        }
        return 0;
        END:
        INTRV_C <<= 1;
    } while (INTRV > 1);
    return -1;
}

inline void calc_real_search(int x, int y, int j, int k) {
    unsigned int x2, y2;
    int lo = 0, hi = N - 1;
    while (lo < hi) {
        int md = lo + hi >> 1;
        if (D[md].x / INTRV > j || D[md].x / INTRV == j && D[md].y / INTRV >= k) hi = md;
        else lo = md + 1;
    }
    x2 = D[lo].x;
    y2 = D[lo].y;
    R = min(R, (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
}

// 연산한다. 옆 혹은 대각선 이동을 1로 쳐서
// 간격이 1, 2, 3인 곳을 계산한다.
// 데이터가 10만이므로 10만번 돈다.
void calc() {
    int x, y;
    for (int i = 0; i != N; ++i) {
        x = D[i].x / INTRV;
        y = D[i].y / INTRV;
        for (int j = max(0, x - 3); j <= min(20000 / INTRV, x + 3); ++j)
            for (int k = max(0, y - 3); k <= min(20000 / INTRV, y + 3); ++k)
                // 데이터가 있는 곳을 발견하면 역추적
                if ((j != x || k != y) && INTVS[j][k / 8] & 1 << k % 8)
                    calc_real_search(D[i].x, D[i].y, j, k);

        INTVS[x][y / 8] |= 1 << y % 8;
    }
}

MAIN { FAST
    cin >> N;
    foreach(i, N) cin >> D[i].x >> D[i].y;
    foreach(i, N) D[i].x += 10000, D[i].y += 10000;
    if (seperate()) { cout << 0; return 0; }
    memset(INTVS, 0, sizeof INTVS);
    sort(D, D + N, [&](Pos a, Pos b) -> bool {
        return a.x / INTRV < b.x / INTRV || a.x / INTRV == b.x / INTRV && a.y / INTRV < b.y / INTRV;
    });
    calc();
    cout << R;
}