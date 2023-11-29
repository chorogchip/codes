#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);

int N, M, A[1000000];

MAIN { FAST
    cin >> N >> M;
    foreach (i, N) cin >> A[i];
    int lo = 0, hi = 1000000000, md;
    long long sum;
    while (lo < hi) {
        md = lo + hi + 1 >> 1;
        sum = 0L;
        for (int i = 0; i != N; ++i)
            sum += max(0, A[i] - md);
        if (sum >= M) lo = md;
        else hi = md - 1;
    }
    cout << lo;
}