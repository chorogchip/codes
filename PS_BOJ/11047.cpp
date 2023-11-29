#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int N, K, D[11], S;

MAIN { FAST
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) cin >> D[i];
    for (int i = N; i > 0; --i) {
        int X = K / D[i];
        K -= X * D[i];
        S += X;
    }
    cout << S;
}