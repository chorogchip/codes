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

int N, X, Y, D[20];

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> X >> Y;
        if (i + X - 1 <= N) D[i + X] = max(D[i + X], D[i] + Y);
        D[i + 1] = max(D[i], D[i+1]);
    }
    cout << D[N + 1] << endl;
}
