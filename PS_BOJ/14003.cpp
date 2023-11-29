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

int N, K, A[1010101], D[1010101], Di[1010101], L[1010101], F;
vector<int> v;

int main() { FAST
    cin >> N;
    D[0] = -2101010101;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        if (A[i] > D[K]) F = i, L[i] = Di[K], D[++K] = A[i], Di[K] = i;
        else {
            int lo = 0, md, hi = K;
            while (lo < hi) {
                md = lo + hi >> 1;
                if (A[i] > D[md]) lo = md + 1;
                else hi = md;
            }
            if (lo) L[i] = Di[lo - 1], D[lo] = A[i], Di[lo] = i;
        }
    }
    cout << K << endl;
    do v.push_back(A[F]); while (F = L[F]);
    for (int i = v.size() - 1; i >= 0; --i) cout << v[i] << ' '; cout << endl;
}
