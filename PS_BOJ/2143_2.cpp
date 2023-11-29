#include<iostream>
#include<algorithm>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

typedef long long ll;
int N, m, A[1010], B[1010], T, C[1010101];
ll R;
int main() { FAST
    cin >> T >> N;
    for1 (i, N) cin >> A[i];
    cin >> m;
    for1 (i, m) cin >> B[i];
    int k = 0;
    for (int i = 1; i <= N; ++i) {
        A[i] += A[i-1];
        for (int j = 0; j < i; ++j)
            C[k++] = A[i] - A[j];
    }
    sort(C, C + k);

    for (int i = 1; i <= m; ++i) {
        B[i] += B[i-1];
        for (int j = 0; j < i; ++j) {
            int x = T - B[i] + B[j];
            int *lo = lower_bound(C, C + k, x);
            if (x != *lo) continue;
            int *hi = upper_bound(C, C + k, x);
            R += hi - lo;
        }lower_bound
    }
    cout << R;
}