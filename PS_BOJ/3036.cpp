#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, X, XX;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    scanf("%d%d", &N, &X);
    for (int i = 1; i != N; ++i) {
        scanf("%d", &XX);
        int R = gcd(X, XX);
        printf("%d/%d\n", X/R, XX/R);
    }
}
