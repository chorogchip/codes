#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define LL long long
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int N, D[61][61][61];

int sol(int A, int B, int C) {
    A = max(0, A);
    B = max(0, B);
    C = max(0, C);
    if (A == 0 && B == 0 && C == 0) return 0;
    if (D[A][B][C]) return D[A][B][C];
    int res = 2101010101;

    res = min(res, sol(A - 9, B - 3, C - 1));
    res = min(res, sol(A - 9, B - 1, C - 3));
    res = min(res, sol(A - 3, B - 9, C - 1));
    res = min(res, sol(A - 3, B - 1, C - 9));
    res = min(res, sol(A - 1, B - 9, C - 3));
    res = min(res, sol(A - 1, B - 3, C - 9));

    return D[A][B][C] = res + 1;
}

MAIN { FAST
    cin >> N;
    if (N == 1) {
        cin >> D[0][0][0];
        cout << (D[0][0][0] + 8) / 9;
        return 0;
    }
    if (N == 2) {
        int A, B;
        cin >> A >> B;
        for (int i = 1; i <= 60; ++i) {
            int var = (i + 8) / 9;
            D[i][0][0] = var;
            D[0][i][0] = var;
            D[0][0][i] = var;
        }
        cout << sol(A, B, 0);
        return 0;
    } else {
        int A, B, C;
        cin >> A >> B >> C;
        for (int i = 1; i <= 60; ++i) {
            int var = (i + 8) / 9;
            D[i][0][0] = var;
            D[0][i][0] = var;
            D[0][0][i] = var;
        }
        cout << sol(A, B, C);
        return 0;
    }
}