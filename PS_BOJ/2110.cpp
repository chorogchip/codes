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

int N, C, X[201010];

int getRemainGongYuGi(int intv) {
    //pos 1 gong-yu-gi at X[0]
    int cnt = C - 1;  // remain gong-yu-gi count
    int lastP = X[0];  // last gong-yu-gi pos
    for (int i = 1; i != N; ++i)
        if (X[i] - lastP >= intv)
            lastP = X[i], --cnt;
    return cnt;
}

int main() { FAST
    cin >> N >> C;
    fore (i, N) cin >> X[i];
    sort(X, X + N);
    int lo = 1, md, hi = X[N-1];
    while (lo < hi) {
        md = lo + hi + 1 >> 1;
        if (getRemainGongYuGi(md) <= 0) lo = md;
        else hi = md - 1;
    }
    cout << lo;
}
