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

int N, M, D[10], C[10], CC[10];

void choose(int dpt) {
    if (dpt == M) {
        for (int i = 0; i != dpt; ++i) cout << C[i] << ' '; cout << endl;
        return;
    }
    int pk = -1;
    for (int i = 0; i != N; ++i) if (!CC[i] && D[i] != pk) {
        C[dpt] = D[i]; CC[i] = 1; pk = D[i];
        choose(dpt + 1);
        CC[i] = 0;
    }
}

int main() { FAST
    cin >> N >> M;
    fore (i, N) cin >> D[i];
    sort(D, D + N);
    choose(0);
}
