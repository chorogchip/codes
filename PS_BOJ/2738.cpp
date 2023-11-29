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

int N, M, X, D[101][101];

int main() { FAST
    cin >> N >> M;
    fore (i, N) fore (j, M) cin >> D[i][j];
    fore (i, N) {
        fore (j, M) {
        cin >> X;
        cout << D[i][j] + X << " ";
        }
        cout << endl;
    }
}
