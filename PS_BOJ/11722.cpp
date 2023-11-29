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

int N, K, X, DD[1010];

int main() { FAST
    cin >> N;
    DD[0] = 2110101010;
    for (int i = 1; i <= N; ++i) {
        cin >> X;
        if (X < DD[K]) DD[++K] = X;
        else {
            int lo = 0, md, hi = K;
            while (lo < hi) {
                md = lo + hi >> 1;
                if (X < DD[md]) lo = md + 1;
                else hi = md;
            }
            if (lo > 0) DD[lo] = X;
        }
    }
    cout << K << endl;
}
