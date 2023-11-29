#include<iostream>
#include<climits>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

typedef long long ll;
int K, N, D[10101];

inline bool isLengthProper(int length) {
    int count = 0;
    for (int i = 0; i != K; ++i) {
        count += D[i] / length;
    }
    return count >= N;
}

int main() { FAST
    cin >> K >> N;
    fore (i, K) cin >> D[i];
    ll lo = 1, md, hi = INT_MAX;
    while (lo < hi) {
        md = lo + hi + 1 >> 1;
        if (isLengthProper(md)) lo = md;
        else hi = md - 1;
    }
    cout << lo;
}
