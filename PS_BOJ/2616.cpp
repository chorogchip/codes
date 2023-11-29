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

int N, T[50002], S, D[3][50001], CNT;

MAIN { FAST
    cin >> N;
    for (int j = 1; j <= N; ++j) cin >> T[j];
    cin >> S;
    CNT = N - S + 1;
    int sum = 0, temp;
    for (int k = 1; k <= S; ++k) sum += T[k];
    for (int j = 1; j <= CNT; ++j) {
        temp = T[j];
        T[j] = sum;
        sum -= temp;
        sum += T[j + S];
    }
    for (int j = 1; j <= CNT; ++j) D[0][j] = max(D[0][j - 1], T[j]);
    for (int i = 1; i != 3; ++i)
        for (int j = S + 1; j <= CNT; ++j)
            D[i][j] = max(D[i][j - 1], D[i - 1][j - S] + T[j]);
    cout << D[2][CNT];
}