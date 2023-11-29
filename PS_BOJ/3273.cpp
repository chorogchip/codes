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

int N, M, A[101010], B[101010];

int main() { FAST
    cin >> N;
    for (int i = 0; i != N; ++i) cin >> A[i];
    cin >> M;
    for (int i = 0; i != M; ++i) cin >> B[i];
    sort(A, A + N);
    for (int i = 0; i != M; ++i) {
        int lo = 0, md, hi = N - 1;
        while (lo < hi) {
            md = lo + hi >> 1;
            if (B[i] > A[md]) lo = md + 1;
            else hi = md;
        }
        if (B[i] == A[lo]) cout << "1\n";
        else cout << "0\n";
    }
}
