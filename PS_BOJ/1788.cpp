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

int D[1010101];
constexpr int M = 1000000000;

int Fib(int n) {
    if (D[n]) return D[n];
    else if (n <= 1) return n;
    else return D[n] = (Fib(n-1) + Fib(n-2)) % M;
}

int main() { FAST
    int N;
    cin >> N;
    D[1] = 1;
    if (N > 0) cout << 1 << endl << Fib(N);
    else if (N == 0) cout << 0 << endl << 0;
    else cout << (N & 1 ? 1 : -1) << endl << Fib(-N);
}
