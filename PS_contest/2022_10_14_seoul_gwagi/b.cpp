#include<iostream>
using namespace std;

double asd(double v, double a) {
    double x1 = 1 - v;
    double x2 = 1 - a/100.0;
    return 1.0 - x1*x2;
}

int main() {
    int n; scanf("%d", &n);
    double s = 0.0;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        s = asd(s, (double)x);
        printf("%lf\n", s*100.0);
    }
}