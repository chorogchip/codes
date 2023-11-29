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

int N, D[1010101];

int SOL(int n) {
    if (D[n]) return D[n];
    return D[n] = (SOL(n - 1) + SOL(n - 2)) % 15746;
}

MAIN { FAST
    cin >> N;
    D[1] = 1;
    D[2] = 2;
    cout << SOL(N) % 15746;
}