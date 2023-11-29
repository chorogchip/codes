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

int A, B, C, D[21][21][21];

int W(int a, int b, int c) {
    int& V = D[a][b][c];
    if (a<=0||b<=0||c<=0) return 1;
    if (a>20||b>20||c>20) return W(20, 20, 20);
    if (V) return V;
    if(a<b&&b<c) return V = W(a, b, c-1) + W(a, b-1, c-1) - W(a, b-1, c);
    return V = W(a-1, b, c) + W(a-1, b-1, c) + W(a-1, b, c-1) - W(a-1, b-1, c-1);
}

MAIN {
    while (true) {
        scanf("%d%d%d", &A, &B, &C);
        if (A == -1 && B == -1 && C == -1) break;
        printf("w(%d, %d, %d) = %d\n", A, B, C, W(A, B, C));
    }
}