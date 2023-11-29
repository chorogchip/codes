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

int N, D[1000], S;

MAIN { FAST
    cin >> N;
    foreach (i, N) cin >> D[i];
    sort(D, D + N);
    for (int i = 0; i != N;) {
        S += ++i * D[N - i];
    }
    cout << S;
}