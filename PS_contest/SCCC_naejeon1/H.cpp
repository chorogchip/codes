#include<bits/stdc++.h>
using namespace std;
using ll = long long;

char arr[128][128];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int nn = n >> 1;
    if (n == 2) {
        cout << ".#\n.#\n";
        return 0;
    } else if (n == 3) {
        cout << "...\n##.\n#..";
        return 0;
    }
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        arr[i][j] = '.';
    for (int i = 0; i < n; ++i)
        arr[i][n] = '\n', arr[i][n+1] = 0;

    if (n & 1) {
        for (int i = 0; i < nn; ++i)
            arr[1][i * 2 + 2] = '#';
        for (int i = 0; i < nn + 1; ++i)
            arr[n-1][i * 2] = '#';
    } else {
        for (int i = 0; i < nn; ++i)
            arr[1][i * 2] = '#';
        for (int i = 0; i < nn; ++i)
            arr[n-1][i*2+1] = '#';
    }
    for (int i = 0; i < n; ++i)
        cout << arr[i];

}