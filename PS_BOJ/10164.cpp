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

int n, m, k, arr[16][16];

inline int comb(int a, int b) {
    if (b == 0 || a == b) return 1;
    if (b == 1 || a == b + 1) return a;
    if (b < a >> 1) b = a - b;
    long long ret = a;
    for (int i = a - 1; i > b; --i) ret *= i;
    for (int i = 2; i <= a - b; ++i) ret /= i;
    return (int)ret;
}

inline int sol(int nn, int mm) { return comb(nn + mm - 2, mm - 1); }

MAIN { FAST
    cin >> n >> m >> k;
    if (k == 0) cout << sol(n, m);
    else cout << sol((k - 1) / m + 1, (k - 1) % m + 1) * sol(n - (k - 1) / m, m - (k - 1) % m);
}