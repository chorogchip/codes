#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int N, M, A[10001], S, R;

MAIN { FAST
    cin >> N >> M;
    foreach (i, N) cin >> A[i];
    int lo = 0, hi = -1;
    while (++hi < N) {
        S += A[hi];
        do   if (S < M) goto C;
        else if (S == M) { R++; goto C; }
        while (lo != hi && (S -= A[lo++]));
        C:;
    }
    cout << R;
}