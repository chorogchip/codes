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

int N, A[500000], T[500000];
long long S;

void merge(int lo, int hi) {
    if (lo == hi) return;
    int md = lo + hi >> 1;
    merge(lo, md);
    merge(md + 1, hi);
    int i = lo, j = md + 1, k = 0;
    while (i <= md && j <= hi)
        if (A[i] > A[j]) T[k++] = A[j++], S += md + 1 - i;
        else T[k++] = A[i++];
    while (i <= md) T[k++] = A[i++];
    while (j <= hi) T[k++] = A[j++];
    for (int l = 0; l < k; ++l) A[lo + l] = T[l];
}

MAIN { FAST
    cin >> N;
    foreach (i, N) cin >> A[i];
    merge(0, N - 1);
    cout << S;
}