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

int N, M, X, C[101010];
char A[101010][21], B[21];

inline int search() {
    int lo = 1, hi = N, md;
    while (lo < hi) {
        md = lo + hi >> 1;
        if (strcmp(A[C[md]], B) < 0) lo = md + 1;
        else hi = md;
    }
    return C[lo];
}

main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%s", A[i]);
        C[i] = i;
    }
    sort(C + 1, C + 1 + N, [](int a, int b)->bool{
        return strcmp(A[a], A[b]) < 0;
    });
    while (M--) {
        scanf("%s", B);
        if (B[0] <= '9') puts(A[atoi(B)]);
        else printf("%d\n", search());
    }
}

