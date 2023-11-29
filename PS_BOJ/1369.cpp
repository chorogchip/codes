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

int N, X;
pair<int,int> D[2][1010][1010];

pair<int,int> asd(int n) {
    pair<int,int> ret = make_pair(0, 0);
    int nn = n;
    while (nn % 2 == 0) ++(ret.first), nn >>= 1;
    nn = n;
    while (nn % 5 == 0) ++(ret.second), nn /= 5;
    return ret;
}

int main() { FAST
    cin >> N;
    fore (i, N) fore (j, N) {
        cin >> X;
        if (X == 0) D[0][i][j].first = -1;
        else D[0][i][j] = D[1][i][j] = asd(X);
    }
    for (int j = 1; j != N; ++j) {
        if (D[0][0][j].first == -1 || D[0][0][j-1].first == -1) {
            D[0][0][j].first = -1;
        } else {
            D[0][0][j].first += D[0][0][j-1].first;
            D[0][0][j].second += D[0][0][j-1].second;
            D[1][0][j].first += D[1][0][j-1].first;
            D[1][0][j].second += D[1][0][j-1].second;
        }
    }
    for (int i = 1; i != N; ++i) {
        if (D[0][i-1][0].first == -1 || D[0][i][0].first == -1) {
            D[0][i][0].first = -1;
        } else {
            D[0][i][0].first += D[0][i-1][0].first;
            D[0][i][0].second += D[0][i-1][0].second;
            D[1][i][0].first += D[1][i-1][0].first;
            D[1][i][0].second += D[1][i-1][0].second;
        }
        for (int j = 1; j != N; ++j) {
            if (D[0][i][j].first == -1) {
                continue;
            } else if (D[0][i-1][j].first == -1 && D[0][i][j-1].first == -1) {
                D[0][i][j].first = -1;
                continue;
            } else if (D[0][i-1][j].first == -1) {
                D[0][i][j].first += D[0][i][j-1].first;
                D[0][i][j].second += D[0][i][j-1].second;
                D[1][i][j].first += D[1][i][j-1].first;
                D[1][i][j].second += D[1][i][j-1].second;
            } else if (D[0][i][j-1].first == -1) {
                D[0][i][j].first += D[0][i-1][j].first;
                D[0][i][j].second += D[0][i-1][j].second;
                D[1][i][j].first += D[1][i-1][j].first;
                D[1][i][j].second += D[1][i-1][j].second;
            } else {
                if (D[0][i-1][j].first < D[0][i][j-1].first) {
                    A2:
                    D[0][i][j].first += D[0][i-1][j].first;
                    D[0][i][j].second += D[0][i-1][j].second;
                } else if (D[0][i-1][j].first > D[0][i][j-1].first) {
                    B2:
                    D[0][i][j].first += D[0][i][j-1].first;
                    D[0][i][j].second += D[0][i][j-1].second;
                } else if (D[0][i-1][j].second < D[0][i][j-1].second) {
                    goto A2;
                } else {
                    goto B2;
                }
                if (D[1][i-1][j].second < D[1][i][j-1].second) {
                    A5:
                    D[1][i][j].first += D[1][i-1][j].first;
                    D[1][i][j].second += D[1][i-1][j].second;
                } else if (D[1][i-1][j].second > D[1][i][j-1].second) {
                    B5:
                    D[1][i][j].first += D[1][i][j-1].first;
                    D[1][i][j].second += D[1][i][j-1].second;
                } else if (D[1][i-1][j].first < D[1][i][j-1].first) {
                    goto A5;
                } else {
                    goto B5;
                }
            }
        }
    }
    cout << min(min(D[0][N-1][N-1].first, D[0][N-1][N-1].second),
                min(D[1][N-1][N-1].first, D[1][N-1][N-1].second)) << endl;
}
