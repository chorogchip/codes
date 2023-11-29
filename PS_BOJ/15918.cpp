#include<cstdio>
#include<algorithm>

#define getd(x) scanf("%d", (x))
#define prtd(x) printf("%d\n", (x))
#define prtds(y, x) for (int asdf = 0; asdf != (x); ++asdf) printf("%d ", (y)[asdf]); putchar('\n');
#define foreach(x, y) for (int x = 0; x != (y); ++x)

int n, nn, x, y, res = 0, arr[24], gap;

int sol(int total, int added, int toadd) {
    if (total == added) return 1;
    if (toadd == gap) toadd++;  // 원래는 수를 증가시키면서 넣는데 처음에 주어진 수는 패스
    int sum = 0;
    foreach (j, nn) if (arr[j] == -1 && j + toadd < nn && arr[j + toadd] == -1) {  // -1일때 수를 넣지 않은것
        arr[j] = toadd;
        arr[j + toadd] = toadd;
        sum += sol(total, added + 1, toadd + 1);
        arr[j + toadd] = -1;
        arr[j] = -1;
    }
    return sum;
}

int main() {
    scanf("%d %d %d", &n, &x, &y);
    nn = n << 1;
    gap = y - x;
    foreach(i, nn) arr[i] = -1;
    arr[x - 1] = gap;
    arr[y - 1] = gap;
    prtd(sol(n, 1, 2));  // 문제는 1부터지만 코드는 계산상 편의를 위해 2부터 넣음
}