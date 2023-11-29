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

int N, A[101010], B[101010], X;
#include<set>
set<int> s;

void asdf(int lo, int hie, int bk) {
    if (hie - lo == 0) return;
    cout << B[bk] << ' ';
    if (hie - lo == 1) return;
    int i = A[B[bk]];
    asdf(lo, i, bk-(hie-i));
    asdf(i+1, hie, bk-1);
}
int main() { FAST
    cin >> N;
    fore (i, N) {
        cin >> X;
        A[X] = i;
    }
    fore (i, N) cin >> B[i];
    asdf(0, N, N-1);
}
