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

int N, M;
char D[11][11];

int main() {
    scanf("%d%d", &N, &M);
    getchar();
    fore (i, N) {
        fore (j, M) D[i][j] = getchar();
        getchar();
    }
    fore (i, N) {
        for (int j = M - 1; j >= 0; --j)
            putchar(D[i][j]);
        putchar('\n');
    }
}
