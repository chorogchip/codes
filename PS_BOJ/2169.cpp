#include<iostream>
using namespace std;

int N, M, C[1024], D[1024], L[1024], R[1024];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int j = 1; j <= M; ++j) {
        cin >> D[j];
        D[j] += D[j-1];
    }
    if (N == 1) {
        cout << D[M];
        return 0;
    }
    for (int i = 2; i < N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> C[j];
            D[j] += C[j];
        }
        L[1] = D[1];
        R[M] = D[M];
        for (int j = 2; j <= M; ++j)
            L[j] = max(D[j], L[j-1]+C[j]);
        D[M] = max(L[M], R[M]);
        for (int j = M - 1; j; --j)
            R[j] = max(D[j], R[j+1]+C[j]),
            D[j] = max(L[j], R[j]);
    }
    cin >> C[1];
    D[1] += C[1];
    for (int j = 2; j <= M; ++j) {
        cin >> C[j];
        D[j] = max(D[j], D[j-1]);
        D[j] += C[j];
    }
    cout << D[M];
}