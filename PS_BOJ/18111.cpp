#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, M, B, MAX = 500, MIN = -1, A = 2101010101, AH;
short D[501][501];

int asdf(int h) {
    int bl = B;
    int rrr = 0;
    for (int i = 0; i != N; ++i)
    for (int j = 0; j != M; ++j) {
        int gap = D[i][j] - h;
        if (gap > 0) bl += gap, rrr += gap;
    }
    rrr <<= 1;
    for (int i = 0; i != N; ++i)
    for (int j = 0; j != M; ++j) {
        int gap = D[i][j] - h;
        if (gap < 0) bl += gap, rrr -= gap;
    }
    if (bl >= 0) return rrr;
    else return -1;
}

main() { FAST
    cin >> N >> M >> B;
    for (int i = 0; i != N; ++i)
        for (int j = 0; j != M; ++j) {
            cin >> D[i][j];
            MAX = max(MAX, (int)D[i][j]);
            MIN = min(MIN, (int)D[i][j]);
        }
    for (int i = MIN; i <= MAX; ++i) {
        int rr = asdf(i);
        if (rr >= 0 && rr <= A) {
            A = rr;
            AH = i;
        }
    }
    cout << A << " " << AH;
}