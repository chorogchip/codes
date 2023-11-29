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

int N, D[1010][10], R;

int main() {
    cin >> N;
    for (int i = 0; i != 10; ++i) D[1][i] = 1;
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j != 10; ++j)
            for (int k = j; k != 10; ++k)
                (D[i][j] += D[i-1][k]) %= 10007;
    }
    for (int i = 0; i != 10; ++i) (R += D[N][i]) %= 10007;
    cout << R << endl;
}
