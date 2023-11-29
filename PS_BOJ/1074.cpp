#include<cstdio>

int n, r, c, ans;

int sol(int nn, int x, int y) {
    if (nn == 1) return 0;
    int dd = nn >> 1;
    if (x < dd) {
        if (y < dd) return sol(dd, x, y);
        else return dd * dd + sol(dd, x, y - dd);
    } else {
        if (y < dd) return 2 * dd * dd + sol(dd, x - dd, y);
        else return 3 * dd * dd + sol(dd, x - dd, y - dd);
    }
}

int main() {
    scanf("%d %d %d", &n, &r, &c);
    printf("%d", sol(1 << n, r, c));
}