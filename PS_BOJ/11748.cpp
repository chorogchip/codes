#include<bits/stdc++.h>
using namespace std;

long double f[501], p[501], MM = 0.0;

int main() {
    int N; cin >> N;
    scanf("%Lf", &f[1]);
    p[1] = f[1];
    MM = p[1] + f[1];
    for (int i = 2; i <= N; ++i) {
        scanf("%Lf", &f[i]);
        long double mm = f[i];
        for (int j = i - 1; j; --j) {
            long double c = f[i] + f[j];
            long double b = f[i] - f[j];
            mm = max(mm, p[j] + sqrt(c*c - b*b));
        }
        p[i] = mm;
        MM = max(MM, p[i]+f[i]);
        //printf("%d %.8Lf\n", i, mm);
    }
    printf("%.8Lf", MM);
}