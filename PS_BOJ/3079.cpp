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

typedef long long ll;
ll N, M, T[101010];

inline bool canDoEvaluationOnTime(ll time) {
    ll people_evaluated = 0LL;
    for (int i = 0; i != N; ++i) {
        people_evaluated += time / T[i];
        if (people_evaluated >= M) return true;
    }
    return people_evaluated >= M;
}

int main() { FAST
    cin >> N >> M;
    fore (i, N) cin >> T[i];
    ll lo = 1LL, md, hi = 1000LL*1000LL*1000LL * M;
    while (lo < hi) {
        md = lo + hi >> 1LL;
        if (canDoEvaluationOnTime(md)) hi = md;
        else lo = md + 1LL;
    }
    cout << lo;
}
