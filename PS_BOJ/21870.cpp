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

int N, A[200000], P[200001];

int calc_GCD(int a, int b) {
    if (b == 0) return a;
    else return calc_GCD(b, a % b);
}

int get_GCD(int lo, int hi) {
    int num = A[hi];
    for (int i = lo; i < hi; ++i) {
        num = calc_GCD(num, A[i]);
    }
    return num;
}

int GCD(int lo, int hi) {
    if (lo >= hi) return A[hi];
    const int md = lo + hi - 1 >> 1;
    return max(GCD(lo, md) + get_GCD(md + 1, hi),
               get_GCD(lo, md) + GCD(md + 1, hi));
}

MAIN { FAST
    cin >> N;
    foreach (i, N) cin >> A[i];
    cout << GCD(0, N - 1);
}