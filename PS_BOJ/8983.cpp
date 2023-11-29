#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, M, L, S[101010], R;
pair<int,int> A[101010];

int main() { FAST
    cin >> M >> N >> L;
    fore (i, M) cin >> S[i];
    fore (i, N) cin >> A[i].first >> A[i].second;
    sort(S, S + M);
    fore (i, N) {
        if (A[i].second > L) continue;
        int dx = L - A[i].second;
        int lo = A[i].first - dx, hi = A[i].first + dx;
        int* lb = lower_bound(S, S + M, lo);
        if (lb == S + M) continue;
        if (*lb <= hi) ++R;
    }
    cout << R;
}
