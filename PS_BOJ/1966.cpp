#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define prtl() putchar('\n')
#define prtds(arr, n) for (int asdf = 0; asdf != (n); ++asdf) printf("%d ", (arr)[asdf]); putchar('\n')
#define foreach(i, n) for (int i = 0; i != (n); ++i)
#define MAIN int main()
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);

int N, A[500000];

MAIN { FAST
    cin >> N;
    int i = 0, n = N;
    while (--n) {
        while (A[i]) {
            i++;
            if (i == N) i = 0;
        }
        A[i++] = 1;
        if (i == N) i = 0;
        while (A[i]) {
            i++;
            if (i == N) i = 0;
        }
        i++;
        if (i == N) i = 0;
    }
    for (int j = 0; j != N; ++j) {
        if (!A[j]) {
            cout << j + 1;
            break;
        }
    }
}