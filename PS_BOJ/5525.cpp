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

int N, M, R, K;
char S[1010101];

int main() { FAST
    cin >> N >> M >> S + 1;
    S[0] = S[1];
    for (int i = 1; i <= M; ++i) {
        if (S[i] == 'I')
            if (S[i-1] == 'O' || !K) ++K;
            else R += max(0, K - N), K = 1;
        else
            if (S[i-1] == 'O') R += max(0, K - N), K = 0;
    }
    R += max(0, K - N);
    cout << R << endl;
}
