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

typedef long long ll;
ll M = 1LL<<50LL;
int N, D[5010], A, B, C;
pair<int,int> DD[25010101];

int main() { FAST
    cin >> N;
    fore (i, N) cin >> D[i];
    sort(D, D + N);
    for (int i = 0; i != N - 2; ++i) {
        for (int j = i + 1; j != N - 1; ++j) {
            int lo = j + 1, md, hi = N - 1;
            ll x = - D[i] - D[j];
            while (lo < hi) {
                md = lo + hi >> 1;
                if (x > D[md]) lo = md + 1;
                else hi = md;
            }
            if (M > abs(D[lo] - x)) {
                M = abs(D[lo] - x);
                A = D[i];
                B = D[j];
                C = D[lo];
            }
            if (lo - 1 != j && M > abs(D[lo-1] - x)) {
                M = abs(D[lo - 1] - x);
                A = D[i];
                B = D[j];
                C = D[lo - 1];
            }
        }
    }
    cout << A << ' ' << B << ' ' << C;
}
