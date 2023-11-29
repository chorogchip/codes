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

int N, K, W, V, D[100001];

MAIN { FAST
    cin >> N >> K;
    for (int i = 1; i != N; ++i) {
        cin >> W >> V;
        for (int j = K; j >= 0; --j)
            if (j >= W) D[j] = max(D[j], D[j - W] + V);
    }
    cin >> W >> V;
    if (K >= W) D[K] = max(D[K], D[K - W] + V);

    cout << D[K];
}