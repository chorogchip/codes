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

int N, M, C[501010], D[501010], R;
char A[501010][21], B[21];

main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i != N; ++i)
        C[i] = i, scanf("%s", A[i]);
    sort(C, C + N, [](int a, int b)->bool{
        return strcmp(A[a], A[b]) < 0;
    });
    while (M--) {
        scanf("%s", B);
        int lo = 0, hi = N-1, md;
        while (lo < hi) {
            md = lo + hi >> 1;
            if (strcmp(A[C[md]], B) < 0) lo = md + 1;
            else hi = md;
        }
        if (strcmp(A[C[lo]], B) == 0) ++R, D[lo] = 1;
    }
    printf("%d\n", R);
    for (int i = 0; i != N; ++i) if (D[i])
        printf("%s\n", A[C[i]]);
}

