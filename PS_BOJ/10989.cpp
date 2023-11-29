#include<bits/stdc++.h>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define LL long long
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int N, X, D[10001];

MAIN { FAST
    cin >> N;
    foreach (i, N) {
       cin >> X;
        D[X]++;
    }
    for (int i = 1; i != 10001; ++i)
        while (D[i]--) cout << i << endl;
}