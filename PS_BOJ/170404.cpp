#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define fore(i, n) for (int i = 0; i != (n); ++i)
#define for1(i, n) for (int i = 1; i <= (n); ++i)
#define FAST cin.sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
constexpr int INF = 1000*1000*1000;

int N, W[1010][3], D[1010][3], R = INF;

int main() { FAST
    cin >> N;
    for1 (i, N) cin >> W[i][0] >> W[i][1] >> W[i][2];
    for (int i = 0; i != 3; ++i) {
        D[1][0] = D[1][1] = D[1][2] = INF;
        D[1][i] = W[1][i];
        for (int j = 2; j != N; ++j) {
            D[j][0] = min(D[j-1][1], D[j-1][2]) + W[j][0];
            D[j][1] = min(D[j-1][2], D[j-1][0]) + W[j][1];
            D[j][2] = min(D[j-1][0], D[j-1][1]) + W[j][2];
        }
        D[N][(i+1)%3] = min(D[N-1][i], D[N-1][(i+2)%3]) + W[N][(i+1)%3];
        D[N][(i+2)%3] = min(D[N-1][i], D[N-1][(i+1)%3]) + W[N][(i+2)%3];
        R = min(R, min(D[N][(i+1)%3], D[N][(i+2)%3]));
    }
    cout << R;
}
