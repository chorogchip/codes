#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;

int N, M, X, cnt[20000001];

main() { FAST
    cin >> N;
    fore (i, N) {
        cin >> X;
        ++cnt[X+10000000];
    }
    cin >> M;
    fore (i, M) {
        cin >> X;
        cout << cnt[X+10000000] << " ";
    }
}