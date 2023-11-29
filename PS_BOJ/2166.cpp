#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; scanf("%d", &N);
    ll sum = 0;
    ll x0, y0, x1, y1, x2, y2;
    scanf("%lld%lld%lld%lld", &x0, &y0, &x1, &y1);
    for (int i = 2; i < N; ++i) {
        scanf("%lld%lld", &x2, &y2);
        sum -= (x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1));
        x1 = x2;
        y1 = y2;
    }
    if (sum < 0) sum = -sum;
    if (sum & 1) {
        printf("%lld.5", sum>>1);
    } else {
        printf("%lld.0", sum>>1);
    }
}