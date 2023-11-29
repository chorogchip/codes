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

int N, W, H, X, L;

int main() { FAST
    cin >> N >> W >> H;
    L = W * W + H * H;
    fore (i, N) {
        cin >> X;
        if (X * X <= L) cout << "DA\n";
        else cout << "NE\n";
    }
}
