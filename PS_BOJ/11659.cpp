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

int N, M, D[101010], S[101010], R, A, B;

int main() { FAST
    cin >> N >> M;
    fore (i, N) cin >> D[i]; S[1] = D[0];
    for (int i = 1; i != N; ++i) S[i+1] = S[i] + D[i];
    fore (i, M) {
        cin >> A >> B;
        cout << S[B] - S[A-1] << endl;;
    }
}
