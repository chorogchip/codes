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
int tmp1, tmp2, tmp3, tmp4, tmp5;
int N, M, K, X, Y, Q, P, S, R, A, B, C, O;

int Map[200], MV[200];
#include<queue>
queue<int> qu;

int main() { FAST
    cin >> N >> M;
    fore (i, N) {
        cin >> A >> B;
        if (A > 1 && A < 100 && B > 1 && B < 100)
        MV[A] = B;
    }
    fore (i, M) {
        cin >> A >> B;
        if (A > 1 && A < 100 && B > 1 && B < 100)
        MV[A] = B;
    }
    qu.push(1);
    tmp1 = Map[1] = 1;
    while (!qu.empty()) {
        tmp2 = qu.size();
        ++tmp1;
        for (int i = 0; i != tmp2; ++i) {
            O = qu.front(); qu.pop();
            if (O == 100) {
                cout << tmp1 - 2;
                return 0;
            }
            for (int j = 1; j <= 6; ++j)
                if ((tmp3 = O + j) <= 100) {
                    if (tmp4 = MV[tmp3]) tmp3 = tmp4;
                    if (!Map[tmp3]) Map[tmp3] = tmp1, qu.push(tmp3);
                }
        }
    }
}
