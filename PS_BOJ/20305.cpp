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

int N, Q, A, B, F[1010101], D[1010101];
constexpr int M = 10*10*10*10*10*10*10*10*10+7;

int main() { FAST
    cin >> N >> Q;
    F[1] = M - 1;
    A = N + 3;
    for (int i = 2; i <= A; ++i) F[i] = (F[i-1] + F[i-2]) % M;
    fore (i, Q) {
        cin >> A >> B;
        D[A] += 1;
        D[A] %= M;
        D[B+1] += F[B-A+2];
        D[B+1] %= M;
        D[B+2] += F[B-A+1];
        D[B+2] %= M;
    }
    cout << D[1];
    for (int i = 2; i <= N; ++i) {
        D[i] += (D[i-1] + D[i-2]) % M;
        D[i] %= M;
        cout << ' ' << D[i];
    }
}
