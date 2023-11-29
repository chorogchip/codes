#include<cstdio>

int n;
char arr[64 * 64], ans[64 * 64 * 4], *p = ans;

void sol(int nn, int x, int y, char*& wrp) {
    if (nn == 1) {
        *wrp++ = arr[x * n + y];
        return;
    }
    char lcans[64 * 64 * 4], *lcp = lcans;
    int dd = nn >> 1;
    sol(dd, x, y, lcp);
    sol(dd, x, y + dd, lcp);
    sol(dd, x + dd, y, lcp);
    sol(dd, x + dd, y + dd, lcp);
    if (lcp - 4 == lcans && lcans[0] == lcans[1] && lcans[1] == lcans[2] && lcans[2] == lcans[3]) {
        *wrp++ = lcans[0];
        return;
    }
    *wrp++ = '(';
    for (char* lcprp = lcans; lcprp != lcp; ++lcprp) *wrp++ = *lcprp;
    *wrp++ = ')';
}

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j)
            arr[i * n + j] = getchar();
        getchar();
    }
    sol(n, 0, 0, p);
    for (char* aa = ans; aa != p; ++aa)
        putchar(*aa);
}
