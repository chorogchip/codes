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

int T, M, N, X, Y, R;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
int main() { FAST
    cin >> T;
    while (T--) {
        cin >> M >> N >> X >> Y;
        R = lcm(M, N);
        if (M == X && N == Y) { cout << R << endl; continue; }
        if (M == X) X = 0;
        if (N == Y) Y = 0;
        while (X <= R && X % N != Y) X += M;
        if (X <= R) cout << X << endl;
        else cout << -1 << endl;
    }
}
