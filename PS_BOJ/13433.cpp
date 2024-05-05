#include<bits/stdc++.h>
using namespace std;

double d[16];
int perm[16];
double pos[16];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lf", &d[i]), perm[i] = i;
    sort(d, d + n);
    double res = 1e30;
    do {
        memset(pos, 0, sizeof(pos));
        for (int i = 0; i < n; ++i) {
            double cur = 0;
            for (int j = 0; j < i; ++j) {
                double r1 = d[perm[i]];
                double r2 = d[perm[j]];
                cur = max(cur, pos[j] + 2.0 * (double)sqrtl(r1 * r2));
            }
            pos[i] = cur;
        }
        res = min(res, pos[n-1]);
    } while(next_permutation(perm, perm + n));
    printf("%.16lf", res);
}