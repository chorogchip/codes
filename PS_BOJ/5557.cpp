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

int N, V;
long long D[99][21];

MAIN { FAST
    cin >> N >> V;
    D[0][V] = 1L;
    for (int i = 1; i != N - 1; ++i) {
        cin >> V;
        for (int j = 0; j <= 20; ++j) {
            if (j - V >= 0) D[i][j] += D[i - 1][j - V];
            if (j + V <= 20) D[i][j] += D[i - 1][j + V];
        }
    }
    cin >> V;
    cout << D[N - 2][V];
}