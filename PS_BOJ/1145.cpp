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

int A[5], R = 2101010101;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int lllcm(int a, int b, int c) {
    return lcm(a, lcm(b, c));
}

int main() { FAST
    cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4];
    R = min(R, lllcm(A[0], A[1], A[2]));
    R = min(R, lllcm(A[0], A[1], A[3]));
    R = min(R, lllcm(A[0], A[1], A[4]));
    R = min(R, lllcm(A[0], A[2], A[3]));
    R = min(R, lllcm(A[0], A[2], A[4]));
    R = min(R, lllcm(A[0], A[3], A[4]));
    R = min(R, lllcm(A[1], A[2], A[3]));
    R = min(R, lllcm(A[1], A[2], A[4]));
    R = min(R, lllcm(A[1], A[3], A[4]));
    R = min(R, lllcm(A[2], A[3], A[4]));
    cout << R << endl;
}
