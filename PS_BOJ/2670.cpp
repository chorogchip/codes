#include<bits/stdc++.h>
using namespace std;

int main() {
    double dp = 1.0f;
    double res = 0.0f;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        double x; cin >> x;
        dp = max(dp * x, x);
        res = max(res, dp);
    }
    printf("%.3lf", res);
}