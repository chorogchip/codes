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

int N;
char arr[(2<<7) * (2<<7)];
int sum[2];

void asdf(int n, int x, int y) {
    char c = arr[x * N + y];
    for (int i = x; i != x + n; i += 1)
        for (int j = y; j != y + n; j++)
            if (c != arr[i * N + j])  {
                n >>= 1;
                asdf(n, x, y);
                asdf(n, x + n, y);
                asdf(n, x, y + n);
                asdf(n, x + n, y + n);
                return;
            }
    sum[c - '0']++;
}

MAIN { //FAST
    scanf("%d", &N), getchar();
    for (int i = 0; i != N; ++i)
        for (int j = 0; j != N; ++j) {
            arr[i * N + j] = getchar();
            getchar();
        }
    asdf(N, 0, 0);
    printf("%d\n%d", sum[0], sum[1]);
}