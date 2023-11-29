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

int N, M, lo, md, hi;
pair<string,string> D[101010];
string S;

int main() { FAST
    cin >> N >> M;
    fore (i, N) cin >> D[i].first >> D[i].second;
    sort(D, D + N);
    fore (i, M) {
        cin >> S;
        lo = 0, hi = N-1;
        while (lo < hi) {
            md = lo + hi >> 1;
            if (S > D[md].first) lo = md + 1;
            else hi = md;
        }
        cout << D[lo].second << endl;
    }
}
