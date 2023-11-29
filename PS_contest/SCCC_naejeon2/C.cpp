#include<bits/stdc++.h>
using namespace std;

int main() {
    double INF = (double)1'0000'0000;
    double a, b, c, v0, v1, v2; cin >> a >> b >> c >> v0 >> v1 >> v2;
    double res = INF;
    res = min(res, a/v0 + c/v1 + b/v2);
    res = min(res, b/v0 + c/v1 + a/v2);

    res = min(res, a/v0 + c/v1 + c/v2 + a/v2);
    res = min(res, b/v0 + c/v1 + c/v2 + b/v2);
    res = min(res, a/v0 + c/v0 + c/v1 + a/v2);
    res = min(res, b/v0 + c/v0 + c/v1 + b/v2);

    res = min(res, a/v0 + a/v1 + b/v0 + b/v1);

    double ares = INF, bres = INF;
    ares = min(ares, a/v0 + a/v1);
    ares = min(ares, a/v0 + c/v1 + b/v1);
    ares = min(ares, b/v0 + c/v0 + a/v1);
    ares = min(ares, b/v0 + c/v0 + c/v1 + b/v1);
    
    bres = min(bres, b/v0 + b/v1);
    bres = min(bres, b/v0 + c/v1 + a/v1);
    bres = min(bres, a/v0 + c/v0 + b/v1);
    bres = min(bres, a/v0 + c/v0 + c/v1 + a/v1);

    res = min(res, ares + bres);
    
    printf("%.15lf", res);
}