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

int N, X, R[101010], T[101010];

void ins(int n) {
    int nn = n;
    
}

MAIN { FAST
    cin >> N;
    do cin >> X, ins(X); while (--N);
    for (int i = 1; i <= N; ++i) cout << R[i] << endl;
}